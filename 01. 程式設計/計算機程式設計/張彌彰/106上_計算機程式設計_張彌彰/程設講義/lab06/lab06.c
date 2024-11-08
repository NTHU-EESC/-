/* EE231002 Lab06. Finding Sudoku Solutions
   106061145, Jyun-Wei, Huang
   Date: 2017/10/30
*/

#include <stdio.h>

void readpuzzle(void); // read puzzle finction
int findnum(int row, int col); // find num fuction
int NumAvailable(int row, int col, int num); // test whether num is 
											 // okay to input function
int printpuzzle(void); // print puzzle function

int mat[9][9]; // set up matrix 
int storenum[9][9]; // set up matrix to record if the number is the problem
int total = 0; // total number of solutions



int main(void)
{
	readpuzzle(); // read puzzle
	
	findnum(0, 0); // begin function by input 0, 0
	printf("Total number of solutions found: %d.\n", total); 
	// print total solution
	return 0;
}


int NumAvailable(int row, int col, int num) // test whether num is okay 
											// to input
{
	int blockfirstrow = (row / 3) * 3; // the first row of the block
	int blockfirstcol = (col / 3) * 3; // the first column of the block
	int i; // for loop
	for (i = 0; i < 9; i++) { // check if num has a duplicate 
		if (mat[row][i] == num) return 0; // has a same num in the row
		if (mat[i][col] == num) return 0; // has a same num in the column
		if (mat[blockfirstrow + (i / 3)][blockfirstcol + (i % 3)] == num) 
			return 0; 	// has the same num in block
	}
	return 1; // if no duplicate, return 1
}


int findnum(int row, int col) // fill in blank spaces
{
	int num; // num = 1 to 9
	if (row < 9 && col < 9) { // if row and col are still in the matrix
	
		if (storenum[row][col] == 1) { // if the space is occupied
		
			if (col < 8) return findnum(row, col + 1); 
			// if isn't the last column, move to next space
			else if (row < 8) return findnum(row + 1, 0); 
			// if is the last column, move to next row
			else return printpuzzle();
		}
		
		else { // if the space is not occupied
			for (num = 1; num <= 9; num++) { // select number to input
				if ( NumAvailable(row, col, num) ) { 
				// if the number isn't a duplicate
					mat[row][col] = num; // put num into space

					if (col < 8) { // if isn't the last column
						if (!findnum(row, col + 1)) // recurse function
							mat[row][col] = 0; 
							// if function return 0, it means not available 
							// reset to 0
						else // if function return 1, it means is available
							return 1; 
					}
					
					else if (row < 8) { // if is the last column
						if (!findnum(row + 1, 0)) // recurse function
							mat[row][col] = 0;
							// if function return 0, it means not available 
							// reset to 0
						else // if function return 1, it means is available
							return 1;
					}
					else  // row = 8, col = 8
						return printpuzzle(); 
					// print puzzle, return 0 to previous function
					// pretend that it hasn't found a num
					// to cause recursion
				}
			} 
			return 0; // if 1 to 9 all can't input, 
				      // return 0 to tell function to backtrack
		}
	} else return 1;
}

void readpuzzle(void) // scanf puzzle
{
	int i, j; // for loops
	char ch; // store char

	for (i = 0; i < 9; i++) { // row 
		for (j = 0; j < 9; j++) { // column
			scanf(" %c", &ch); // scan num
			if (ch == '.') { // if scan period
				mat[i][j] = 0; // is 0
				storenum[i][j] = 0; // this is a num we can change
			}
			else { // if scan not period
				mat[i][j] = ch - '0'; // convert to number
				storenum[i][j] = 1; // this is a num we can not change
			}
		}
	}
}

int printpuzzle(void) // print puzzle
{
	total++; // add one to total solution
	printf("Solution %d:\n", total); // print solution number
	int i, j; // for loops
	for (i = 0; i < 9; i++) { // row
		printf("  "); // indentation
		for (j = 0; j < 9; j++) { // column
			printf("%d ", mat[i][j]); // print num
			if ((j + 1) % 3 == 0 && j != 8) // if third column or six column
				printf("| "); // print line
			if (j == 8) // if last column
				printf("\n"); // newline
			if ((i + 1) % 3 == 0 && i != 8 && j == 8) //if third row or six row
				printf("  ------|-------|------\n"); // print line
		}
		
	}
	if (storenum[8][8] == 0) // if the last num is not in the problem
		mat[8][8] = 0; // make last num to 0
	return 0; // return 0 to findnum function
}
