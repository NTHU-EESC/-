// �������A��
// �b��ӧO���A��
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
        swap2(a, 0, 0);//����A�� //�]���ڭ̥���l�e�謰0�A�ҥH��Ū��ch=0�ɪ�ܨ쵲���F
        a[i]=' ';

        i=0;
        while(a[i]!=0) i += swap2(&a[i],0,' ')+1; //���C�ӳ�r�}�Y��index�A�ǤJswap2����r�A��
                                             //�Y���swap2(&a[i],0,' ')�Aa[i]�|Ū��ť�
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

//swap2�|�^�Ǧr�����
int swap2(char *a, int b, char c)
{
    char ch;
    int i;
    ch = *a;
    if (ch!=c)
    {
        i = swap2(a+1,b+1,c);
        if(b<=i){           // �קK���⦸���ܦ��쥻���ˤl
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
