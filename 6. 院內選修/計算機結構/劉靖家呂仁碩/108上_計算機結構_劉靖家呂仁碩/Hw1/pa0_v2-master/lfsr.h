#ifndef LFSR_H
#define LFSR_H


/*
 * Generate random numbers in a range from lfsr64
 */

#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// Stahnke's primitive 64-bit tap positions as used by the inner loop from
// http://users.ece.cmu.edu/~koopman/lfsr/index.html

uint64_t random_lfsr(uint64_t value, uint64_t range);
uint64_t lfsr64(uint64_t status, uint64_t feedback);


#endif
