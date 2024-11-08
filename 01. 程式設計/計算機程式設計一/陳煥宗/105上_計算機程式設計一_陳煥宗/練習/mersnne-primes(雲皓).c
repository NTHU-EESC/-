#include<stdlib.h>
#include<stdio.h>

int mersenne_prime(int k)
{
	int t=1,num=2;
    while (t!=k){
        num *= 2;
        t++;
        if (t == k) break;
    }
	return num - 1;
}
int is_it_prime(num)
{
	int i=2,flag=1;
	while (num > i){
		if (num%i == 0){
			flag = 0;
			break;
		}
		i++;
	}
	return flag;
}
void main(void)
{
	int i=2,time=1;
	while (1){
		int mersenne_prime(i);
		int is_it_prime(mersenne_prime(i));
		if (is_it_prime(i) == 1){
				printf("%d\n", mersenne_prime(i));
				time++;
        }
		i++;
		if (time == 9) break;
	}
	system("pause");
}
