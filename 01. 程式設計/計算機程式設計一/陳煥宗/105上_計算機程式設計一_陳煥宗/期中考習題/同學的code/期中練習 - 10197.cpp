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
        giver--;					//�N�H�ƽs���վ㬰���� 
        if(a[giver]<given)
            continue;				//���X�h�� > �������A���L�j���b������ i++ ���]  
        if(FB=='B'){
            a[giver]-=given;
            a[(giver+9)%10]+=given; // �b�@�뱡�p��-1 �bgiver = 1 �ɷ| = 10 
        }else{
            a[giver]-=given;
            a[(giver+1)%10]+=given; // �b�@�뱡�p��+1 �bgiver = 10 �ɷ| = 1 
        }
    }
    for(i=0;i<10;i++)
        printf("%d\n",a[i]);
    return 0;
}

