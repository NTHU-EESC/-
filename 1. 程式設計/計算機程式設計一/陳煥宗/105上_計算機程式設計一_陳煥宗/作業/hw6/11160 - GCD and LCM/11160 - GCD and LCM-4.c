#include<stdio.h>
int GCD(int,int);
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
        gcd = GCD(GCD(nums[0],nums[1]),nums[2]);
        lcm = (nums[0]*nums[1]*nums[2])/GCD(nums[0],nums[1])/GCD(nums[0],nums[2])/GCD(nums[1],nums[2])*gcd;
        printf("%d %d\n",gcd,lcm);

    }
    return 0;
}
int GCD(int a,int b)
{
    int i;
    if(b>a){
        for(i=a;i>0;i--){
            if((a%i==0)&&(b%i==0)){
                return i;
            }
        }
    }
    else{
        for(i=b;i>0;i--){
            if((a%i==0)&&(b%i==0)){
                return i;
            }
        }
    }
}
