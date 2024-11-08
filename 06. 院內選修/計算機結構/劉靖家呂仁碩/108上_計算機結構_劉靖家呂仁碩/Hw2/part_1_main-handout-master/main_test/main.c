#include <stdio.h>
#include "util.h"
void lfsr64();
uint64_t lfsr_gold(uint64_t status, uint64_t feedback_f);
// you can modify values below
uint64_t seed = 17;
uint64_t feedback = 0x800000000000000D;

int main() {
	int i;
	uint64_t seed_g=seed, feedback_g=feedback;
	
	printf("your answer\n");
  	for(i=0; i<5; i++){				// print your answer
		lfsr64();
		printf("%ld\n",seed);
	}
	seed = seed_g;
	feedback = feedback_g;
	printf("golden answer\n");
  	for(i=0; i<5; i++){				// print the golden answer
		seed = lfsr_gold(seed, feedback);
		printf("%ld\n",seed);
	}
	return 0;
}

uint64_t lfsr_gold(uint64_t status, uint64_t feedback_f){
    uint64_t lfsr=status;
    lfsr = (lfsr & 1) ? (lfsr >> 1) ^ feedback_f : (lfsr >> 1); //cycle one step of LFSR
    return lfsr;

}