#include <stdio.h>

int main(int argc,char *argv[])
{
	char p[999];
	int i;
	/*char *q=argv;*/
	
	printf("argc=%d\n",argc);
/*	puts(q);*/
	printf("\n");
	for(i=0;i<50;i++)
/*	printf("argv[%d]=%c\n",i,*argv[i]);*/
	;
	gets(p);
	/*scanf("%s",p);*/
	puts(p);
	return 0;
}
