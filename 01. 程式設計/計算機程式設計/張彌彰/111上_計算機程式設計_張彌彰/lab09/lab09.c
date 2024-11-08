// EE231002 Lab09. GCD and LCM
// 111060023, 黃柏霖
// Date: 2022/11/21

#include <stdio.h>

#define S 20

void factorize(int N, int factors[S], int powers[S]);	// to factorize
void GCD(int Afactors[S], int Apower[S], int Bfactors[S], int Bpowers[S],
		 int Cfactors[S], int Cpowers[S]); 				// to find GCD
void LCM(int Afactors[S], int Apower[S], int Bfactors[S], int Bpowers[S],
		 int Cfactors[S], int Cpowers[S]); 				// to find LCM
void write(int factors[S], int powers[S]);				// to print answer
void clean(int array[S]);								// clean array

int main(void)
{
	int N1, N2;									// two numbers
	int fac1[S] = {0}, fac2[S] = {0}, 
		facans[S] = {0};						// factors for N1, N2, answer
	int pow1[S] = {0}, pow2[S] = {0}, 
		powans[S] = {0};						// powers for N1, N2, answer

	printf("input A: ");							// prompt for A
	scanf("%d", &N1);								// get A
	printf("input B: ");							// prompt for B
	scanf("%d", &N2);								// get B
	factorize(N1, fac1, pow1);						// factorize A
	factorize(N2, fac2, pow2);						// factorize B
	printf("  A = ");							
	write(fac1, pow1);								// print factorized A 
	printf("  B = ");
	write(fac2, pow2);							 	// print factorized B
	GCD(fac1, pow1, fac2, pow2, facans, powans); 	// get GCD of A and B
	printf("  GCD(A, B) = ");
	write(facans, powans);							// print factorized (A, B)
	clean(facans);									// clean factors for answer
	clean(powans);									// clean powers for answer
	LCM(fac1, pow1, fac2, pow2, facans, powans);	// get LCM of A and B
	printf("  LCM(A, B) = ");						
	write(facans, powans);							// print factorized [A, B]
	return 0;
}


// To factorize an integer
// input: int N is the integer to be factorized
// 		  int factors[S] stores the factors
// 		  int power[S] stores the power of each factor
// 		  return: no return
void factorize(int N, int factors[S], int powers[S])
{
	int fac = 2;									// factors
	int k = 0;										// index for arrays

	while (N > 1) {									// searching when N > 1
		while (N % fac == 0) {						// when fac can devide N
			factors[k] = fac;						// store fac
			powers[k]++;							// add one to the power
			N /= fac;								// eliminate fac from N
		}
		fac++;										// find next factor
		if (powers[k] != 0) k++;					// find the next facctor
	}
	factors[k] = 1;									// the final factor is 1
	powers[k] = 1;									// the power for 1 is 1
}	

// To compute GCD of given two numbers
// input: Afactors[s] and Apowers[S] are factors and powers for integer A
// 		  Bfactors[s] and Bpowers[S] are factors and powers for integer B   
// 		  Cfactors[s] and Cpowers[S] are factors and powers for GCD(A, B)
// return: no return
void GCD(int Afactors[S], int Apowers[S], int Bfactors[S], int Bpowers[S],
		 int Cfactors[S], int Cpowers[S])
{
	int i, j;										// loop control
	int k = 0;										// index for array

	for(i = 0; Afactors[i] != 1; i++) {				// searching until 1
		for (j = 0; Bfactors[j] != 1; j++) {		// searching until 1
			if (Afactors[i] == Bfactors[j]) {		// have the same factor
				Cfactors[k] = Bfactors[j];			// store the factor
				Cpowers[k] = Apowers[i] < Bpowers[j] ? 
					Apowers[i] : Bpowers[j];		// find the bigger power
				k++;								// store the next
			}
		}
	}
	Cfactors[k] = 1; 								// the final factor is 1
	Cpowers[k] = 1; 								// the power for 1 is 1
}

// To compute LCM of given two numbers
// input: Afactors[s] and Apowers[S] are factors and powers for integer A
// 		  Bfactors[s] and Bpowers[S] are factors and powers for integer B   
// 		  Cfactors[s] and Cpowers[S] are factors and powers for LCM(A, B)
// return: no return
void LCM(int Afactors[S], int Apowers[S], int Bfactors[S], int Bpowers[S],
		 int Cfactors[S], int Cpowers[])
{
	int i = 0;										// index for A
	int j = 0;										// index for B
	int k = 0;										// index for C

	while (Afactors[i] > 1 || Bfactors[j] > 1) {	// search all factors > 1
		// Store A to C if 1. A's factor is not 1 but smaller than B's factor
		// 				   2. all factors of B is found
		if ((Afactors[i] < Bfactors[j] && Afactors[i] > 1)	
			|| (Afactors[i] > 1 && Bfactors[j] == 1)) {
			Cfactors[k] = Afactors[i];
			Cpowers[k] = Apowers[i];
			i++;									// go to next A
			k++;									// store the next
		}
		// Store B to C if 1. B's factor is not 1 but smaller than A's factor
		// 				   2. all factors of A is found
		else if ((Afactors[i] > Bfactors[j] && Bfactors[j] > 1)
				|| (Bfactors[j] > 1 && Afactors[i] == 1)){
			Cfactors[k] = Bfactors[j];
			Cpowers[k] = Bpowers[j];
			j++;									// go to next B
			k++;									// store the next
		}
		// if A's factor is as big as B's factor, store A factor
		// and store the one which has bigger power
		else {
			Cfactors[k] = Afactors[i];		
			Cpowers[k] = Apowers[i] > Bpowers[j] ? 
				Apowers[i] : Bpowers[j];
			i++;									// go to next A
			j++;									// go to next B
			k++;									// store the next
		}
	}
	Cfactors[k] = 1;								// the final factor is 1
	Cpowers[k] = 1;									// the power for 1 is 1
}

// To print factors and power of an integer
// input: int factors[S] are the factors of the integer
// 		  int power[S] are the power of each factors
// return: no return
// output: factors and powers of an integer and the integer itself
void write(int factors[S], int powers[S])
{
	int i, j;										// loop control
	int parts = 1;									// store factor^power
	int product = 1;								// multiple of all parts
	
	// print 1 directly if it's one
	if (factors[0] == 1) {							
		printf("1 = 1\n");
		return;
	}
	// print factors and power in a form of factor^power
	for (i = 0; factors[i] != 1; i++) {
		if (i == 0) printf("%d", factors[i]);
		else printf(" * %d", factors[i]);
		if (powers[i] > 1) printf("^%d", powers[i]);	// print power if > 1
		for (j = 0; j < powers[i]; j++) {				// compute parts
			parts *= factors[i];
		}
		product *= parts;								// compute product
		parts = 1;										// initialize it
	}
	printf(" = %d\n", product);
}

// Clean all elements in given array to 0
// input: int factors[S] is the array should be cleaned
// return: no return
void clean(int array[S])
{
	int i;

	for(i = 0; i < S; i++) array[i] = 0;				// turn elements to 0
}
