#include<stdio.h>
int main(void)
{
    int i, j, N, n;
    float p[100][5];
    float v1,v2,m,k;
    //v1 = 1;
    //v2 = 0;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        for(j=0;j<5;j++){
            scanf("%f",&p[i][j]);
        }
    }
    //k = v1;
    //m = v2;
    for(i=0;i<N;i++){
        v1 = 1;
        v2 = 0;
        k = v1;
        m = v2;
        for(n=0;k>p[i][4];n++){
            v1 = k*p[i][0] + m*p[i][1];
            v2 = p[i][2]*k + p[i][3]*m;
            k = v1;
            m = v2;
			//if(k<=p[4])break;
        }
            printf("%d\n",n);
    }
    return 0;
}
