/* EE231002 Lab06. Finding Sudoku Solutions
   106061145, Jyun-Wei, Huang
   Date: 2017/10/30
*/

#include <stdio.h>

int mat[9][9];
int storenum[9][9];
int i, j, num;

void readpuzzle(void);
int findnum(void);
int NumAvailable(int row, int col, int num);
void printpuzzle(void);


int main(void)
{
	readpuzzle();
	
	if (findnum())
		printpuzzle();
	else
		printf("no solution");
	return 0;
}


int NumAvailable(int row, int col, int num)
{
	int blockfirstrow = (row / 3) * 3; // the first row of the block
	int blockfirstcol = (col / 3) * 3; // the first column of the block
	
	for (i = 0; i < 9; i++) { // check if num has a duplicate 
		if (mat[row][i] == num) return 0; // has a same num in the row
		if (mat[i][col] == num) return 0; // has a same num in the column
		if (mat[blockfirstrow + (i / 3)][blockfirstcol + (i % 3)] == num) return 0; 
		// has the same num in block
	}
	return 1; // if no duplicate, return 1
}



int findnum()
{	

			int row = 1, col =7;

				do {
					if (col > 0) {
						col--;						
					}
					else if (col == 0) {
						row--;
						col = 8;
						
					}
				} while (storenum[row][col] == 1);
				mat[row][col] = 77;
				return 1;
	
}


void readpuzzle(void)
{

	char ch;

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			scanf(" %c", &ch);
			if (ch == '.') {
				mat[i][j] = 0;
				storenum[i][j] = 0;
			}
			else {
				mat[i][j] = ch - '0';
				storenum[i][j] = 1;
			}
		}
	}
}

void printpuzzle(void)
{
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			printf("%d ", mat[i][j]);
			if ((j + 1) % 3 == 0 && j != 8)
				printf("| ");
			if (j == 8)
				printf("\n");
			if ((i + 1) % 3 == 0 && i != 8 && j == 8)
				printf("------|-------|------\n");
		}
	}
}
