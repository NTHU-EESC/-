/*EE231002 Lab04. Deciphering Roman numerals
 *104061212,Li-yu,Feng
 *Date:10/19
 */

#include <stdio.h>

int main(void)
{
	int A,B;
	int sum;
	sum=0;

	printf("Input a Roman Numeral:");
	for(B=5000;;){							//SET B EQUALS A LARGE NUMBER
		A=getchar();						//such that A<=B initially
		if(A==10) break;					//read /n(10 in ASCII),end loop
	
		switch (A){							//FROM ASCII   TO ROMAN
			case 73:A=1;break;				//I=73			I=1
			case 86:A=5;break;				//V=86			V=5
			case 88:A=10;break;				//X=88			X=10
			case 76:A=50;break;				//L=76			L=50
			case 67:A=100;break;			//C=67			C=100
			case 68:A=500;break;			//D=68			D=500
			case 77:A=1000;break;			//M=77			M=1000
			default:A=999;					//detect wrong format 
		}
		if(A==999){									//
		printf("You typed a wrong format!\n");		//
		return 0;									//detect wrong format
		}
		if(A<=B)						//right <= left sum += right
			sum += A;
		else							//right > left sum +=right-left
			sum += A-2*B;				//then minus former-added left
		
		B=getchar();
		if(B==10) break;
		switch (B){
			case 73:B=1;break;
			case 86:B=5;break;
			case 88:B=10;break;
			case 76:B=50;break;
			case 67:B=100;break;
			case 68:B=500;break;
			case 77:B=1000;break;
			default:B=999;
		}
		if(B==999){
		printf("You typed a wrong format,哈哈哈!\n");
		return 0;
		}
		if(B<=A)
		sum+=B;
		else
		sum+=B-2*A;
	}
	printf("The value is:%d\n",sum);

	return 0;
}

