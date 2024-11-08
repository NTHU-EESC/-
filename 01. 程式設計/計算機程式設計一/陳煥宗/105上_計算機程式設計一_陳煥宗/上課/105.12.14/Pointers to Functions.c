#include <stdio.h>
#include <stdlib.h>
int sum(int a[], int n)
{
    int i, ans = 0;
    for (i=0; i<n; i++) {
        ans += a[i];
    }
    return ans;
}
int sum_squared(int a[], int n)
{
    int i, ans = 0;
    for (i=0; i<n; i++) {
        ans += a[i]*a[i];
    }
    return ans;
}

int middle(int a[], int n)
{
    return a[n/2];
}

int run (  int  (*fp) (int *, int )  , int a[], int n)
{
    return fp(a, n);
}

int main(void)
{
    int a[] = {1, 2, 3, 4};
    printf("%d\n", run(sum, a, 4));  // fp = sum; sum(a,4);
    printf("%d\n", run(sum_squared, a, 4));
    printf("%d\n", run(middle, a, 4));
    return 0;
}
