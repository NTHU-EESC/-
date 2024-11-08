#include <stdio.h>
#define NQ 4

void place(int q[], int row);
int valid(int q[], int row, int col);
void display(int q[]);

int main(void)
{
    int q[NQ] = {0};
    /* q[i] �O�����O�b�� i �C (row) �X�{���ӦZ�A�n�\�b�ĴX�� (column) */
    /* Ĵ�p�Aq[] �����e�p�G�O {2, 0, 3, 1}�A��ܥ|�ӬӦZ���O��b�ѽL�� (0,2), (1,0), (2,3), (3,1) �|�Ӧ�m */

    place(q, 0);

    return 0;
}

/*
�P�_�ثe�����p�U�A�p�G�b row, col ��m��J�s���ӦZ
�O�_�|�M���e���ӦZ�Ĭ�
�p�G�O�X�k����m�覡 return 1;
�p�G���Ĭ� return 0;
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
