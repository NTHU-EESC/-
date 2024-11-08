#ifndef _CACHE_HPP_
#define _CACHE_HPP_

#include <bitset>
#include <cassert>
#include <fstream>
#include <iostream>
#include <random>
#include <string>

using namespace std;

const int MAX_LINE = 65536;

using uint = unsigned int;
using ulint = uint64_t;

enum MAPPING_P{
    // Cache block mapping policies
    direct_mapped,
    set_associative,
    full_associative
};

enum REPL_P{
    // Cache replacement policies
    NONE,
    RANDOM,
    LRU
};

enum WRITE_P{
    // Cache write policies
    write_back
};

struct CACHE_SET{
    MAPPING_P associativity;
    REPL_P    replacement_policy;
    WRITE_P   write_policy;
    ulint     cache_size;          // cache size
    ulint     block_size;          // cache block size
    ulint     cache_sets;          // cache set
    ulint     num_block;           // # of lines
    ulint     num_sets;            // # of sets
    CACHE_SET(){
        associativity      = direct_mapped;
        replacement_policy = NONE;
        write_policy       = write_back;
        cache_size         = 0;
        block_size         = 0;
        cache_sets         = 0;
        num_block          = 0;
        num_sets           = 0;
    }
};

struct COUNTER{
    ulint access;          // # of cache access
    ulint load;            // # of load inst.
    ulint store;           // # of store inst.
    ulint space;           // # of space line
    ulint hit;             // # of hit
    ulint load_hit;        // # of load hit 
    ulint store_hit;       // # of store hit
    double avg_hit_rate;   // average hit rate
    double load_hit_rate;  // hit rate of loads
    double store_hit_rate; // hit rarte of stores
    COUNTER(){
        access          = 0;
        load            = 0;
        store           = 0;
        space           = 0;
        hit             = 0;
        load_hit        = 0;
        store_hit       = 0;
        avg_hit_rate    = 0.0;
        load_hit_rate   = 0.0;
        store_hit_rate  = 0.0;
    }
};

class Cache{
public:
    Cache();
    ~Cache();
    void read_config(char* config_file);// Read cache configurations
    void run_sim(char* trace_file);     // Load trace file and run simulation
    void cache_setup();                 // Setup cache
    void dump_result(char* trace_file); // print simulation result
private:
    
    // Main handling Functions
    bool _CacheHandler(char* trace_line);  // Main Instruction processing
    bool _IsHit(bitset<32> addr);          // Data is hit/miss
    void _Read(const bitset<32>& addr);    // Read data from memory
    void _Drop();                          // Write data to memory
    void _Replace(const bitset<32>& addr); // No available block, replace cache block

    // Utility functions
    void  _WriteToBlock(const bitset<32>& addr);  // Write data to cache block
    ulint _GetCacheIndex(const bitset<32>& addr); // Get index of block
    bool  _CheckIdent(const bitset<32>& cache, const bitset<32>& addr);
    // Check whether current address is in certain cache block 
    void _CalHitRate();                           // Caculate hit rate

    // Variables
    CACHE_SET   _cache_setting;    // Basic configurations
    COUNTER     _counter;          // Runtime statistics
    bitset<32>  _cache[MAX_LINE];  // Cache status
    // [31]: valid bit [30]: hit [29]: dirty bit [28]~[0]: data
    uint        _LRU_priority[MAX_LINE];// Priority table for LRU
    ulint       _current_block;     // The block being processed
    ulint       _current_set;      // The set being processed
    uint        _bit_block;        // # of bits of a block
    uint        _bit_line;         // # of bits of a line
    uint        _bit_tag;          // # of bits of a tag
    uint        _bit_set;          // # of bits of a set
    uint        _LRUMAX;
};

#endif
