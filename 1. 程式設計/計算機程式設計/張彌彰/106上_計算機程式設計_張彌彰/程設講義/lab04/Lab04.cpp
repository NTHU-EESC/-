#include <stdio.h> 
int main(void)
{
	int rn = 0, num1 = 0, num2 = 0;
	char ch;
	
	printf("Input a Roman Numeral: ");
	scanf("%c", &ch);
	
	while (ch != '\n') {
		
		num1 = num2;	
		
		switch (ch) {
			case 'I':
				num2 = 1;
				break;
			case 'V':
				num2 = 5;
				break;
			case 'X':
				num2 = 10;
				break;
			case 'L':
				num2 = 50;
				break;
			case 'C':
				num2 = 100;
				break;
			case 'D':
				num2 = 500;
				break;
			case 'M':
				num2 = 1000;
				break;
		}
		
		if (num1 >= num2)
			rn = rn + num2;
			
		else if (num1 < num2)
			rn = rn + num2 - num1*2;
			
		scanf("%c", &ch);
	} 
	
	printf("The value is: %d", rn);

	return 0;
}
