#include <unistd.h>
#include <stdio.h>
#include "util.h"
#include"generate_maze.h"
#include "config.h" 

const uint64_t FEEDBACK_golden=0x800000000000000D;
void initial_maze(uint64_t* maze, int rowCount, int colCount);
void print_maze(uint64_t* maze, int rowCount, int colCount);

int main() {
    int h, w, rowCount, colCount, i_i, i_j, i;
    uint64_t seed;

    seed = 17;
  h = H_n;
  w = W_n;
  i_i = I_I;
  i_j = I_J;

	rowCount = 2*h+1+2;
	colCount = 2*w+1+2;

	uint64_t maze[rowCount];

	initial_maze(maze,rowCount, colCount);
	setStats(1);
	generate_maze(maze, h, w, i_i, i_j, &seed);
	setStats(0);
	printf("Your maze\n");
	print_maze(maze,rowCount, colCount);
    /*for (i = 0; i < rowCount; i++) {
        printf("%lu\n", maze[i]);
    }*/

	seed = 17;
	printf("\nCorrect maze\n");
	initial_maze(maze,rowCount, colCount);
	generate_maze_golden(maze, h, w, i_i, i_j, &seed);
	print_maze(maze,rowCount, colCount);
    /*for (i = 0; i < rowCount; i++) {
        printf("%lu\n", maze[i]);
    }*/
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

void generate_maze_golden(uint64_t* maze, int h, int w, int i_i, int i_j, uint64_t* seed) {
// "h" is the number of cell in one column, "w" is the number of cell in one row
//"i_i","i_j" is the index of the initial position, where this maze should start.
//***************************your code write here********

    uint64_t j = 0x0000000000000001;
    int dir;
    int range, r;

    j = j << i_j;
    maze[i_i] &= ~j;

    do {
		range = available_dir_golden(maze, i_i, i_j);
		if (range == -1)
			return;
        r = random_dir_golden(seed, range);
		dir = choose_dir_golden(maze, i_i, i_j, r);
        switch(dir) {
            case 2:
                j = j >> 1;
                maze[i_i] &= ~j;
                j = j << 1;
                generate_maze_golden(maze, h, w, i_i, i_j-2, seed);

                break;
            case 1:
                maze[i_i + 1] &= ~j;
                generate_maze_golden(maze, h, w, i_i+2, i_j, seed);

                break;
            case 0:
                j = j << 1;
                maze[i_i] &= ~j;
                j = j >> 1;
                generate_maze_golden(maze, h, w, i_i, i_j+2, seed);

                break;
            case 3:
                maze[i_i - 1] &= ~j;
                generate_maze_golden(maze, h, w, i_i-2, i_j, seed);

                break;
            case -1:
                return;
        }

    }while (1);

    return;
}
//************you can define your function here

int available_dir_golden(uint64_t* maze, int i_i, int i_j) {
// this function will output number of available direction at current position
// "i_i","i_j" is the index of the current position
// if there is no available direction, it returns -1.
	uint64_t j = 0x0000000000000001;
    int num;
    int i;

	j = j << i_j;

	num = 0;
    //left
    if ((maze[i_i] & (j << 2)) != 0)
        num++;
    // down
    if ((maze[i_i+2] & (j)) != 0)
        num++;
    // right
    if ((maze[i_i] & (j >> 2)) != 0)
        num++;
    // up
    if ((maze[i_i-2] & (j)) != 0)
        num++;   
	if(num==0)
		return -1;
    return num;
}

int random_dir_golden(uint64_t* seed, int range) {
// this function picks one number randomly from 0 to range-1
// "seed" is used by lfsr function, when you use this function in generate_maze() you do not need to modified "seed", like following example.
	int n;

    *seed = lfsr64_golden(*seed, FEEDBACK_golden); 	
    n = random_lfsr_golden(*seed, range);
    return n;
}

int choose_dir_golden(uint64_t* maze, int i_i, int i_j, int r) {
// this function will output an available direction at current position
// "i_i","i_j" is the index of the current position
// output 0 means left, 1 means down, 2 means right, 3 means up
    uint64_t j = 0x0000000000000001;
    int ava_dir[4];
    int num = 0;
    int i;

    j = j << i_j;
    //left
    if ((maze[i_i] & (j << 2)) != 0)
        ava_dir[num++] = 0;
    // down
    if ((maze[i_i+2] & (j)) != 0)
        ava_dir[num++] = 1;
    // right
    if ((maze[i_i] & (j >> 2)) != 0)
        ava_dir[num++] = 2;
    // up
    if ((maze[i_i-2] & (j)) != 0)
        ava_dir[num++] = 3;

    return ava_dir[r];
}

uint64_t lfsr64_golden(uint64_t status, uint64_t feedback){
    uint64_t lfsr=status;
    lfsr = (lfsr & 1) ? (lfsr >> 1) ^ feedback : (lfsr >> 1); //cycle one step of LFSR
    return lfsr;

}

uint64_t random_lfsr_golden(uint64_t value, uint64_t range){
	return value%range;
}








