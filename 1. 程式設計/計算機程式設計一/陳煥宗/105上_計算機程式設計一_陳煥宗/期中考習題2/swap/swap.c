#include <stdio.h>
#include <stdlib.h>

void swap(char arr[], int count);

int main(void)
{
    char a[100];
    int num;
    int count;
    int i, j, k;

    FILE *fin;

    fin = fopen("swap.txt", "r");
    if (fin==NULL) {
        //perror("swap.txt");
        fprintf(stderr, "sdfgsfafsaffw");
        exit(EXIT_FAILURE);
    }

    fscanf(fin, "%s", a);

    i = 0;
    while((fscanf(fin, "%d", &num))!=EOF){
        swap(a, num);
        printf("%s\n", a);
    }

    return 0;
}
void swap(char arr[], int num)
{
    int i, j, k;
    char tmp[100];

    for(i=0; i<num; i++){
        tmp[i] = arr[i];
    }
    //printf("%s\n",tmp);
    for(i=num; i<strlen(arr); i++){
        arr[i-num] = arr[i];
    }
    //printf("%s\n",arr);
    for(i=0; i<num; i++){
        arr[i+strlen(arr)-num] = tmp[i];
    }
}
