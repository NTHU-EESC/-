#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100
using namespace std;

int fibonacci(int num, int* ans);
void big_add(int* a, int* b, int* rst);
int big_compare(int* a, int* b);

int main(void)
{
    int n;
    cin >> n;
    int* num = (int*)malloc(n*sizeof(int));
    int** ans = (int**)malloc(n*sizeof(void*));
    for(int i=0; i<n; i++) cin >> num[i];

    for(int i=0; i<n; i++){
        ans[i] = (int*)malloc(MAX*sizeof(int));
        for(int j=0; j<MAX; j++) ans[i][j] = -1; //initialize
        fibonacci(num[i], ans[i]);
    }

    cout << n <<endl;
    for(int i=0; i<n; i++){
        cout <<num[i] <<" ";
        for(int j=0; ans[i][j]!=-1; j++) cout <<ans[i][j];
        cout <<endl;
    }

    return 0;
}

int fibonacci(int num, int* ans)
{
    int** f = (int**)malloc(1000*sizeof(void*));
    for(int i=0; i<1000; i++){
        f[i] = (int*)malloc(MAX*sizeof(int));
        for(int j=0; j<MAX; j++) f[i][j] = -1;
    }
    f[0][0] = 1;
    f[1][0] = 1;
    int lb[MAX];
    for(int i=0; i<MAX; i++) lb[i] = -1;

    for(int i=0; i<num-1; i++) lb[i] = 0;
    lb[num-1] = 1;

    for(int i=1; ;i++){
        cout << i << endl;
        if(big_compare( f[i], lb)){
            //cout << i+100 << endl;
            for(int j=0; f[i][j]!=-1; j++) ans[j] = f[i][j];
            return 0;
        }
        else{
            cout << i+200 << endl;
            big_add(f[i-1], f[i], f[i+1]);
        }
    }
}

void big_add(int* a, int* b, int* rst)  //a < b
{
    int carry = 0;
    int num;
    for(int i=0; (a[i]!=-1)||(b[i]!=-1); i++){
        rst[i] = a[i] + b[i] + carry;
        carry = rst[i]/10;
        rst[i] %= 10;
        num = i;
    }
    if((carry)||(b[num+1]!=-1)){
        rst[num+1] = carry;
        if(b[num+1]!=-1) rst[num+1] += b[num+1];
    }
}

int big_compare(int* a, int* b)
{
    int i = MAX-1;
    while(i>0 && a[i]==b[i]) i--;
    return a[i] - b[i];
}
