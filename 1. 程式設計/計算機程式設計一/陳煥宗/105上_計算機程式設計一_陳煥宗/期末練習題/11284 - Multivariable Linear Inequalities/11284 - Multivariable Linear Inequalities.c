#include<stdio.h>

void f(int sum, int idx, int a[]);
void show(int sum, int a[]);

int glb, lub, num;
//int arr[30]={0};

int main(void)
{
    int arr[30] = {0};
    scanf("%d %d %d", &glb, &lub, &num); // glb<x+y+z<=lub
    f(0,num-1, arr);
    return 0;
}

void f(int sum, int idx, int arr[])
{
    int i, j, k;
    for(i=0;i<=lub;i++){
        arr[idx] = i;
        if(sum!=(sum+i)){
            if((sum+i)>glb){
                if((sum+i)<=lub) show(sum+arr[idx], arr);
            }
        }
        if(idx>0) f(sum+i,idx-1, arr);
        arr[idx] = 0;
    }
}

void show(int sum, int arr[])
{
    int i, j, k;
    //if((sum>glb)&&(sum<=lub)){
        for(i=(num-1);i>0;i--) printf("%d ",arr[i]);
        printf("%d\n", arr[0]);
    //}
}
