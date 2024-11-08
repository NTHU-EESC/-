// Q3 u104061212 馮立俞
// Please write a function to read a set of positive integers into an array A.
// The number of the integers to be read is unknown when the function is
// called. It is known that a negative integer terminates the reading process.
// Due to the unknown size, the array A is declared as a global int pointer.
// The function returns the number of data read, excluding the negative
// integer.
//
// Note that you should pay attention to the space efficiency.

#include <stdio.h>
#include <stdlib.h>

int *A;

int readData(void)
{	
	int i,Nread=0;	//Nread : Numbers read

	A=(int *)malloc(sizeof(int));
	scanf("%d",&i);
	while(i >= 0){
		*A++ = i;
		Nread++;
		scanf("%d",&i);
		A=(int *)malloc(sizeof(int));
	}
	free(A);		//avoid memory leak
	return Nread;
}
