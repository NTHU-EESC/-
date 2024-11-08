#include<stdio.h>
int main(void)
{
    unsigned long num, div;
    int isPrime;

    printf("Please enter an integer (q to quit): \n");
    while(scanf("%lu",&num)==1){
        for(div=2, isPrime=1; (div*div)<=num; div++){
            if(num%div==0){
                if((div*div)!=num) printf("%lu, %lu, ", div, num/div);
                else printf("%lu, ",div);
                isPrime = 0;
            }
        }
        if(isPrime) printf("%lu is prime.\n", num);
        else printf("\b\b are divisors of %lu\n", num);
        printf("Please enter another integer (q to quit): \n");
    }
    printf("Bye.\n");
    return 0;
}
