// 先把整行顛倒
// 在把個別的顛倒
#include <stdio.h>
#include <stdlib.h>

int swap2(char *a, int b, char c);
int main(void)
{
    FILE *fin, *fout;
    char a[421]={0},ch;
    int i;
    fin = fopen("swap2.txt", "r");
    fout = fopen("swap2_out.txt", "w");
    if (fin==NULL) return -1;

    while((ch=fgetc(fin)) != EOF)
    {
        i=0;
        while(ch!='\n' && ch!=EOF)
        {
            a[i++] = ch;
            ch = fgetc(fin);
        }
        swap2(a, 0, 0);//整行顛倒 //因為我們先初始畫質為0，所以當讀到ch=0時表示到結尾了
        a[i]=' ';

        i=0;
        while(a[i]!=0) i += swap2(&a[i],0,' ')+1; //找到每個單字開頭的index，傳入swap2做單字顛倒
                                             //若單純swap2(&a[i],0,' ')，a[i]會讀到空白
        i=0;
        while (a[i]!=0)
        {
            fprintf(fout, "%c", a[i]);
            a[i]=0;
            i++;
        }
        fprintf(fout, "\n");
    }

    fclose(fin);
    fclose(fout);
}

//swap2會回傳字串長度
int swap2(char *a, int b, char c)
{
    char ch;
    int i;
    ch = *a;
    if (ch!=c)
    {
        i = swap2(a+1,b+1,c);
        if(b<=i){           // 避免換兩次而變成原本的樣子
            *a = *(a-b+i);  //a[b] = a[b-b+i]
            *(a-b+i) = ch;
        }
        return i+1;
    }
    else return 0;
}

/*i=0;
while((ch = getchar())!='\n'){
    a[i] = ch;
    i++;
}
putchar(ch);*/
