#include <stdio.h>
int main (void){
    char FB;			//F or B
    int i,operation,giver,given,a[10];
    for(i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&operation);
    for(i=0;i<operation;i++){
        scanf("%d %c %d",&giver,&FB,&given);
        giver--;					//將人數編號調整為項數 
        if(a[giver]<given)
            continue;				//當給出去的 > 持有的，跳過迴圈後半部直接 i++ 重跑  
        if(FB=='B'){
            a[giver]-=given;
            a[(giver+9)%10]+=given; // 在一般情況為-1 在giver = 1 時會 = 10 
        }else{
            a[giver]-=given;
            a[(giver+1)%10]+=given; // 在一般情況為+1 在giver = 10 時會 = 1 
        }
    }
    for(i=0;i<10;i++)
        printf("%d\n",a[i]);
    return 0;
}

