// Q1 u104061212 馮立俞
// Given an int array A[N] of N elements, it is known all elements of A are
// in the range 1 <= A[i] <= 9. Please write a function, Ngreater(A,k),
// that returns the number of elements which are larger than k.
//
// For example, if A[10] = { 1, 2, 3, 2, 2, 1, 4, 5, 5, 3}, then
//    Ngreater(A,3)=3   and   Ngreater(A,4)=2.
//

#define N 10
int Ngreater(int A[N],int k)
{
	int i,count;
	for(i=0;i<N;i++){
		if(A[i]>k)
		count++;
	}
	return count;
}
