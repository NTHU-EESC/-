#include <stdio.h>
#include <stdlib.h>

int main()
{
float a,b,c,d;

printf("Please type the temperature in Celsius scale.\n");

scanf("%f %f", &a,&c);

printf("%f \n", a, c);

b = 9.0/5.0*a+32.0;
d = 9/5*c+32;

printf("the temperature in Fahrenheit scale is %f.\n", b);
printf("wrong one is %f.\n",d);

system("pause");

return 0;
}
