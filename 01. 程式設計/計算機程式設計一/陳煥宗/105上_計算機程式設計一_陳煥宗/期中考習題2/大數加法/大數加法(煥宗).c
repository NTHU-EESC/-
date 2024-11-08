#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define END_INT 999
void string_to_int(char *str, int num[]);
void show_big_int(int *num);
void add(int num1[], int num2[], int num3[]);

int main(void)
{
    char str[100];
    int A[100] = {0, END_INT};
    int B[100] = {0, END_INT};
    int C[101] = {0, END_INT};

    FILE *fin;
    fin = fopen("big_int.txt", "r");
    if (fin == NULL) {
        perror("big_int.txt");
        exit(EXIT_FAILURE);
    }

    fscanf(fin, "%99s", str); //ex.12345->str[0]=1;str[1]=2.....
    string_to_int(str, A);

    fscanf(fin, "%99s", str);
    string_to_int(str, B);

    show_big_int(A);
    printf("\n");

    show_big_int(B);
    printf("\n");

    add(A, B, C);

    show_big_int(C);
    printf("\n");

    fclose(fin);

    return 0;
}

void string_to_int(char *str, int num[]) //num = &(A);
{
    int i;
    for (i=0; i<strlen(str); i++) {
        num[i] = str[strlen(str)-i-1] -'0'; //ex.12345->num[0]=1;num[1]=2;.... //str¬O¤@­Óchar
    }
    num[strlen(str)] = END_INT; //ex.12345->num[5]=999
}

void show_big_int(int *num)
{
    if (*num!=END_INT) {
        show_big_int(num+1);
        printf("%d", *num);
    }
}

void add(int num1[], int num2[], int num3[])
{
	int i, j, k, carry;
	i = j = k = 0;
	carry = 0;

	while(num1[i]!=END_INT || num2[j]!=END_INT){
        if(num2[j]==END_INT){
            num3[k] = num1[i] + carry;
            i++;
        }
        else if(num1[i]==END_INT){
            num3[k] = num2[j] + carry;
            j++;
        }
        else{
            num3[k] = num1[i] + num2[j] + carry;
            i++;
            j++;
        }
        carry = num3[k]/10;
        num3[k] = num3[k]%10;
        k++;
	}
	if(carry){
        num3[k] = carry;
        k++;
	}
    num3[k] = END_INT;

}

