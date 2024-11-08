#ifndef GENERATE_MAZE_H
#define GENERATE_MAZE_H
#include <stdio.h>
#define MAXSIZE 1000 



//************you can declare any other function you need
void generate_maze(uint64_t* maze, int h, int w, int i_i, int i_j, uint64_t* seed);
int available_dir(uint64_t* maze, int i_i, int i_j);
int random_dir(uint64_t* seed, int range);
int choose_dir(uint64_t* maze, int i_i, int i_j, int r);
uint64_t random_lfsr(uint64_t value, uint64_t range);
uint64_t lfsr64(uint64_t status, uint64_t feedback);
void generate_maze_golden(uint64_t* maze, int h, int w, int i_i, int i_j, uint64_t* seed);
int available_dir_golden(uint64_t* maze, int i_i, int i_j);
int random_dir_golden(uint64_t* seed, int range);
int choose_dir_golden(uint64_t* maze, int i_i, int i_j, int r);
uint64_t random_lfsr_golden(uint64_t value, uint64_t range);
uint64_t lfsr64_golden(uint64_t status, uint64_t feedback);
//******************************

#endif
