#ifndef GENERATE_MAZE_H
#define GENERATE_MAZE_H
#include "lfsr.h"
#include <stdio.h>
#define MAXSIZE 1000


//************you can declare any other function you need
void generate_maze(uint64_t* maze, int h, int w, int i_i, int i_j, uint64_t* seed);
int available_dir(uint64_t* maze, int i_i, int i_j);
int random_dir(uint64_t* seed, int range);
int choose_dir(uint64_t* maze, int i_i, int i_j, int r);
void bit_ctrl_0 (uint64_t* pflag, int bit);
void bit_ctrl_1 (uint64_t* pflag, int bit);

//座標位置結構體
typedef struct local{
	
	int x;
	int y;

}LOCAL;

//棧結構
typedef struct stack{
	
	LOCAL data[MAXSIZE];
	int top;

}STACK;
int EmptyStack(STACK *maze);
int PushStack(STACK *maze, LOCAL *x);
STACK *InitStack(void);
int EmptyStack(STACK *maze);
int PushStack(STACK *maze, LOCAL *x);
int PopStack(STACK *maze, LOCAL *x);
//******************************

#endif
