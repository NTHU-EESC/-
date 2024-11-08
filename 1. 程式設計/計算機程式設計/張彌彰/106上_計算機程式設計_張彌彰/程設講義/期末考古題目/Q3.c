// Q3 u105061245 蕭郁澄
// Given an m X n integer matrix, A[i][j], 1 <= i <= m and 1 <= j <= n,
// please find the smallest element of the matrix and return its value.
// For example, if
//     int A[2][3] = { {1, 2, 3},
//                     {4, 5, 6}};
// then min(A,2,3) returns 1.
//

#include <stdio.h>
#define m 2
#define n 3

int min(int A[m][n])
{
	int min=A[0][0];	// assume min is A[0][0]. 
	int i,j;			// index variables.

	for ( i=0 ; i<m ; i++ ){
		for ( j=0 ; j<n; j++){
			if ( A[i][j] < min ){	
			// if A[i][j] is smaller than min, then assign A[i][j] to min.
				min = A[i][j];
			}
		}
	}
	return min;
}

