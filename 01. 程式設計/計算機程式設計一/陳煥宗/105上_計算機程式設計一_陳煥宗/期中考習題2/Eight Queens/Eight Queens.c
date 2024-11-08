#include <stdio.h>
#define NQ 4

void place(int q[], int row);
int valid(int q[], int row, int col);
void display(int q[]);

int main(void)
{
    int q[NQ] = {0};
    /* q[i] 記錄的是在第 i 列 (row) 出現的皇后，要擺在第幾行 (column) */
    /* 譬如，q[] 的內容如果是 {2, 0, 3, 1}，表示四個皇后分別放在棋盤的 (0,2), (1,0), (2,3), (3,1) 四個位置 */

    place(q, 0);

    return 0;
}

/*
判斷目前的狀況下，如果在 row, col 位置放入新的皇后
是否會和之前的皇后衝突
如果是合法的放置方式 return 1;
如果有衝突 return 0;
*/
int valid(int q[], int row, int col)
{
    int i;
    for (i=0; i<=row-1; i++) {
        if(q[i]==col||row-i==col-q[i]||row-i==q[i]-col) return 0;
    }
    return 1;
}

void display(int q[])
{
    int i, j;
    for(i=0;i<NQ;i++){
        for(j=0;j<NQ;j++){
            if(q[i]==j) printf("@");
            else printf("o");
        }
        printf("\n");
    }
    printf("\n");
}

void place(int q[], int row)
{
    int j;
    //printf("%d",row);
    if (row == NQ) {
        display(q);
    }
    else {
        for (j=0; j<NQ; j++) {
            if (valid(q, row, j)) {
                *(q+row) = j;//*****
                place(q,row+1);
            }
        }
        //place(q,q++);
    }
}
