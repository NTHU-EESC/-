#include <stdio.h>

#define SIZE 5
#define K_X 0
#define K_Y 0

//int num;

/*
騎士的八種走法
每一行代表一種走法 x 和 y 的位移量
*/
int Move[8][2] = {
     1, -2,
     2, -1,
     2,  1,
     1,  2,
    -1,  2,
    -2,  1,
    -2, -1,
    -1, -2
};
int NoSolution = 1;

void display(int board[SIZE][SIZE])
{
    int i, j;

    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/*
判斷是否超出棋盤、是否已經走過
path 代表是第幾種走法
*/
int valid(int board[SIZE][SIZE], int x, int y, int path)
{
    int next_x, next_y;

    next_x = x + Move[path][0];
    next_y = y + Move[path][1];
    /* */
    if(next_x<0||next_x>=SIZE||next_y<0||next_y>=SIZE) return 0;
    else if(board[next_x][next_y]!=0) return 0;
    else return 1;
}

/* 傳入騎士現在的位置以及要尋找的是第幾步 */
void knightTour(int board[SIZE][SIZE], int x, int y, int step)
{
    int next_x, next_y;
    int i;

    if (step == SIZE * SIZE + 1) {
        NoSolution = 0;
        display(board);
        //num++;
        return;
    }
    for (i = 0; i < 8; ++i) {
        if (valid(board, x, y, i) == 1) {
            next_x = x + Move[i][0];
            next_y = y + Move[i][1];
            board[next_x][next_y] = step;/* */
            knightTour(board, next_x, next_y, step+1);//if step++ -> step = step + 1;
            board[next_x][next_y] = 0;
        }
    }
}

int main(int argc, char *argv[])
{
    /* board 記錄每一格在第幾步被走到 */
    int board[SIZE][SIZE] = {0};

    board[K_X][K_Y] = 1;//*****
    knightTour(board, K_X, K_Y, 2);//board為指標
    if (NoSolution == 1)
        printf("No Solution\n");
    //printf("%d",num);
    return 0;
}
