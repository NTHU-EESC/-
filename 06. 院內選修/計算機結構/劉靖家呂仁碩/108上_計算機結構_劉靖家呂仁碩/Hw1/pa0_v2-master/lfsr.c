#include "lfsr.h"

#ifndef UINT64_MAX
#define UINT64_MAX ((uint64_t) -1)
#endif

uint64_t lfsr64(uint64_t status, uint64_t feedback){
    uint64_t lfsr=status;
    lfsr = (lfsr & 1) ? (lfsr >> 1) ^ feedback : (lfsr >> 1); //cycle one step of LFSR
    return lfsr;

}

uint64_t random_lfsr(uint64_t value, uint64_t range){
    return (uint64_t)((double)(value)/(double)(UINT64_MAX)*range);
}
