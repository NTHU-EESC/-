#include<stdio.h>
#include<stdlib.h>

int Determinant(int matrix[][8], int num);

int main(void)
{
    int n, ans;
    int i, j, k;
    int matrix[8][8] = {0};
    scanf("%d", &n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    ans = Determinant(matrix, n);
    printf("%d\n",ans);
    return 0;
}

int Determinant(int matrix[][8], int num){
    int ans = 0;
    int i, j, k;
    int divid[8][8]={0};
    //int divid[8][8];
    /*for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");*/
    if(num>2){
        for(k=0;k<num;k++){
            for(i=0;i<num;i++){
                for(j=1;j<num;j++){
                    if((i<k)) divid[j-1][i] = matrix[j][i];
                    else if(i>k) divid[j-1][i-1] = matrix[j][i];
                }
            }

            /*for(i=0;i<8;i++){
                for(j=0;j<8;j++){
                    printf("%d ", divid[i][j]);
                }
                printf("\n");
            }
            printf("\n");*/

            if((k%2)==0) ans += matrix[0][k]*Determinant(divid, num-1);
            else ans -= matrix[0][k]*Determinant(divid, num-1);
        }
    }
    else if(num==2){
        ans = (matrix[0][0]*matrix[1][1])-(matrix[0][1]*matrix[1][0]);
    }
    //printf("%d\n", num);
    return ans;
}
