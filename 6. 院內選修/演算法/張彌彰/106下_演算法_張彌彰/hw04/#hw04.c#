/*****************************************
  EE3980 Algorithms HW04 Trading Stock, II
  Li-Yu Feng 104061212
  Date:2018/4/1
******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct sSTKprice {		//store date, price & price change
	int year,month,day;
	double price,change;
} STKprice;

typedef struct retval{	//store low, high index and the maximum sum between
	int low, high;		//for convenient return
	double sum;
} RETval;

double GetTime(void);
void MaxSubArrayBF(STKprice *A, int n);					//Brute-force method
RETval MaxSubArray(STKprice *A, int begin, int end);	//D & C method
RETval MaxSubArrayXB(STKprice *A, int begin, int mid, int end); 
													//cross boundary 
RETval MaxSubArrayFast(STKprice *A, int n);			//linear complexity
void PrintResult(STKprice *A, RETval result, double time,int flag);  //as its name

double GetTime(void)
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec+1e-6*tv.tv_usec;
}

void MaxSubArrayBF(STKprice *A, int n){
	double max = 0, sum;
	double t;				//time
	int low = 0, high = n-1;
	int i,j,k;

	t = GetTime();			
	for (j = 0; j < n; j++){		//try all n(n-1)/2 possible situations
		for (k = j; k < n; k++){
			sum = A[k].price - A[j].price;	// n^2 complexity version
			//sum = 0;
			//for(i = j; i <= k; i++){
			//	sum += A[i].change;
			//}								//n^3 version
			if(sum > max){
				max = sum;
				low = j + 1 ;				//Note: for alignment in printing 
				high = k;					//process
			}
		}
	}
	t = GetTime() - t;

	//print result
	printf("Brute-force approach:\n");
	printf("  CPU time %.3g s\n", t);
	if(low != 0)printf("  Buy: %d/%d/%d at $%g\n",A[low-1].year,
					A[low-1].month,A[low-1].day,A[low-1].price );
	else printf("  Buy: %d/%d/%d at $%g\n",A[0].year,
					A[0].month,A[0].day,A[0].price );
	printf("  Sell: %d/%d/%d at $%g\n",A[high].year,A[high].month,
										A[high].day,A[high].price );
	printf("  Earning: $%g per share.\n",max);
}


RETval MaxSubArray(STKprice *A, int begin, int end){

	int mid;
	RETval Ans,lret,rret,xret;		//store return values from divided aprts
	double lsum,rsum,xsum;

	if(begin == end){
		Ans.low = begin;
		Ans.high = end;
		Ans.sum = A[begin].change;
		return Ans;
	}
	mid = (begin + end) / 2;
	lret = MaxSubArray(A,begin,mid);
	rret = MaxSubArray(A,mid+1,end);
	xret = MaxSubArrayXB(A,begin,mid,end);

	lsum = lret.sum;
	rsum = rret.sum;
	xsum = xret.sum;

	if(lsum >= rsum && lsum >= xsum){ //left side returns maximum
		Ans.low = lret.low;
		Ans.high = lret.high;
		Ans.sum = lsum;
	}
	else if (rsum >= xsum){			//right side
		Ans.low = rret.low;
		Ans.high = rret.high;
		Ans.sum = rsum;
	}
	else{							//cross boundary
		Ans.low = xret.low;
		Ans.high = xret.high;
		Ans.sum = xsum;
	}
	return Ans;
}

RETval MaxSubArrayXB(STKprice *A, int begin, int mid, int end){
	double lsum = 0,rsum = 0;
	int low = mid;
	int high = mid + 1;
	double sum = 0;
	int i;
	RETval Ans;

	for(i = mid; i >= begin; i--){		//find left side max sum
		sum = sum + A[i].change;
		if(sum > lsum){
			lsum = sum;
			low = i;
		}
	}
	sum = 0;
	for(i = mid + 1; i <= end; i++){	//find at right side
		sum = sum + A[i].change;
		if(sum > rsum){
			rsum = sum;
			high = i;
		}
	}

	Ans.low = low;
	Ans.high = high;
	Ans.sum = lsum + rsum;
	return Ans;
}

void PrintResult(STKprice *A, RETval result, double time, int flag){
	int low = result.low;
	int high = result.high;
	double sum = result.sum;

	if(flag == 1)	printf("Divide and Conquer approach:\n");
	else printf("Fast approach:\n");
	printf("  CPU time %.3g s\n", time);
	if(low != 0)printf("  Buy: %d/%d/%d at $%g\n",A[low-1].year,	//to avoid 
					A[low-1].month,A[low-1].day,A[low-1].price );	//segfault
	else printf("  Buy: %d/%d/%d at $%g\n",A[0].year,
					A[0].month,A[0].day,A[0].price );
	printf("  Sell: %d/%d/%d at $%g\n",A[high].year,A[high].month,
										A[high].day,A[high].price );
	printf("  Earning: $%g per share.\n",sum);

}

RETval MaxSubArrayFast(STKprice *A, int n){
	double sum = 0;
	int temp_start = 0;
	int i;
	RETval Ans;

	Ans.sum = 0;
	Ans.low = 0;
	Ans.high = 0;
	
	for (i = 0; i < n; i++){
		sum +=A[i].change;

		if (sum < 0){
			sum = 0;
			temp_start = i+1;
		}						//restart record

		if (sum > Ans.sum){
			Ans.sum = sum;
			Ans.low = temp_start;
			Ans.high = i;		//update record
		}
	}
	return Ans;
}



int main()
{
	int Ndays;
	int i;
	double t;
	STKprice *Prices;
	RETval result;

	scanf("%d",&Ndays);
	Prices = malloc(Ndays * sizeof(STKprice));
	
	for ( i = 0; i < Ndays; i++){
		scanf(" %d %d %d %lf", &Prices[i].year, &Prices[i].month, 
								 &Prices[i].day, &Prices[i].price );
	}

	Prices[0].change = 0;		//calculate the price changes				
	for ( i = 1; i < Ndays; i++)
		Prices[i].change = Prices[i].price - Prices[i-1].price;


	printf("N = %d\n",Ndays );
	MaxSubArrayBF(Prices,Ndays);
	
	t = GetTime();
	for ( i = 0; i < 1000; i++)
	{
		result = MaxSubArray(Prices,0,Ndays-1);
	}
	t = GetTime() - t;
	PrintResult(Prices,result,t/1000, 1);

	t = GetTime();
	for ( i = 0; i < 1000; i++)
	{
		result = MaxSubArrayFast(Prices,Ndays);
	}
	t = GetTime() - t;
	PrintResult(Prices,result,t/1000, 2);

	
	return 0;
}





