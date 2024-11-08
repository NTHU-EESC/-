// EE231002 Lab07. Latin Squares
// 110060007, 黃俊穎
// 2022/01/01

#include <stdio.h>              // I/O library
#if !defined(N)                 // if N isn't defined, N = 3
#define N 3
#endif

char A[N][N];                   // Latin Square is an N * N matrix
int counter;                    // see the matrix is filled by alphabets
int num;                        // total found answer number

// a function creating a new matrix or fill symbols in rest elements
int create_fill(int row, int column, int n);

// a function judging if there are same symbols in that row or column
int decide(int row, int column);

// a function printing out results corresponding with Latin Squares
void print(int n);

int main(void)                  // start main function
{
	create_fill(0, 0, N);       // call function to find all Latin Squares
	// print out total found answer
	printf("Total number of Latin Squares found is %d\n", num);
	return 0;
}

// we use counter to record alphabet number, continue filling in if current 
// symbol is valid, or delete one and try for other alphabet
// until matrix is right, create new valid Latin squares
int create_fill(int row, int column, int n)
{
	int next_row;            // next row with respect to current row
	int next_column;         // next column with respect to current column
	char symb = 'A';         // initialize first symbol
	int i;                   // variable for loop

	if (counter == n * n) {  // decide if matrix is filled up
		print(n);            // print out the result
		num++;               // counter of found answers
	} else {
		for (i = 1; i <= n; i++) {
			A[row][column] = symb;  // input symbol to matrix
			symb++;          // change to next alphabet subsequently
		    counter++;       // if it reach to n * n, print out the
			                 // solution, or alphabet will keep be filled
            // if repeated alphabet in same row and column,
            // alphabets will be filled in same column first
			if (decide(row, column)) {
				next_row = (row + 1) % n;
				next_column = column;
				// if that column is filled up, change column
				if (row == n - 1) {
					next_column = column + 1;
				}
                // if current array is right, create next matrix
				create_fill(next_row, next_column, n);
			}
		    counter--;        // subtract invalid storage number in matrix
		}
	}
}

// check if same row and column occur repeated alphabets respectively
int decide(int row, int column)
{
	int i;                    // variable for loops
	char decide_char;         // record current alphabet

	decide_char = A[row][column];
    // bound same row and check column
	for (i = 0; i < column; i++) {
		if (decide_char == A[row][i]) {
			return 0;
		}
	}
    // bound same column and check row
	for (i = 0; i < row; i++) {
		if (decide_char == A[i][column]) {
			return 0;
		}
	}
	return 1;                 // nothing error then return 1
}

// print out results complying with Latin Squares
void print(int n)
{
	int i, j;

	printf("Latin Square %d:\n", num + 1);

	for (i = 0; i < n; i++) {
		printf(" ");
		for (j = 0; j < N; j++) {
			printf(" %c", A[i][j]);
		}
		printf("\n");
	}
}
