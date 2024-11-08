#include<stdio.h>
int level(int n);
int main(void)
{
    printf(" = %d\n", level(15));
    return 0;
}
int level(int n)
{
    int ans;
    if (n==1) {
        printf("1");
        return 1;
    }
    if (n>1) {
        if (n%2==1) {
            if(n!=2) printf("(");
        }
        ans = level(n-1);
        if (n%2==0) ans = ans + n;
        else ans = ans*n;
        if (n%2==0) printf("+%d",n);
        else printf(")*%d",n);
    }
    return ans;
}

