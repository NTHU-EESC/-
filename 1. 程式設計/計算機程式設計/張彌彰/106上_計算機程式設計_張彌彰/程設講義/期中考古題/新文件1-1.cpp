#include <stdio.h>	//declare the header

int main(void)		//the start of the function
{
	int a,b,c,d,e,f,g,h,i;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	scanf("%d", &d);
	scanf("%d", &e);
	scanf("%d", &f);
	scanf("%d", &g);
	scanf("%d", &h);
	scanf("%d", &i);
	if (a==1&&b==0&&(c<=6)&&(d<=1)&&(e==6)){
		switch(f) {
			case 1: printf("Department of Electrical Engineering\n"); break;
			case 2: printf("Department of Computer Science\n");break;
			case 3: printf("Institute of Electronics Engineering\n");break;
			case 4: printf("Institute of Communications Engineering\n");break;
			case 5: printf("Institute of Information Systems and Applications\n");break;
			case 6: printf("Institute of Photonic Technologies\n");break;
			default: printf("\"Non-EECS student.\n\"");
		}
			
	}
	else printf("\"Non-EECS student.\n\"");
	return 0;
}
	
