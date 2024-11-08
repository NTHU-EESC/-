#include<stdio.h>
int nums[100][3];
int gcd[100], lcm[100];
int main(void)
{
    int i, j, k;
    int cases;
    scanf("%d",&cases);
    for(i=0;i<cases;i++){
        for(j=0;j<3;j++){
            scanf("%d",&nums[i][j]);
        }
    }
    for(i=0;i<cases;i++){
        for(j=nums[i][2];j>=0;j--){
            if(((nums[i][0]%j)==0)&&((nums[i][1]%j)==0)&&((nums[i][2]%j)==0)){
                gcd[i] = j;
                break;
            }
        }
        for(j=nums[i][2];;j++){
            if((j%nums[i][0]==0)&&(j%nums[i][1]==0)&&(j%nums[i][2]==0)){
                lcm[i] = j;
                break;
            }
        }
        printf("%d %d\n",gcd[i],lcm[i]);
    }
    /*for(i=0;i<cases;i++){
        printf("%d %d\n",gcd[i],lcm[i]);
    }*/
    return 0;
}
