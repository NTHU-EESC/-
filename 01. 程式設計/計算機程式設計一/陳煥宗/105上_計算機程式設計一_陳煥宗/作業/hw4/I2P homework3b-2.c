#include <stdio.h>
int input[10];
int visited[10]; // True or False
int main(){
    int ptr,ans;
    ptr=ans=0;
    int i;
    for(i=1;i<10;i++){
        scanf("%d",&input[i]);
    }
    ptr=1;
    while(!visited[ptr]){
        ans=ans+input[ptr];
        visited[ptr]=1;//¨«¹L
        ptr=input[ptr];
    }
    printf("%d\n",ans);
}
