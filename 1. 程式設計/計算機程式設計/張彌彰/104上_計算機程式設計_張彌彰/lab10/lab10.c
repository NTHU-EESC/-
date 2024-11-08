/* EE231002 Lab10. GCD and LCM
   104061212, Li-Yu Feng
   Date:2015/11/30
*/

#include <stdio.h>

#define S 50

void factorize(int N,int factors[S],int power[S]);
void GCD(int Afactors[S],int Apower[S],int Bfactors[S],int Bpower[S],
		 int Cfactors[S],int Cpower[S]);
void LCM(int Afactors[S],int Apower[S],int Bfactors[S],int Bpower[S],
		 int Cfactors[S],int Cpower[S]);
void write(int factors[S],int power[S]);
void find50prime(void);							// find prime

int prime[S];									//space to store primes found

int main(void)
{
	int A,B,i;
	int Afactors[S]={0},Apower[S]={0},Bfactors[S]={0};
	int Bpower[S]={0},Cfactors[S]={0},Cpower[S]={0};
	
	find50prime();
	printf("input A: ");						//
	scanf("%d",&A);								//
	printf("input B: ");						//
	scanf("%d",&B);								//take input
	factorize(A,Afactors,Apower);				//
	factorize(B,Bfactors,Bpower);				//
	printf("  A = ");							//
	write(Afactors,Apower);						//
	printf("  B = ");							//
	write(Bfactors,Bpower);						//factorization & printing
	GCD( Afactors,Apower,Bfactors,Bpower,Cfactors,Cpower) ;
	printf("  GCD(A,B) = ");
	write(Cfactors,Cpower);						//GCD
	LCM(Afactors,Apower,Bfactors,Bpower,Cfactors,Cpower);
	printf("  LCM(A,B) = ");
	write(Cfactors,Cpower);						//LCM
	return 0;

}

void find50prime(void)
{
	int i,j,p=0;								//i = prime candidate
												//j = test tool
	for(i=2;p<S;i++){
		for(j=2; i%j!=0 && j<i;j++){};
		if(i==j)prime[p++]=i;					//test how did j escape loop?
	}
}

void factorize(int N,int factors[S],int power[S])
{
	int i,j,k=0,Power;

	for(i=0; i < S ;i++){
		for(Power=0; N % prime[i]==0;Power++){	//N divisible by primes?
			N /= prime[i];						//if so , power +1 ,then
		}										//keep dividing by same prime
		if(Power>0){							//
			factors[k]=prime[i];				//record power
			power[k++]=Power;
		}
	}
	factors[k]=1;								//for printing recognition
	power[k]=1;									//
}

void GCD(int Afactors[S],int Apower[S],int Bfactors[S],int Bpower[S],
		 int Cfactors[S],int Cpower[S])
{
	int i,j,k=0;

	for(i=0; Afactors[i] != 1;i++){			//
		for(j=0; Bfactors[j] != 1;j++){		//
			if(Afactors[i]==Bfactors[j]){	//search for same factor
				Cfactors[k]=Afactors[i];
				if (Apower[i] >= Bpower[j]) Cpower[k++]=Bpower[j];
				else Cpower[k++]=Apower[i++];
			}								//if so,record the smaller power
		}

	}
	Cfactors[k]=1;
	Cpower[k]=1;							

}
void LCM(int Afactors[S],int Apower[S],int Bfactors[S],int Bpower[S],
		 int Cfactors[S],int Cpower[S])
{
	int i=0,j=0,k=0;
	
	/* find all prime factors in A & B in ascending order*/
	while( Afactors[i] != 1 && Bfactors[j] != 1 ){
		if( Afactors[i] < Bfactors[j] ){		//record smaller factor first
			Cfactors[k]=Afactors[i];
			Cpower[k++]=Apower[i++];			//record power
		}
		else if( Bfactors[j] < Afactors[i] ){
			Cfactors[k]=Bfactors[j];
			Cpower[k++]=Bpower[j++];
		}
		else{
			Cfactors[k]=Afactors[i];			//if A & B have commom factor
			if( Apower[i] > Bpower[j] ){		//record the bigger power
				Cpower[k++]=Apower[i++];
				 j++;
			}
			else{
				Cpower[k++]=Bpower[j++];
				i++;
			}
		}
	}
	while( Afactors[i] != 1 || Bfactors[j]!= 1 ){	//when Afactors or Bfactors
		if(Afactors[i]==1)							//reaches its end
			while(Bfactors[j] != 1){				
				Cfactors[k]=Bfactors[j];
				Cpower[k++]=Bpower[j++];			//stop comparing
			}										//just record the other one
		else
			while(Afactors[i] != 1){
				Cfactors[k]=Afactors[i];
				Cpower[k++]=Apower[i++];
			}
	}
	Cfactors[k]=1;
	Cpower[k]=1;
}
void write(int factors[S],int power[S])
{
	int i,j,product=1;

	for(i=0;factors[i] > 1;){
		printf("%d",factors[i]);				//print factor
		if (power[i]>1)							//
		printf("^%d",power[i]);					//print power if power > 1
		i++;
		if(factors[i] > 1)printf(" * ");		//print *
		else printf(" ");
	}	
	for(i=0;factors[i] != 1;i++){				//generate value for common case
		for(j=power[i];j>0;j--)product *= factors[i];
	}
	if( factors[0]== 1 ){						//for '1' case
		printf("1\n");
		return;
	}
	printf("= %d",product);
	printf("\n");
}
