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

//�y�Ц�m���c��
typedef struct local{
	
	int x;
	int y;

}LOCAL;

//�̵��c
typedef struct stack{
	
	LOCAL data[100];
	int top;

}STACK;
//��l�ƴ�
STACK *InitStack(void)
{
	STACK maze[1200];
	//maze = (STACK *)malloc(sizeof(STACK));
	maze->top = -1;
	
	return maze;
}

//�P�̪�
int EmptyStack(STACK *maze)
{
	if (maze->top == -1)
		return 1;
	else
		return 0;
}


//�J��
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


//�X��
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
