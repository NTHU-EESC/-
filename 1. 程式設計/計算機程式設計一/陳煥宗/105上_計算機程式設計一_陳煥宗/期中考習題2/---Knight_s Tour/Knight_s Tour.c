#include <stdio.h>

#define SIZE 5
#define K_X 0
#define K_Y 0

//int num;

/*
�M�h���K�ب��k
�C�@��N��@�ب��k x �M y ���첾�q
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
�P�_�O�_�W�X�ѽL�B�O�_�w�g���L
path �N��O�ĴX�ب��k
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

/* �ǤJ�M�h�{�b����m�H�έn�M�䪺�O�ĴX�B */
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
    /* board �O���C�@��b�ĴX�B�Q���� */
    int board[SIZE][SIZE] = {0};

    board[K_X][K_Y] = 1;//*****
    knightTour(board, K_X, K_Y, 2);//board������
    if (NoSolution == 1)
        printf("No Solution\n");
    //printf("%d",num);
    return 0;
}
