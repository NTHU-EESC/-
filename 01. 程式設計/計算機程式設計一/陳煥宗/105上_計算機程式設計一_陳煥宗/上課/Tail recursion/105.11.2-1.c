#include<stdio.h>
int fact(int n, int ans);
int main(void)
{
    printf("%d\n", fact(15, 1));
    int ans = 1;
    int n = 15;
    while(n>0){
        ans = n*ans;
        n--;
    }
    printf("%d",ans);
    return 0;
}
int fact(int n, int ans)
{
    if(n==0) return ans;
    else return fact(n-1, ans*n);
}
//¦¹ans = 15!
