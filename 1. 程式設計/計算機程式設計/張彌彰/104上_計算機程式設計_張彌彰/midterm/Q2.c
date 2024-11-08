// Q2 u104061212 馮立俞
// Given a char array A[N] of N elements, please write a function to rotate
// array A to the left by one position.
//
// For example, if A[7] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g'}  then
// after calling Lrotate(A) we have
// A[] = {'b', 'c', 'd', 'e', 'f', 'g', 'a'}.
//

#define N 7
int Lrotate(char A[N])
{
	int i;
	char temp;
	
	temp=A[0];						//save A[0]'s value
	for(i=0;i<N-1;i++){						
		A[i]=A[i+1];				//assign the left with  the right	
	}
	A[N-1]=temp;					//assign the last one with A[0]
	return 0;
}

