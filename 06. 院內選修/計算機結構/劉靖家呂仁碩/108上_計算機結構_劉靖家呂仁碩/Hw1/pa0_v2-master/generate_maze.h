#ifndef GENERATE_MAZE_H
#define GENERATE_MAZE_H
#include "lfsr.h"
#include <stdio.h>


//************you can declare any other function you need
void generate_maze(uint64_t* maze, int h, int w, int i_i, int i_j, uint64_t* seed);
int available_dir(uint64_t* maze, int i_i, int i_j);
int random_dir(uint64_t* seed, int range);
int choose_dir(uint64_t* maze, int i_i, int i_j, int r);
//void bit_ctrl_0 (uint64_t* pflag, int bit);
//void bit_ctrl_1 (uint64_t* pflag, int bit);

//******************************

#endif
