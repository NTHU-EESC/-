#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10
int trace(int* ,int* ,int );
int main(void)
{
    FILE *fin, *fout;
    char ch;
    int i,t;
    int a[N]={0},b[N]={0},c[N]={0},d[N]={0},e[N]={0};//多給一些陣列，不一定每個都用到
    fin = fopen("group-1.txt", "r");
    fout = fopen("group_out-1.txt", "w");
    if (fin==NULL) return -1;

    i=0;
    while(i<N)
    {
        ch = fgetc(fin); // ch = getchar()
        if(ch=='='){
            fscanf(fin,"%d", &t);
            a[i] = t-1;
            i++;
        }else if(ch==','){ //do nothing
        }else{
            ungetc(ch,fin);
            fscanf(fin,"%d",&t);
            b[i] = t;
            i++;
        }
    }
    for(i=0;i<N;i++)
    {
        trace(a,b,i);//對每一個人，追蹤他
    }
    for(i=0;i<N;i++)
    {
        fprintf(fout,"%d %d\n",a[i],b[i]);/* ??? 存檔 */
    }
    fclose(fin);
    fclose(fout);
    return 0;
}

int trace(int a[],int b[], int i)
{
    int j;
    if(b[i]) return b[i];
    else{
        j = trace(a,b,a[i]);
        b[i] = j;
        return j;
    }
}
