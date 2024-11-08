#include "generate_maze.h"
#include "lfsr.h"
const uint64_t FEEDBACK=0x800000000000000D;

void bit_ctrl_0 (uint64_t* maze, int bit) {
	uint64_t tmp = 0x0000000000000001;
	*maze &= ~(tmp << bit);
}
void bit_ctrl_1 (uint64_t* maze, int bit) {
	uint64_t tmp = 0x0000000000000001;
	*maze |= (tmp << bit);
}


void generate_maze(uint64_t* maze, int h, int w, int i_i, int i_j, uint64_t* seed) {
// "h" is the number of cell in one column, "w" is the number of cell in one row
//"i_i","i_j" is the index of the initial position, where this maze should start.

	bit_ctrl_0(&maze[i_i], i_j);

	while(1){
		int range = 0;
		range = available_dir(maze, i_i, i_j);
		if(range == -1)		break;	
		
		int r = 0;
		r = random_dir(seed, range);
		int direction = 0;
		direction = choose_dir(maze, i_i, i_j, r);
		
		if(direction == 0){  
	    	bit_ctrl_0(&maze[i_i], i_j+1);
			i_j = i_j+2;	
			generate_maze(maze, h, w, i_i, i_j, seed);
			//i_j=i_j-2; 			
			//bit_ctrl_1(&maze[i_i], i_j-1);
		} 
		else if(direction == 1){
			bit_ctrl_0(&maze[i_i+1], i_j);
			i_i = i_i+2;
			generate_maze(maze, h, w, i_i, i_j, seed);
			//i_i=i_i-2;	
			//bit_ctrl_1(&maze[i_i-1], i_j);
			
		}	
		else if(direction == 2){
			bit_ctrl_0(&maze[i_i], i_j-1);
			i_j = i_j-2;
			generate_maze(maze, h, w, i_i, i_j, seed);
			//i_j=i_j+2;
			//bit_ctrl_1(&maze[i_i], i_j+1);		
		}	
		else if(direction == 3){
			bit_ctrl_0(&maze[i_i-1], i_j);
			i_i = i_i-2;
			generate_maze(maze, h, w, i_i, i_j, seed);
			//i_i=i_i+2;
			//bit_ctrl_1(&maze[i_i+1], i_j);
		}		
		
	}
	return;
}
//************you can define your function here

int available_dir(uint64_t* maze, int i_i, int i_j) {
// this function will output number of available direction at current position
// "i_i","i_j" is the index of the current position
// if there is no available direction, it returns -1.
	uint64_t j = 0x0000000000000001;
    int num;
    int i;

	j = j << i_j;

	num = 0;
    // right
    if ((maze[i_i] & (j << 2)) != 0)
        num++;
    // down
    if ((maze[i_i+2] & (j)) != 0)
        num++;
    // left
    if ((maze[i_i] & (j >> 2)) != 0)
        num++;
    // up
    if ((maze[i_i-2] & (j)) != 0)
        num++;   
	if(num==0)
		return -1;
    return num;
}

int random_dir(uint64_t* seed, int range) {
// this function picks one number randomly from 0 to range-1
// "seed" is used by lfsr function, when you use this function in generate_maze() you do not need to modified "seed", like following example.
	int n;

    *seed = lfsr64(*seed, FEEDBACK); 	
    n = random_lfsr(*seed, range-1);
    return n;
}

int choose_dir(uint64_t* maze, int i_i, int i_j, int r) {
// this function will output an available direction at current position
// "i_i","i_j" is the index of the current position
// output 0 means left, 1 means down, 2 means right, 3 means up
    uint64_t j = 0x0000000000000001;
    int ava_dir[4];
    int num = 0;
    int i;

    j = j << i_j;
    // right
    if ((maze[i_i] & (j << 2)) != 0)
        ava_dir[num++] = 0;
    // down
    if ((maze[i_i+2] & (j)) != 0)
        ava_dir[num++] = 1;
    // left
    if ((maze[i_i] & (j >> 2)) != 0)
        ava_dir[num++] = 2;
    // up
    if ((maze[i_i-2] & (j)) != 0)
        ava_dir[num++] = 3;

    return ava_dir[r];
}





