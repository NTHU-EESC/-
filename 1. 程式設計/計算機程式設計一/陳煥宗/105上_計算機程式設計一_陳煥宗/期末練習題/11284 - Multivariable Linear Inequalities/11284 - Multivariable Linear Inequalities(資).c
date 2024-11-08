#include <stdio.h>
#define MAXN 20

int num[MAXN];
int l, u, n;

void show(void){
    int i;
    for(i=0; i<n-1; i++)
        printf("%d ", num[i]);
    printf("%d\n", num[n-1]);
}

void go(int sum, int idx){
    int i;
    if(sum == u){
        for(i=idx; i<n; i++){
            num[i] = 0;
        }
        show();
        return;
    }
    if(idx == n-1){
        for(i=0; i<=u-sum;i++){
            if(sum+i>l){
                num[n-1] = i;
                show();
            }
        }
        return;
    }
    for(i=0; i<=u-sum; i++){ // move to right
        num[idx] = i;
        go(sum+i, idx+1);
    }
}

int main(void){
    scanf("%d%d%d", &l, &u, &n);
    go(0,0);
    return 0;
}
