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

/*void add(int num1[], int num2[], int num3[])
{
    int i = 0;
    while(i<99999990){
        if((*num1!=END_INT)&&(*num2==END_INT)){
            num3[i] += (num1[i])%10;
            num3[i+1] += (num1[i])/10;
            i++;
        }
        else if((*num1==END_INT)&&(*num2!=END_INT)){
            num3[i] += (num2[i])%10;
            num3[i+1] += (num2[i])/10;
            i++;
        }
        else if((*num1==END_INT)&&(*num2==END_INT)){
            return ;
        }
        else if((*num1!=END_INT)&&(*num2!=END_INT)){
            num3[i] += (num1[i]+num2[i])%10;
            num3[i+1] += (num1[i]+num2[i])/10;
            i++;
        }
    }
}*/

void add(int num1[], int num2[], int num3[])
{
	int i,n1,n2;
	i=0;
	while (num1[i]!=END_INT) i++;
	n1=i;

	i=0;
	while (num2[i]!=END_INT) i++;
	n2=i;

	if(n1>n2){
		num2[n2]=0;
		for(i=0;i<n1;i++){
			num3[i]=num3[i]+num2[i]+num1[i];
			if(num3[i]>9){
				num3[i]=num3[i]%10;
				num3[i+1]=1;
			}
		}
		if(num3[n1]==0)	num3[n1]=END_INT;
		else num3[n1+1]=END_INT;
	}
	else{
		num1[n1]=0;
		for(i=0;i<n2;i++){
			num3[i]=num3[i]+num2[i]+num1[i];
			if(num3[i]>9){
				num3[i]=num3[i]%10;
				num3[i+1]=1;
			}
		}
		if(num3[n2]==0)	num3[n2]=END_INT;
		else num3[n2+1]=END_INT;
	}
}
