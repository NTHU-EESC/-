#include <stdio.h>
void multiply(int c[], int a[], int deg, int N, int num);
int main(void)
{
    int deg, N, tmp;
    int i,j,k;
    int a[200]={0};
    int c[200]={0};

    scanf("%d",&N);
    for (i=0; i<=N; i++) {
        scanf("%d ", &a[i]);
        c[i] = a[i];
    }
    scanf("%d",&deg);
    /*tmp = deg;  //
    while (tmp==1) {
        for (i=0; i<=N; i++) {
            c[i]+=a[i];
        }
       tmp--;
    }
    while (tmp==2) {
        for (i=0; i<=N; i++) {
            for (j=0; j<=N; j++) {
                c[i+j]+=a[i]*a[j];
            }
        }
       tmp--;
    }
    while (tmp==3) {
        for (i=0; i<=N; i++) {
            for (j=0; j<=N; j++) {
                for (k=0; k<=N; k++){
                    c[i+j+k]+=a[i]*a[j]*a[k];
                }
            }
        }
       tmp--;
    }*/
    multiply(c,a,deg,N,N);
    for (i=0; i<(N*deg+1); i++) {  //
        printf("%5d", c[i]);
    }
    printf("\n");
    return 0;
}

void multiply(int c[], int a[], int deg, int N, int num){
    int i, j, k;
    int tmp[200] = {0};
    if(deg==1);
    else{
        for (i=0; i<=N; i++) {
            for (j=0; j<=num; j++) {
                tmp[i+j]+=c[i]*a[j];
            }
        }
        for(k=0;k<=2*N;k++){
            c[k] = tmp[k];
        }
        multiply(c,a,deg-1,2*N,num);
    }
}
