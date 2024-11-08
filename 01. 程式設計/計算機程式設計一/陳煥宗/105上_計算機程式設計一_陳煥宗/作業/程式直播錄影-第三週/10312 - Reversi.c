#include <stdio.h>
#include <stdlib.h>
#define B_SIZE 8

char board[B_SIZE][B_SIZE];

void read_board(){
    int i, j;
    for(i = 0; i < B_SIZE; i++){
        for(j = 0; j < B_SIZE; j++){
            scanf(" %c", &board[i][j]);
        }
    }
}

void print_board(){
    int i, j;
    for(i = 0; i < B_SIZE; i++){
        for(j = 0; j < B_SIZE; j++){
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int N;
    int i, j;
	char a[100], ch;
	int b[100];  //row
	int c[100];  //col
    int x[8]={0,0,1,-1,-1,1,1,-1};  //增
    int y[8]={1,-1,0,0,-1,1,-1,1};  //增
    int ax,ay;  //增
    int bx,by;  //增
    read_board();
    scanf("%d", &N);
    for(i=0;i<N;i++){
        ch = getchar();  //增
        scanf("%c %d %d",&a[i],&b[i],&c[i]);
    }
    /*FILE *fin;
    fin = fopen("10312.txt", "r");
    if (fin == NULL) {
        perror("10312.txt");
        exit(EXIT_FAILURE);
    }
    for(i = 0; i < B_SIZE; i++){
        for(j = 0; j < B_SIZE; j++){
            fscanf(fin, " %c", &board[i][j]);
        }
    }
    fscanf(fin, "%d", &N);
    for (i=0; i<N; i++) {
        fscanf(fin ,"%c",&ch);
        fscanf(fin, "%c %d %d",&a[i],&b[i],&c[i]);
    }*/
    //print_board();
	for(i=0;i<N;i++){
        board[b[i]][c[i]] = a[i];
        for(j=0;j<8;j++){
            for(ax=b[i]+x[j],ay=c[i]+y[j];;ax+=x[j],ay+=y[j]){
                if(ax>7||ax<0||ay>7||ay<0) break;
                if(board[ax][ay]=='-') break;
                if(board[ax][ay]==a[i]) break;
            }
            if(ax>7||ax<0||ay>7||ay<0) continue;
            if(board[ax][ay]=='-') continue;
            if(board[ax][ay]=='D'){
                for(bx=b[i]+x[j],by=c[i]+y[j];(bx!=ax)||(by!=ay);bx+=x[j],by+=y[j]){
                    board[bx][by] = 'D';
                }
            }
            if(board[ax][ay]=='L'){
                for(bx=b[i]+x[j],by=c[i]+y[j];(bx!=ax)||(by!=ay);bx+=x[j],by+=y[j]){
                    board[bx][by] = 'L';
                }
            }
        }
        //print_board();
	}
    print_board();
    printf("%d\n", N);

    return 0;
}
