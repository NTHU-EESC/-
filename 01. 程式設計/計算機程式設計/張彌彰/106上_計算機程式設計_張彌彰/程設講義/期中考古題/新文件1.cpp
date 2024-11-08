#include <stdio.h>	//declare the header

int main(void)		//the start of the function
{	
	char A[9];
	int i;
	
	for (i=0; i<9; i++){
		scanf("%c", &A[i]);
	}
	
	if (A[0]=='1'&&A[1]=='0'&&(A[2]<='6')&&(A[3]<='1')&&(A[4]=='6')){
		switch(A[5]) {
			case '1': printf("Department of Electrical Engineering\n"); break;
			case '2': printf("Department of Computer Science\n");break;
			case '3': printf("Institute of Electronics Engineering\n");break;
			case '4': printf("Institute of Communications Engineering\n");break;
			case '5': printf("Institute of Information Systems and Applications\n");break;
			case '6': printf("Institute of Photonic Technologies\n");break;
			default: printf("\"Non-EECS student.\n\"");
		}
			
	}
	else printf("\"Non-EECS student.\n\"");
	return 0;
}
