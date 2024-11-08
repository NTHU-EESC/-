// EE231002 Lob08. Finding Sudoku Sloutions
// 111060023, 黃柏霖
// 2022/11/14

#include <stdio.h>

#define N 9

int count = 0;										// count found solution

// to solve sudoku
void solve_sudoku(int A[N][N], int row, int col);
// to determin what can be in A[i][j]
int check(int A[N][N], int i, int j, int num);
// print sudoku
void print_sudoku(int A[N][N]);				

int main(void)
{
	int i, j;										// loop control
	char tmp;										// store char temporary
	int M[N][N] = {0};								// the sudoku
	
	for (i = 0; i < N; i++) {						// read sodoku
		for (j = 0; j < N; j++) {
			scanf("%c ", &tmp);						// store tmp
			// store char to int, and transfer '.' to 0
			M[i][j] = (tmp - '0' == '.' - '0') ? 0 : tmp - '0';
		}		
	}												
	solve_sudoku(M, 0, 0);							// solve sudoku
	printf("Total number of solution found: %d.\n"
		, count);									// print what's demended
	return 0;
}

// to print sudoku
// int A[][]: the sudoku
// return nothing
void print_sudoku(int A[N][N])
{
	int i, j;
	
	// print sudoku as the requirment
	for (i = 0; i < N; i++) {
		printf("  ");
		if (i == 3 || i == 6) printf("------|-------|------\n  ");
		for (j = 0; j < N; j++) {
			if (j == 3 || j == 6) printf("| ");
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
}

// to solve sudoku, count solution, and print it
// int A[N][N]: the sudoku
// 	   row, col: the row and colunm of sudoku
// return nothing
void solve_sudoku(int A[N][N], int row, int col)
{
	int i;

	// find from up-left to down-right
	// if not 0, don't fill in number 
	if (A[row][col] != 0) {
		// found the right if it's still in sudoku
		if (col < 8) solve_sudoku(A, row, col + 1);
		// found the next row if it's still in sudoku
		else if (row < 8) solve_sudoku(A, row + 1, 0);
		// every position is searched
		else {											
			count++;									// new solution found				
			printf("Solution %d:\n", count);
			print_sudoku(A);							// print sudoku
		}
	}
	// if 0, then try which number can fill in
	else {
		for (i = 1; i <= N; i++) {
			if (check(A, row, col, i)) {
				A[row][col] = i;						// try through 1 to 9
				// not searching to the rightmost yet
				if (col < 8) {
					solve_sudoku(A, row, col + 1);		// found the right
					A[row][col] = 0;					// trace back
				}
				// not searching to the downmost yet
				else if (row < 8) {
					solve_sudoku(A, row + 1, 0);		// found the next row
					A[row][col] = 0;					// trace back
				}
				// every position is searched
				else {
					count++;							// new solution found
					printf("Solution %d:\n", count);	
					print_sudoku(A);				 	// print sudoku
					A[row][col] = 0;					// trace back
				}
			}
		}
	}
}

// to check whether the num can be put in A[row][col]
// int A[N][N]: the sudoku
// 	   row, col: the tow and column of sudoku
// 	   num: the number that is checking
// return whether num can be put in
int check(int A[N][N], int row, int col, int num) 
{
	int k;										// loop control
	int cell_x0 = row / 3 * 3;					// the leftmost x of a cell
	int cell_y0 = col / 3 * 3;					// the uppermost y of a cell

	for (k = 0; k < N; k++) {
		if (A[row][k] == num) return 0;			// check row
		if (A[k][col] == num) return 0;			// check column
		if (A[cell_x0 + k % 3][cell_y0 + k / 3] == num)
			return 0;							// check cell
	}
	return 1;									// num is available
}
