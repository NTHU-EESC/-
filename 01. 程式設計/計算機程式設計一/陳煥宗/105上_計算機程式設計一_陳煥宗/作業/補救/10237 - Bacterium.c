#include <stdio.h>
int devide2(int week);
int main(void){
	int n_week;

	scanf("%d", &n_week);
	printf("%d\n", devide2(n_week));
	return 0;
}

int devide2(int week){
	if(week == 1)
		return 1;
	else if(week == 2)
		return 2;
	else if(week == 3)
		return 4;
	else return devide2(week-1)+devide2(week-2);

}
