#include <stdio.h>
int mat[9] = {3, 6, 1, 0, 0, 4, 0, 0, 0};
int i,  total = 0;
int findnum(int row);
int numavail(int row, int num);
int storenum[9] = {1, 1, 1, 0, 0, 1, 0, 0, 0};


int main(void)
{
	findnum(0);
	
	
	return 0;
}

int findnum(int row) 
{
	int num;
	if (row<9){
		if (storenum[row] == 1) {
			return findnum(row+1);  //row 0 to 1 to 2 to 3 // 5 to 6
		}
		else {
			for (num = 1; num < 10; num++) {
				
				if (numavail(row, num)) {
					mat[row] = num;
					if (!findnum(row+1)) // 3 to 4 to 5 // 6 to 7 // 7 to 8 // return 0, mat7 = 0 // 
						mat[row] = 0;
					
					else
						return 1;
				}
				
			}return 0; // if 1 - 9 can't input, return 0 to last if(!findnum) to make last mat[row] = 0, in order to run for to the next num 
		}
		
	} 
	else {
		total++;
		printf("solution %d\n", total);
		for (i = 0; i<9; i++) {
			printf("%d", mat[i]);
		}
		
		
	return 1; // from (!findnum(row+1)), if row is 9, means all num found, MUST return 1 to last (!findnum(row+1))
	}
}

int numavail(int row, int num)
{	

	if ( (row == 8 && num == 9) || (row==7 &&num == 9) )
		return 0;
		
	for (i = 0; i < 9; i++) {
		if (mat[i] == num) return 0;

	} 
	return 1;


}
