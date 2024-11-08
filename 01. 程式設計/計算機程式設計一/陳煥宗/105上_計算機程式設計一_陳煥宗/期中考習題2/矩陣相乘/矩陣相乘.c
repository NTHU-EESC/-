#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    double A[10][10] = {0};
    double B[10][10] = {0};
    double C[10][10] = {0};
    int A_r, A_c, B_r, B_c;
    int i, j, k;
    FILE *fin;

    fin = fopen("matrix_data.txt", "r");
    if (fin == NULL) {
        perror("matrix_data.txt");
        exit(EXIT_FAILURE);
    }

    fscanf(fin, "%d%d", &A_r, &A_c);
    for (i=0; i<A_r; i++) {
        for (j=0; j<A_c; j++) {
            fscanf(fin, "%lf", &A[i][j]);
       }
    }

    fscanf(fin, "%d%d", &B_r, &B_c);
    for (i=0; i<B_r; i++) {
       for (j=0; j<B_c; j++) {
          fscanf(fin, "%lf", &B[i][j]);
        }
    }
    fclose(fin);

    /*for(i=0;i<A_r;i++){
        for(j=0;j<B_r;j++){
            for(k=0;k<A_c;k++){
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }*/

    for (i=0; i<A_r; i++) {
       for (j=0; j<B_c; j++) {
            for(k=0;k<A_c;k++) C[i][j] += A[i][k]*B[k][j];
            printf("%5.2f ", C[i][j]);
       }
       printf("\n");
    }

    return 0;
}
