#include <unistd.h>
#include <stdio.h>
#include "lfsr.h"
#include "generate_maze.h"


void initial_maze(uint64_t* maze, int rowCount, int colCount);
void print_maze(uint64_t* maze, int rowCount, int colCount);

int main() {
    int h, w, rowCount, colCount, i_i, i_j;
    uint64_t seed;

    seed = 17;
    scanf("%d",&h);
    scanf("%d",&w);
    scanf("%d",&i_i);
    scanf("%d",&i_j);

	rowCount = 2*h+1+2;
	colCount = 2*w+1+2;

	uint64_t maze[rowCount];

	initial_maze(maze,rowCount, colCount);
	generate_maze(maze, h, w, i_i, i_j, &seed);
    print_maze(maze,rowCount, colCount);


    return 0;
}


void initial_maze(uint64_t* maze, int rowCount, int colCount) {
    uint64_t tmp = 0x0000000000000001;

    int i = 0, j = 0;
    for (i = 0; i < rowCount; i++) {
        maze[i] = 0;
    }

    for (i = 0; i < rowCount; i++) {
        if (i != 0 && i != rowCount-1) {
            for (j = 1; j < colCount-1; j++) {
                maze[i] |= (tmp<<j);
            }
        }
    }

    return;
}

void print_maze(uint64_t* maze, int rowCount, int colCount) {
    uint64_t flag = 0;
    int i = 0, j = 0;
    uint64_t tmp = 0x0000000000000001;
    //bit_ctrl_0(&maze[1], 1);
    for (i = 0; i < rowCount; i++) {
        for (j = 0; j < colCount; j++) {
                flag = maze[i] & (tmp<<j);
                if (flag != 0)
                    printf("1 ");
                else
                    printf("0 ");
        }
        printf("\n");
    }


    return;
}
