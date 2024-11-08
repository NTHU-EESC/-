#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 6
using namespace std;

int compare_int (const void *a, const void *b)  //const絋玂把计肚秈ㄓぃ穦砆э->ぃ砆э->ぃ暗++or--单单
{
    const int *va = (const int *) a;
    const int *vb = (const int *) b;
    return *va-*vb;
    //return *((const int *)a) - *((const int *)b);  //搇ョр︽虏てΘ
}

void bubble_sort(int** num, int in);
int check(int** num, int** lottery, int in, int now);

int main(void)
{
    char c;
    int in, out;
    cin >> c;  // read all input

    cin >> in;
    int** num = (int**)malloc(in*sizeof(void*));
    for(int i=0; i<in ; i++){
        num[i] = (int*)malloc(SIZE*sizeof(int));
        for(int j=0; j<SIZE; j++) cin >> num[i][j];
        qsort(num[i], SIZE, sizeof(int), compare_int);
    }


    bubble_sort(num, in);

    cin >> out;
    int* ans = (int*)malloc(out*sizeof(int));
    int** lottery = (int**)malloc(out*sizeof(int*));
    for(int i=0; i<out ; i++){
        lottery[i] = (int*)malloc(SIZE*sizeof(int*));
        for(int j=0; j<SIZE; j++) cin >> lottery[i][j];
        qsort(lottery[i], SIZE, sizeof(int), compare_int);
        ans[i] = check(num, lottery, in, i);
    }

    cout << c << endl << in << endl;
    for(int i=0; i<in; i++){
        for(int j=0; j<SIZE-1; j++){
            if(num[i][j]<10) cout << "0"<< num[i][j]<< " ";
            else cout << num[i][j] <<" ";
        }
        cout <<num[i][SIZE-1] << endl;
    }
    cout << out << endl;
    for(int i=0; i<out-1; i++){
        for(int j=0; j<SIZE; j++){
            if(lottery[i][j]<10) cout << "0"<< lottery[i][j]<< " ";
            else cout << lottery[i][j] <<" ";
        }
        if(ans[i] == true) cout <<"Y "<< ans[i]+1<< endl;
        else cout <<"N" << endl;
    }
    for(int j=0; j<SIZE; j++){
        if(lottery[out-1][j]<10) cout << "0"<< lottery[out-1][j]<< " ";
        else cout << lottery[out-1][j] <<" ";
    }
    if(ans[out-1] == true) cout <<"Y "<< ans[out-1]+1;
    else cout <<"N";

    return 0;
}

void bubble_sort(int** num, int in)
{
    int* tmp;
    for(int i=0; i<in; i++){
        for(int j=i+1; j<in; j++){
            if(num[i][0]>num[j][0]){
                tmp = num[i];
                num[i] = num[j];
                num[j] = tmp;
            }
        }
    }
}

int check(int** num, int** lottery, int in, int now)
{
    int flag;
    for(int i=0; i<in; i++){
        if(num[i][0] == lottery[now][0]){
            for(int j=1; j<SIZE; j++){
                if(num[i][j] == lottery[now][j]) flag = 1;
                else{
                    flag = 0;
                    break;
                }
            }
            if(flag == 1) return i;
        }
        else continue;
    }
    return 0;
}
