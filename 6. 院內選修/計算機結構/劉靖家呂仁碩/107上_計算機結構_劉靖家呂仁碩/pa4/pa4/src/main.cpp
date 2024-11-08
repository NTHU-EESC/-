#include "cache.hpp"

int main(int argc, char* argv[]){
    assert(argc >= 3);

    Cache cache;
    cache.read_config(argv[2]);
    cache.cache_setup(); 
    cache.run_sim(argv[1]);
    cache.dump_result(argv[1]);

    return 0;
}