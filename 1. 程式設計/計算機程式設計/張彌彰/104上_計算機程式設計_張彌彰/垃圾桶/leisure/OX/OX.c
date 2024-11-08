#include<stdio.h>
#include<stdlib.h>



void print_all(int *A);
char printOX(int i);

int	main(){

	int A[3][3];
	int *p;
	int i,j;
	int R,C;

	for(i = 0;i<3;i++)
		for(j=0;j<3;j++)
			A[i][j] = 0;	//space
	A[1][1] = -1;			// "X"

	p = &A[0][0];
	print_all(p);

	print_all(p);

	
	return 0;
}



void print_all(int *A)
{
	int i,j,k;
	int R,C;
	
	for(i=0,j=0,k=0;i<5;i++){
			if(i%2 == 0){
				printf("	%c|",printOX(*(A + j + k ) ));	k++;
				printf("%c|",printOX(*(A + j+ k ) )	   );	k++;
				printf("%c\n",printOX(*(A + j + k))    );	
				j += 3;	k = 0;
			}
			else	printf("	_____\n");
	}

	printf("Where do you want to place 'O' ?( row & column )\n");
	scanf("%d%d",&R,&C);
}

char printOX(int i)
{
	switch(i){
		case -1:	return'X';	break;
		case  1:	return'O';	break;
		default:	return' ';
	}
}
