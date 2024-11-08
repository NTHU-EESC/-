#include <iostream>
#include <stdio.h>
using namespace std;
#include <fstream>


#define lim 1000000000000000000
#define limDigit 18
int num_count(long long int *num);

int main()
{
    long long int a1[2000];
    long long int a2[2000];
    long long int a3[2000];
    int digi;
    int digit;
    long long int j;
    int Input;
    int k;
    int i;

   // freopen("t2.txt", "r", stdin);
    //freopen("a1.txt", "w", stdout);
    cin >> Input;
    cout <<Input<<endl;
    cin >> Input;
    while(!cin.eof()){

        //if(!cin.eof()) return 0;
        for(i = 1 ;i<2000 ;i++){
            a3[i] = 0;
            a2[i] = 0;
            a1[i] = 0;
        }
        a3[0] = 0;
        a2[0] = 1;
        a1[0] = 1;
        /*cout <<"a1";
        for(i = 4 ;i>=0; i--){
            printf("%12lld",a1[i]);
        }
        cout << endl;
        cout <<"a2";
        for(i = 4 ;i>=0; i--){
            printf("%12lld",a2[i]);
        }
        cout << endl;
        cout <<"a3";
        for(i = 4 ;i>=0; i--){
            printf("%12lld",a3[i]);
        }
        cout << endl;*/

        while(1){
            for( k  =0;a1[k] !=0 or a2[k]!=0;k++ ){
                a3[k] += a2[k] + a1[k];
                if(a3[k]>=lim){
                    a3[k] -= lim;
                    a3[k+1] = 1;
                }
            }
            if (a3[k] == 1)k++;

            if(Input <= k*limDigit){

                for (j = 1,i=0,digi=0 ; digi==0 ; j*=10,i++)
                    if(a3[k-1]/j==0) digi = i;
                if( (digi + (k-1)*limDigit) == Input ){
                        digit = digi + (k-1)*limDigit;
                  //  if(digi/limDigit==0) i =
                        cout << Input<<" ";
                    for(i= digit%limDigit==0 ? digit/limDigit -1:digit/limDigit,
                        j = 0 ; i>=0 ;i--,j++){
                            if(j==0)    cout<<a3[i];
                            else    printf("%018lld",a3[i]);
                    }
                   // cout<<"digit="<<digit;
                     //   cout <<"----------------"<<endl;
                    num_count(a3);
                     //cout <<k*limDigit<<endl;
                     cin >>Input;
                    break;
                }
            }
            /*cout <<"a1";
        for(i = 4 ;i>=0; i--){
            printf("%12lld",a1[i]);
        }
        cout << endl;
        cout <<"a2";
        for(i = 4 ;i>=0; i--){
            printf("%12lld",a2[i]);
        }
        cout << endl;
        cout <<"a3";
        for(i = 4 ;i>=0; i--){
            printf("%12lld",a3[i]);
        }
        cout << endl;
*/


            for(int i=0 ; i < k ; i++ ){
                a1[i] = a2[i];
                a2[i] = a3[i];
                a3[i] = 0;
            }
        }
    }

    return 0;
}

int num_count(long long int *num){
    int z2n[10];
    int i;

    for(i = 0; i<10 ; i++)  //initializing
        z2n[i] = 0;

    for( ; *(num+1) != 0 ; num++){
        for(i = 0;i<limDigit ;i++){
            z2n[ (*num) % 10 ] ++ ;
            *num /= 10;
        }
    }
    while(*num!=0){
        z2n[ (*num) % 10 ] ++ ;
        *num /= 10;
    }

    for(i = 0; i<10 ; i++) //printing
        cout <<" "<< z2n[i] ;
    cout << endl;


return 0;
}
