/*EE231002 Lab02 Currency Exchange, II
 *104061212, Li-Yu,Feng
 *Date:104/10/5
 */


#include <stdio.h>

int main(void)

{
	int X,A,a,B,b,C,c,D,d,E,e,F,f,G,g,H,h;

	printf("Enter USD amount:");
	scanf("%d",&X);			//USD amount input

	A=X/1000;				//X's Quotient of 1000
	a=X%1000;				//X's remainder of 1000
	B=a/100;				//divide the previous remainder again by 50
	b=a%100;				//calculate the remainder for next division
	C=b/50;
	c=b%50;
	D=c/20;
	d=c%20;
	E=d/10;
	e=d%10;
	F=e/5;
	f=e%5;
	G=f/2;					//Math done
	g=f%2;					//(variations with Capital=values to be shown below)

	printf("To pay:\n");	//show "To pay"
	switch(A){				//A for 1000 bill
		case 0:break;		//skip sowing value if the quoptient is 0
		case 1: printf(" %d 1000 bill\n",A); break;//show "bill"should the
												   //value	be 1	
		default:printf(" %d 1000 bills\n",A);		//otherwise,show exact
		 											//value with bill"s"
	};
	switch(B){										//B for 100 bill
		case 0:break;
		case 1:printf(" %d $100 bill\n",B); break;
		default:printf(" %d $100 bills\n",B);
	};
	switch(C){										//C for 50 bill
		case 0:break;
		case 1:printf(" %d $50 bill\n",C); break;
		default:printf(" %d $50 bills\n",C);
	};
	switch(D){
		case 0:break;
		case 1:printf(" %d $20 bill\n",D); break;
		default:printf(" %d $20 bills\n",D);
	};
	switch(E){
		case 0:break;
		case 1:printf(" %d $10 bill\n",E); break;
		default:printf(" %d $10 bills\n",E);
	};
	switch(F){
		case 0:break;
		case 1:printf(" %d $5 bill\n",F); break;
		default:printf(" %d $5 bills\n",F);
	};
	switch(G){
		case 0:break;
		case 1:printf(" %d $2 bill\n",G); break;
		default:printf(" %d $2 bills\n",G);
	};
	switch(g){
		case 0:break;
		case 1:printf(" %d $1 bill\n",g); break;
		default:printf(" %d $1 bills\n",g);
	};
	return 0;
}
