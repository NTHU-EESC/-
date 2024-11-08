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

void bit_ctrl_0 (uint64_t* maze, int bit) {
	uint64_t tmp = 0x0000000000000001;
	*maze &= ~(tmp << bit);
}
void bit_ctrl_1 (uint64_t* maze, int bit) {
	uint64_t tmp = 0x0000000000000001;
	*maze |= (tmp << bit);
}

//座標位置結構體
typedef struct local{
	
	int x;
	int y;

}LOCAL;

//棧結構
typedef struct stack{
	
	LOCAL data[100];
	int top;

}STACK;
//初始化棧
STACK *InitStack(void)
{
	STACK maze[1200];
	//maze = (STACK *)malloc(sizeof(STACK));
	maze->top = -1;
	
	return maze;
}

//判棧空
int EmptyStack(STACK *maze)
{
	if (maze->top == -1)
		return 1;
	else
		return 0;
}


//入棧
int PushStack(STACK *maze, LOCAL *x)
{
	if (maze->top <= MAXSIZE - 1){
		maze->data[++maze->top] = *x;
		return 1;
	}
	else{
		return 0;
	}
}


//出棧
int PopStack(STACK *maze, LOCAL *x)
{
	if (maze->top > -1){
		*x = maze->data[maze->top];
		maze->top--;
		return 1;
	}
	else{
		return 0;
	}
}





//******************************

#endif
