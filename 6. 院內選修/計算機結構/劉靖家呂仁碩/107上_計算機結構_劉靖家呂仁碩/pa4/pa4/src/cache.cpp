#include "cache.hpp"

Cache::Cache(){
    // reset cache 
    for(auto i : _cache){
        i.reset();
    }
    _bit_block    = 0;
    _bit_line     = 0;
    _bit_set      = 0;
    _bit_tag      = 0;
    _current_block = 0;
    _current_set  = 0;
    for(int i=0 ;i<MAX_LINE;i++){
        _LRU_priority[i] = 0;
    }
    _LRUMAX = 0;
}

Cache::~Cache() = default;

void Cache::read_config(char* config_file){
    ifstream conf;

    conf.open(config_file, ios::in);
    while(conf.fail()){
        cerr<<"Open config file error"<<endl;
        std::exit(-1);
    }

    // Get cache size
    ulint size = 0;
    conf>>size;
    if(size<1 || size>= 262144 || (size&(~size+1)) != size){
        cerr<<"Invalid Cache Size"<<endl;
        std::exit(-1);
    }
    _cache_setting.cache_size = size;
    
    // Get cache line size
    size = 0;
    conf>>size;
    if(size<1 || size>= 262144 || (size&(~size+1)) != size){
        cerr<<"Invalid Cache Block Size"<<endl;
        std::exit(-1);
    }
    _cache_setting.block_size = size;
    
    // Get cache mapping policy
    int mapping = -1;
    conf>>mapping;
    switch(mapping){
        case 1:
            _cache_setting.associativity = direct_mapped;
            break;
        case 2:
            _cache_setting.associativity = set_associative;
            break;
        case 3:
            _cache_setting.associativity = full_associative;
            break;
        default:
            cerr<<"Invalid Associativity Config"<<endl;
            std::exit(-1);
    } 

    switch(_cache_setting.associativity){
        // Note: replacement policy is not applicable 
        //       on a direct mapped cache 
        case direct_mapped:
            _cache_setting.replacement_policy = NONE;
            return;
            break;
        case full_associative:
            goto GET_REPL;
            break;
        case set_associative:
            goto GET_SET;
            break;
        default:
            cerr<<"Wrong Mapping Policy Config"<<endl;
            std::exit(-1);
    }

    GET_SET:{
        ulint size = 0;
        conf>>size;
        if(size<1 || size>= 262144 || (size&(~size+1))!=size){
            cerr<<"Invalid Cache Set Config"<<endl;
            std::exit(-1);
        }
        _cache_setting.cache_sets = size;
    }

    GET_REPL:{
        int repl = 0;
        conf>>repl;
        switch(repl){
            case 1: 
                _cache_setting.replacement_policy = RANDOM;
                break;
            case 2: 
                _cache_setting.replacement_policy = LRU;
                break;
            default:
                cerr<<"Invalid Replacement Policy"<<endl;
                std::exit(-1);
        }
    }
    conf.close();
}

void Cache::cache_setup(){
    assert(_cache_setting.block_size > 0);
    _cache_setting.num_block = (_cache_setting.cache_size<<10) / _cache_setting.block_size;
    ulint temp = _cache_setting.block_size;
    while(temp != 0u){
        temp >>= 1;
        _bit_block++;
    }
    --_bit_block;
    // Setup bit line and bit set
    switch(_cache_setting.associativity){
        case direct_mapped:
            temp = _cache_setting.num_block;
            while(temp != 0u){
                temp >>= 1;
                _bit_line++;
            }
            --_bit_line;
            _bit_set = 0;
            break;
        case full_associative:
            _bit_line = 0;
            _bit_set  = 0;
            break;
        case set_associative:
            _bit_line = 0;
            assert(_cache_setting.cache_sets != 0);
            assert(_cache_setting.num_block > _cache_setting.cache_sets);
            _cache_setting.num_sets = _cache_setting.num_block / _cache_setting.cache_sets;
            temp = _cache_setting.num_sets;
            while(temp != 0u){
                temp >>=1;
                _bit_set++;
            }
            --_bit_set;
            break;
        default:
            cerr<<"Invlid mapping policy"<<endl;
            exit(-1);
    }
    _bit_tag = 32ul - _bit_block - _bit_line - _bit_set;
    assert(_bit_tag <= 29);
    int set_count = 0;
    for(ulint i = 0; i < _cache_setting.num_block; ++i){
        _cache[i][31] = true;
        ++set_count;
    }
}

void Cache::run_sim(char* trace_file){
    ifstream in_file;
    char trace_line[13];

    in_file.open(trace_file, ios::in);
    while(in_file.fail()){
        cerr<<"Open trace file error"<<endl;
        exit(-1);
    }

    while(!in_file.eof()){
        in_file.getline(trace_line, 13);
        bool __attribute__((unused)) is_success = _CacheHandler(trace_line);
        assert(is_success);
    }
    in_file.close();
    _CalHitRate();
}

void Cache::dump_result(char* trace_file){

    cout<<"Test file: "<<trace_file<<endl;
    cout<<"Cache size: "<<_cache_setting.cache_size<<"KB"<<endl;
    cout<<"Cache block size: "<<_cache_setting.block_size<<"B"<<endl;
    switch(_cache_setting.associativity){
        case direct_mapped:
            cout<<"Associativity: direct_mapped"<<endl;
        break;
        case set_associative:
            cout<<"Associativity: "<<_cache_setting.cache_sets<< "-way set_associative"<<endl;
        break;
        case full_associative:
            cout<<"Associativity: fully_associative"<<endl;
        break;
        default:
            cerr<<"Error associtivity setting"<<endl;
            exit(-1);
    }
    switch(_cache_setting.replacement_policy){
        case NONE:
            cout<<"Replacement policy: None"<<endl;
        break;
        case RANDOM:
            cout<<"Replacement policy: Random"<<endl;
        break;
        case LRU:
            cout<<"Replacement policy: LRU"<<endl;
        break;
        default:
            cerr<<"Error replacement setting"<<endl;
            exit(-1);
    }
    cout<<"\n";
    cout<<"Number of cache access: "<<_counter.access<<endl;
    cout<<"Number of cache load: "  <<_counter.load<<endl;
    cout<<"Number of cache store: " <<_counter.store<<endl;
    cout<<"Cache hit rate: "         <<_counter.avg_hit_rate<<endl;
}

bool Cache::_CacheHandler(char* trace_line){
    bool is_load  = false;
    bool is_store = false;
    bool is_space = false;
    bool hit      = false;
    ulint temp = 0;

    switch(trace_line[0]){
        case 'l':
            is_load = true;
        break;
        case 's':
            is_store = true;
        break;
        case '\0':
            is_space = true;
        break;
        default:
            cerr<<"Undefined instruction type."<<endl;
            cerr<<"Error line: "<<trace_line<<endl;
            return false;
    }
    temp = strtoul(trace_line+2, nullptr, 16);
    bitset<32> addr(temp);
    hit = _IsHit(addr);

    if(hit && is_load){
        ++_counter.access;
        ++_counter.load;
        ++_counter.load_hit;
        ++_counter.hit;
    }
    else if(hit && is_store){
        ++_counter.access;
        ++_counter.store;
        ++_counter.store_hit;
        ++_counter.hit;
        // If write back, set dirty bit
        if(_cache_setting.write_policy == write_back){
            _cache[_current_block][29] = true;
        }
    }
    else if((!hit) && is_load){
        ++_counter.access;
        ++_counter.load;
        _Read(addr);
    }
    else if((!hit) && is_store){
        ++_counter.access;
        ++_counter.store;
        _Read(addr);
        if(_cache_setting.write_policy == write_back){
            _cache[_current_block][29] = true; // set dirty bit
        }
    }
    else if(is_space){
        ++_counter.space;
    }
    else{
        cerr<<"Unexpected error in _CacheHandler()"<<endl;
        cerr<<"ERROR line: "<<trace_line<<endl;
        return false;
    }
    return true;
}

bool Cache::_IsHit(bitset<32> addr){
    bool ret = false;

    if(_cache_setting.associativity == direct_mapped){
        _current_block = _GetCacheIndex(addr);
        assert(_cache[_current_block][31] == true);
        if(_cache[_current_block][30]){
            ret = _CheckIdent(_cache[_current_block], addr);
        }
    }
    else if(_cache_setting.associativity == full_associative){
        for(ulint i = 0; i < _cache_setting.num_block; ++i){
            if(_cache[i][30]){
                ret = _CheckIdent(_cache[i], addr);
            }
            if(ret){
                _current_block = i;
                _LRU_priority[_current_block] = _LRUMAX+1;
				_LRUMAX++;
                break;
            }
        }
    }
    else{ // Set associative
        _current_set = _GetCacheIndex(addr);
        for(ulint i = _cache_setting.cache_sets * _current_set; i < ((_current_set + 1)* _cache_setting.cache_sets); ++i){
            if(_cache[i][30]){
                ret = _CheckIdent(_cache[i], addr);
            }
            if(ret){
                _current_block = i;
				_LRU_priority[_current_block] = _LRUMAX+1;
				_LRUMAX++;
                break;
            }
        }
    }

    return ret;
}

void Cache::_Read(const bitset<32>& addr){
    bool space = false;
    switch(_cache_setting.associativity){
        case direct_mapped:
            if(!_cache[_current_block][30]){
                _WriteToBlock(addr);
            }
            else{
                _Replace(addr);
            }
        break;
        case full_associative:
            space = false;
            // Find available block
            for(uint i = 0; i < _cache_setting.num_block; ++i){
                if(!_cache[i][30]){
                    space = true;
                    _current_block = i;
                    break;
                }
            }
            if(space){
                _WriteToBlock(addr);
                if(_cache_setting.replacement_policy == LRU){
                    // need extra LRU hit handler
                    _LRU_priority[_current_block] = _LRUMAX+1;
					_LRUMAX++;
                }
            }
            else{
                _Replace(addr);
            }
        break;
        case set_associative:
            space = false;
            for(ulint i = (_current_set * _cache_setting.cache_sets); i <((_current_set+1)) * _cache_setting.cache_sets; i++){
                if(!_cache[i][30]){
                    space = true;
                    _current_block = i;
                    break;
                }
            }
            if(space){
                _WriteToBlock(addr);
                if(_cache_setting.replacement_policy == LRU){
                    // need extra LRU hit handler
					_LRU_priority[_current_block] = _LRUMAX+1;
					_LRUMAX++;
                }
            }
            else{
                _Replace(addr);
            }
        break;
    }
}

void Cache::_Replace(const bitset<32>& addr){
    // Find victim block
    switch(_cache_setting.associativity){
        case direct_mapped: // nothing to do 
        break;
        case full_associative:
            if(_cache_setting.replacement_policy == RANDOM){
                std::random_device rd;
                std::mt19937_64 generator( rd() );
                std::uniform_int_distribution<int> unif(0, INT32_MAX);
                _current_block = static_cast<ulint>(unif(generator) / (INT32_MAX / _cache_setting.num_block+1));
            }
            else if(_cache_setting.replacement_policy == LRU){
                // Do sth.
				uint LRU_value = _LRU_priority[0];
				_current_block = 0;
					for(int i=0 ;i<_cache_setting.num_block ;++i){
						if(LRU_value > _LRU_priority[i]){
							_current_block = i;
							LRU_value = _LRU_priority[i];
						}
					}
				_LRU_priority[_current_block] = _LRUMAX+1;
				_LRUMAX++;
            }
        break;
        case set_associative:
            if(_cache_setting.replacement_policy == RANDOM){
                std::random_device rd;
                std::mt19937_64 generator( rd() );
                std::uniform_int_distribution<int> unif(0, INT32_MAX);
                ulint temp = static_cast<ulint>(unif(generator) / (INT32_MAX / _cache_setting.cache_sets+1));
                _current_block = _current_set * _cache_setting.cache_sets + temp;
            }
            else if(_cache_setting.replacement_policy == LRU){
                // Do sth.
				uint set_begin = _current_set*_cache_setting.cache_sets;
				uint set_end = (_current_set+1)*_cache_setting.cache_sets;
				uint LRU_value = _LRU_priority[set_begin];
				_current_block = set_begin;
				for(uint i=set_begin ; i<set_end ; i++){
					if(LRU_value > _LRU_priority[i]){
						_current_block = i;
						LRU_value = _LRU_priority[i];
					}
				}
				_LRU_priority[_current_block] = _LRUMAX+1;
				_LRUMAX++;
            }
        break;
    }
    // If the victim block is dirty, write back to RAM
    if(_cache[_current_block][29]){
        _Drop();
    }
    // Write new data from RAM to Cache 
    _WriteToBlock(addr);
}

void Cache::_Drop(){
    // Set dirty bit and hit bit to flase
    _cache[_current_block][29] = false;
    _cache[_current_block][30] = false;
}

void  Cache::_WriteToBlock(const bitset<32>& addr){
    for(uint i = 31, j = 28; i > (31ul-_bit_tag); --i, --j){
        _cache[_current_block][j] =  addr[i];
        assert(j > 0);
    }
    _cache[_current_block][30] = true;
}

ulint Cache::_GetCacheIndex(const bitset<32>& addr){
    bitset<32> temp_cache_line;
    temp_cache_line.reset();
    if(_cache_setting.associativity == set_associative){
        for(ulint i = (_bit_block), j = 0; i < (_bit_block+_bit_set); ++i, ++j){
            temp_cache_line[j] = addr[i];
        }
    }
    else{
        for(ulint i = (_bit_block), j = 0; i < (_bit_block+_bit_line); ++i, ++j){
            temp_cache_line[j] = addr[i];
        }
    }
    return temp_cache_line.to_ulong();
}

bool Cache::_CheckIdent(const bitset<32>& cache, const bitset<32>& addr){
    for(uint i = 31, j = 28; i > (31ul-_bit_tag); --i, --j){
        if(addr[i] != cache[j]){
            return false;
        }
    }
    return true;
}

void Cache::_CalHitRate(){
    assert(_counter.access != 0);
    assert(_counter.load   != 0);
    assert(_counter.store  != 0);
    _counter.avg_hit_rate   = static_cast<double>(_counter.hit) / _counter.access;
    _counter.load_hit_rate  = static_cast<double>(_counter.load_hit) / _counter.load;
    _counter.store_hit_rate = static_cast<double>(_counter.store_hit) / _counter.store; 
}
