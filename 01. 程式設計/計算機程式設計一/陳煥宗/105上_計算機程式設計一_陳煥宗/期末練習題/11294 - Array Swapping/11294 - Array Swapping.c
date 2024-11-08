#include <stdio.h>

void swap_array( int *loc_S, int *loc_T, int N ){
    int i, tmp;
    for(i=0; i<N; i++){
        tmp = *(loc_S+i);
        *(loc_S+i) = *(loc_T+i);
        *(loc_T+i) = tmp;
    }
}

int main(void){
    int i, M, array[20], O;
    scanf("%d", &M);
    for(i=0; i<M; i++)
        scanf("%d", &array[i]);
    scanf("%d", &O);
    for(i=0; i<O; i++){
        int N, S, T;
        scanf("%d%d%d", &N, &S, &T);
        swap_array( array+S, array+T, N );
    }
    for(i=0; i<M-1; i++) printf("%d ", array[i]);
    printf("%d\n", array[M-1]);
    return 0;
}
