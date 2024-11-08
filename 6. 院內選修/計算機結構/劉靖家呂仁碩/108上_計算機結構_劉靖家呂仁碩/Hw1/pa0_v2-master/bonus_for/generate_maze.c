#include "generate_maze.h"


const uint64_t FEEDBACK=0x800000000000000D;


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




void generate_maze(uint64_t* maze, int h, int w, int i_i, int i_j, uint64_t* seed) {
// "h" is the number of cell in one column, "w" is the number of cell in one row
//"i_i","i_j" is the index of the initial position, where this maze should start.
	int i,j;

	//初始化棧
	STACK *stack;
	LOCAL temp;
	stack = InitStack();
	temp.x = i_i; temp.y = i_j;
	PushStack(stack, &temp);
	bit_ctrl_0(&maze[i_i], i_j);
	int first=1;
	
	while(!EmptyStack(stack)){
		//PopStack(stack, &temp);
		i = temp.x;	j = temp.y;
		
		int range = available_dir(maze, i, j);
	
		while(!EmptyStack(stack)){
			if(first==1) break;
			else{
				if(range != -1){
					break;
				} 
				else{
					PopStack(stack, &temp);
					i = temp.x;	j = temp.y;
					range = available_dir(maze, temp.x, temp.y);
				} 
			}
		} 
		if(i==i_i && j==i_j && first==0)	break;
		first=0;
	
		int r = 0;
		r = random_dir(seed, range);
		int direction = 0;
		direction = choose_dir(maze, i, j, r);
			
		if(direction == 0){  
			bit_ctrl_0(&maze[i], j+1);
			j = j+2;
			temp.x=i ; temp.y=j;	
			PushStack(stack, &temp);
			bit_ctrl_0(&maze[i], j);
		}
		else if(direction == 1){
			bit_ctrl_0(&maze[i+1], j);
			i = i+2;
			temp.x=i ; temp.y=j;	
			PushStack(stack, &temp);
			bit_ctrl_0(&maze[i], j);
		}
		else if(direction == 2){
			bit_ctrl_0(&maze[i], j-1);
			j = j-2;
			temp.x=i ; temp.y=j;	
			PushStack(stack, &temp);
			bit_ctrl_0(&maze[i], j);
		}	
		else if(direction == 3){
			bit_ctrl_0(&maze[i-1], j);
			i = i-2;
			temp.x=i ; temp.y=j;	
			PushStack(stack, &temp);
			bit_ctrl_0(&maze[i], j);
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





