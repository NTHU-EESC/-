/*EE231002 Lab09. Word Processing
  104061212, Li-yu Feng
  Date:2015/11/23
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 1000

int printLine(char *para,int len);

int main(int argc,int *argv[])
{
	int i,j,length;
	char A[5],B[N],C[N]={'\0'},ch;
	
	memcpy(A,argv[1],3);
	if(A[0]=='1' && A[1]=='0')length=100;
	else length=(A[0]-48)*10 + (A[1]-48);
	for(;;){
		/*for(i=0;( ch= getchar() ) != '\n' ;i++)
			B[i] = ch;
		B[i]='\0';*/
		gets(B);
		if(  strncmp ( B , "EOF",3 )==0 )return 0;
		else printLine( B , length );
		memcpy(B,C,sizeof(B));
	}
}

/* the following function print out a paragraph line by line			     *
 * Input: char *para, is the  string  of  a  paragraph, 	 		  	 	 *
 *			 int len, is the number of characters for the first output line. *
 * Output: the paragraph is printed directly using printf or puts, 		     *
 *			 no return value is needed.				      					 *
 * Side effects: the contents of the paragraph can be modified by this		 *
 * 				function.													 */

int printLine(char *para,int len)
{
	char *q=para;
	int i,j,k,space=0,jump=0;
	
	printf("	");
	for(i=0;i<len-4;i++){
		if( *(q+i)=='\n' || *(q+i)=='\0'){
			for(j=0 ; j<i ; j++){
				putchar(*(q+j));
			}
			printf("\n");
			return 0;
		}
	}
	if(*q+len-5==' '){
		i=len-5;			
		do{
			i--;
			*(q+i+1) = *(q+i);
		}while( *q+i != ' ' );
	/*	jump++;*/
	}
	else if( *q+len-4 != ' ')
		for(i = len-5 , space = 1 ; *(q+i) != ' ' ; i-- )
			space++;
	if(*q==' ')q++;
	for( i = 0 ; i < len-4 ; i++ ){
			if( *q == ' ' && space > 0 ){
				putchar(' ');
				space--;
				i++;
			}
			putchar(*q++);
	}
/*	if(!jump){
		q++;
		jump=0;
	}*/
	printf("\n");

	for( k=len-4 ; k<N ;k += len){	
		for(i=0;i<len;i++){
			if( *(q+i)=='\n' || *(q+i)=='\0'){
				for(j=0 ; j<i ; j++){
					putchar(*(q+j));
				}
				printf("\n");
				return 0;
			}
		}
		if(*q+len-1==' '){
			i=len-1;
			do{
				i--;
				*(q+i+1) = *(q+i);
			}while( *q+i != ' ' );
		/*	jump++;*/
		}
		else if( *q+len != ' ')
			for(i = len-1 , space=1 ; *q+i != ' ' ; i-- )
				space++;
		if(*q==' ')q++;
		for( i = 0 ; i < len ; i++ ){
				if( *q == ' ' && space > 0 ){
					putchar(' ');
					space--;
					i++;
					/*printf("%d",i);*/
				}
				putchar(*q++);
		}	
		/*if(!jump){
			q++;
			jump=0;
		}*/
		printf("\n");
	}
}

