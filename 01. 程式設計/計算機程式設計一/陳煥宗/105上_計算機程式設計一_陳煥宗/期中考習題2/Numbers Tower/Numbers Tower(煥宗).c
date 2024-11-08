#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 15

int Height;   /* �O���𪺰��� */
int Value;    /* �n�o�쪺�ƭ� */
int NoSolution = 1;

void display(int path[])
{
    int i;

    for (i = 0; i < Height; ++i) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

/* �ǤJ�Y�N�i�J�ĴX�h�B�ĴX�Ӧ�m�H�Υثe����[�` */
void goThroughTower(int tower[MAX_SIZE][MAX_SIZE], int path[], int level, int index, int sum)//�ۤv��
{
    if (level + 1 == Height) {
        if (sum + tower[level][index] == Value) {
            NoSolution = 0;
            path[level] = tower[level][index];
            display(path);
        }
        return;
    }
    else {
        path[level] = tower[level][index];
        goThroughTower(tower, path, level+1, index, sum+tower[level][index]);
        goThroughTower(tower, path, level+1, index+1, sum+tower[level][index]);
    }
}

int main(int argc, char *argv[])
{
    FILE *fin;
    int tower[MAX_SIZE][MAX_SIZE];
    int path[MAX_SIZE];   /* �O���C�@�h�ҿ�ܪ��Ʀr */
    int i, j, width;

    fin = fopen("nTower.txt", "r");
    if (fin == NULL) {
        perror("nTower.txt");
        exit(EXIT_FAILURE);
    }
    fscanf(fin, "%d %d", &Height, &Value);
    for (i = 0; i < Height; ++i) {
        for(j = 0; j<= i; j++){
            fscanf(fin, "%d",&tower[i][j]);
        }
    }

    path[0] = tower[0][0];
    goThroughTower(tower, path, 0, 0, 0);
    if (NoSolution == 1)
        printf("No Solution\n");

    return 0;
}
