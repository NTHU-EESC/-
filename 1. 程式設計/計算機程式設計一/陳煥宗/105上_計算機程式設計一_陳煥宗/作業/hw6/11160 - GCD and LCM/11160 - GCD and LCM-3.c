#include<stdio.h>
int main(void)
{
    int i, j, k;
    int cases;
    int nums[100];
    int gcd, lcm, check;
    scanf("%d",&cases);
    for(i=0;i<cases;i++){
        for(j=0;j<3;j++){
            nums[j] = 0;
            scanf("%d",&nums[j]);
        }
        for(j=nums[0];j>=0;j--){
            check = 1;
            for(k=0;k<3;k++){
                if(nums[k]%j!=0) check = 0;
            }
            if(check){
                gcd = j;
                break;
            }
            /*if(((nums[0]%j)==0)&&((nums[1]%j)==0)&&((nums[2]%j)==0)){
                gcd = j;
                //printf("%d ",gcd);
                break;
            }*/
        }
        for(j=nums[2];j<=(nums[0]*nums[1]*nums[2]);j++){
            check = 1;
            for(k=0;k<3;k++){
                if(j%nums[k]!=0) check = 0;
            }
            if(check){
                lcm = j;
                break;
            }
        }
        printf("%d %d\n",gcd,lcm);

    }
    return 0;
}
