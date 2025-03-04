#include <stdio.h>
#define MAXNV 5
int values[MAXNV];
int numbers[MAXNV];  //錢幣數量

void show(int nv);
void change(int amount, int smallest, int nv);

int main(void)
{
	int nv, i;   //nv為錢幣的種類數量
	int money;
	scanf("%d", &nv);
	if (nv>MAXNV || nv<1) return 0;
	for (i=0; i<nv; i++) {
		scanf("%d", &values[i]);   //錢幣的面額大小
	}
    scanf("%d", &money);
	change(money, 0, nv);

	return 0;
}

void show(int nv)
{
    int i;
	printf("(%d", numbers[0]);
	for (i=1; i<nv; i++) {
		printf(",%d", numbers[i]);
	}
	printf(")\n");
}

void change(int amount, int smallest, int nv)
{
	if (smallest<nv) {
		if (amount == 0) {
			show(nv);
		} else if (amount > 0) {
			change(amount, smallest+1, nv);
			numbers[smallest]++;
			change(amount-values[smallest], smallest, nv);
			numbers[smallest]--;
		}
	}
}
