#include<stdio.h>
int ans=0;
int temp=0;
int tmp[8] = {0};
int map[10][10];

int valid(int row, int col);
int place(int row);
void search(void);

int main(void)
{
    int i, j, k;
	int testcase;
	//int map[10][10];
	scanf("%d",&testcase);
	for(i=0;i<testcase;i++){
		for(j=0;j<8;j++){
			for(k=0;k<8;k++){
				scanf("%d",&map[j][k]);
			}
		}
		place(0);
		printf("%d\n",ans);
		ans = temp = 0;
	}
	return 0;
}
int valid(int row, int col)
{
	int i;
	for(i=0;i<=row-1;i++)
		if( tmp[i]==col || row-i==col-tmp[i] || row-i==tmp[i]-col ) return 0;//row-iªí¥Ü¦C®t
    return 1;
}
int place(int row)
{
	int j;
	if(row==8) search();
	else{
		for(j=0;j<8;j++){
			if(valid(row,j)){
				tmp[row] = j;
				place(row+1);
			}
		}
	}
}
void search(void)
{
	int i, j;
	temp = 0;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(tmp[i]==j) temp += map[i][j];
		}
	}
	//ans = (temp>ans) ? temp:ans;
	if(temp>ans) ans = temp;
}



/*#include <stdio.h>
#define NQ 4

int q[NQ] = {0};

void place(int row);
int valid(int row, int col);
void display(void);

int main(void)
{

	place(0);
	return 0;
}


int valid(int row, int col)
{
	int i;
	for (i=0; i<row; i++) {

		if ( q[i] == col || row-i == col-q[i] || row-i == q[i]-col )
		return 0;

	}
	return 1;
}

void display(void)
{
    int i, j;
    for (i=0; i<NQ; i++) {
	    for (j=0; j<NQ; j++) {
	        if (q[i]==j) printf("@");
	        else printf("O");
	    }
	    printf("\n");
	}
	printf("\n");
}

void place(int row)
{
	int j;
	if (row == NQ) {
		display();
	} else {
		for (j=0; j<NQ; j++) {
			if (valid(row, j)) {
				q[row] = j;
				place(row+1);
			}
		}
	}
}
*/
