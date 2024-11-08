#include <stdio.h>
#include <stdlib.h>
//#include "function.h"
typedef struct {
    int score[3], id;
} Score;
int cmp( const void *a , const void *b );
int main(){
    Score students[22];
    int i, n;
    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%d%d%d",&students[i].score[0],&students[i].score[1],&students[i].score[2]);
        students[i].id=i+1;
    }
    qsort(students, n, sizeof(Score), cmp);

    for(i=0;i<n;i++){
        printf("%d ", students[i].id);
    }
    return 0;
}
int cmp( const void *a , const void *b )
{
    Score* va = (const Score *)a;
    Score* vb = (const Score *)b;
    int i;
    for(i=0;i<3;i++){
        if(va->score[i] != vb->score[i]) return -va->score[i] + vb->score[i];
    }
    return va->id - vb->id;
}
