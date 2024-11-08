#include<stdio.h>
int main(void)
{
    int i, j, k;
    int cases;
    int nums[100];
    int gcd, lcm;
    scanf("%d",&cases);
    for(i=0;i<cases;i++){
        for(j=0;j<3;j++){
            nums[j] = 0;
            scanf("%d",&nums[j]);
        }
        for(j=nums[0];j>=0;j--){
            if(((nums[0]%j)==0)&&((nums[1]%j)==0)&&((nums[2]%j)==0)){
                gcd = j;
                //printf("%d ",gcd);
                break;
            }
        }
        for(j=nums[2];j<=(nums[0]*nums[1]*nums[2]);j++){
            if((j%nums[0]==0)&&(j%nums[1]==0)&&(j%nums[2]==0)){
                lcm = j;
                //printf("%d\n");
                break;
            }
        }
        printf("%d %d\n",gcd,lcm);

    }
    /*for(i=0;i<cases;i++){
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
    }*/
    /*for(i=0;i<cases;i++){
        printf("%d %d\n",gcd[i],lcm[i]);
    }*/
    return 0;
}

