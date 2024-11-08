/*EE231002 Lab01 Currecy Exchange
 *104061212 , Li-Yu,Feng
 *Date:2015/9/21
 */


#include <stdio.h>
int main(void)

{                                	  //function start
	float y;	     	  	  //USD input
	float x;	    		  //NTD required			
	printf("USD to buy: ");  	  //demonstrate "USD to buy"	
	scanf("%f",&y);
	x=32.57*y+100;	     		  //do the math
	printf("NTD required =%.2f\n",x); //demonstrate the exact NTD required
	return 0; 			   		  //fuction end


