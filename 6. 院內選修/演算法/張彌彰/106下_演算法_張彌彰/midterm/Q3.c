// Q3 104061212 馮立俞
// GOOGLE stock 2-buy-2-sell max earning
#include<stdio.h>
#include<stdlib.h>


typedef struct sSTKprice{
	int year, month,day;
	double price, change;
} STKprice;

typedef struct retval{	//store low, high index and the maximum sum between
	STKprice low, high;		//for convenient return
	double sum;
} RETval;

typedef struct candidate{
	RETval left, right;
	double earning;
} Candidate;

RETval MaxSubArrayFast(STKprice *A, int n){
	double sum = 0;
	int temp_start = 0;
	int i;
	RETval Ans;

	Ans.sum = 0;
	Ans.low = A[0];
	Ans.high = A[0];
	
	for (i = 0; i < n; i++){
		sum +=A[i].change;

		if (sum < 0){
			sum = 0;
			temp_start = i+1;
		}

		if (sum > Ans.sum){
			Ans.sum = sum;
			if(temp_start == 0)Ans.low = A[temp_start];
			else Ans.low = A[temp_start-1];
			Ans.high = A[i];
		}
	}
	return Ans;
}


int main(){
	int Ndays;
	STKprice *Prices;
	int i,j;
	double max;
	RETval temp1, temp2;
	Candidate *C;
	
	scanf("%d", &Ndays);
	Prices = malloc( Ndays * sizeof(STKprice));
	C = malloc(Ndays * sizeof(Candidate));

	for (i = 0; i < Ndays; i++){
		scanf("%d %d %d %lf, ", &Prices[i].year, &Prices[i].month, &Prices[i].day,
								&Prices[i].price);
	}
	Prices[0].change = 0;
	for(i = 1; i< Ndays; i++)
		Prices[i].change = Prices[i].price - Prices[i-1].price;	

	temp1 = MaxSubArrayFast(Prices, Ndays);
	printf("global max:%g\n", temp1.sum);
	printf("%d/%d/%d\n", temp1.low.year, temp1.low.month, temp1.low.day);
	printf("%d/%d/%d\n", temp1.high.year, temp1.high.month, temp1.high.day);
	


	for(i = 0 ; i< Ndays; i++){
		temp1 = MaxSubArrayFast(Prices, i);
		temp2 = MaxSubArrayFast(&Prices[i], Ndays - i);
		C[i].left = temp1;
		C[i].right = temp2;
		C[i].earning = temp1.sum + temp2.sum;
	}

	max = 0;
	for(i = 0; i < Ndays; i++){
		if(C[i].earning > max){
			max  = C[i].earning;
			j = i;
		}
	}
	printf("%d /%d/ %d %g\n%d / %d / %d %g\n", 
		C[j].left.low.year, C[j].left.low.month, C[j].left.low.day, C[j].left.low.price,
		C[j].left.high.year, C[j].left.high.month, C[j].left.high.day, C[j].left.high.price);
	printf("%d /%d/ %d %g\n%d / %d / %d %g\n", 
		C[j].right.low.year, C[j-1].right.low.month, C[j].right.low.day, C[j].right.low.price,
		C[j].right.high.year, C[j].right.high.month, C[j].right.high.day, C[j].right.high.price);
	printf("total : %g\n",C[j].earning );
}
