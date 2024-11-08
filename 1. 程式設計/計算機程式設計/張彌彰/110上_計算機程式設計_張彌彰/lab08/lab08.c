// EE231002 Lab08. GCD and LCM
// 110060007, 黃俊穎
// 2021/11/29

#include <stdio.h>                   // I/O library
#define S 20                         // size of array

// find out number's factors and powers and save them into two arrays
void factorize(int N, int factors[S], int power[S]);

// take two numbers' arrays of factors and powers to produce Greatest
// Common Divisor
void GCD(int Afactors[S], int Apower[S], int Bfactors[S], int Bpower[S],
         int Cfactors[S], int Cpower[S]);

// take two numbers' arrays of factors and powers to produce Least
// Common Multiple
void LCM(int Afactors[S], int Apower[S], int Bfactors[S], int Bpower[S],
         int Cfactors[S], int Cpower[S]);

// print out results of factors and powers by product form
void write(int factors[S], int power[S]);

int main(void)
{
	int A, B;                         // two input positive integers
	int Afactors[S], Apower[S];       // factorized A
	int Bfactors[S], Bpower[S];       // factorized B
	int Cfactors[S], Cpower[S];       // GCD or LCM of A and B

	printf("input A: ");              // prompt to input an integer
	scanf("%d", &A);                  // read it as A
	printf("input B: ", B);           // prompt to input an integer
	scanf("%d", &B);                  // read it as B

	factorize(A, Afactors, Apower);   // factorize A
	printf("  A = ");                 // print out factorized result of A
	write(Afactors, Apower);          // by product form

	factorize(B, Bfactors, Bpower);   // factorize B
	printf("  B = ");                 // print out factorized result of B
	write(Bfactors, Bpower);          // by product form

	// compute GCD of A and B
	GCD(Afactors, Apower, Bfactors, Bpower, Cfactors, Cpower);
	printf("  GCD(A, B) = ");  // print out GCD result of A and B
	write(Cfactors, Cpower);

    // compute LCM of A and B
	LCM(Afactors, Apower, Bfactors, Bpower, Cfactors, Cpower);
	printf("  LCM(A, B) = ");  // print out LCM result of A and B
	write(Cfactors, Cpower);

	return 0;
}

// function to convert N into its prime factors
void factorize(int N, int factors[S], int power[S])
{
	int i;                            // variable for loop
	int pwr = 0;                      // initialize power number
	int index = 0;                    // initialize address of array

	for (i = 2; i <= N; i++) {        // find prime factor of number N
		pwr = 0;                      // power return 0 to record others'
		while (N % i == 0) {          // check if N be divided by i
			N /= i;                   // update N if divisible
			pwr++;                    // update power if divisible
		}
		if (pwr > 0) {
			factors[index] = i; // record new factor to save in an element
			power[index] = pwr; // record new power to save in an element
			index++;            // expand space to save next value
		}
	}
    factors[index] = 1;         // if prime, ensure arrays are terminated
	power[index] = 1;           // by 1
	return;                     // function termination
}

// take two factors' arrays of factors and powers to produce Greatest
// Common Divisor
void GCD(int Afactors[S], int Apower[S],
         int Bfactors[S], int Bpower[S],
         int Cfactors[S], int Cpower[S])
{
	int a, b, c = 0;            // variables for loops

	// find common prime factors except 1
	for (a = 0; Afactors[a] != 1; a++) {
		for (b = c; Bfactors[b] <= Afactors[a] && Bfactors[b] != 1; b++) {
			if (Afactors[a] == Bfactors[b]) { // common prime factor
				Cfactors[c] = Afactors[a];    // save factor to C array
				if (Apower[a] < Bpower[b]) {  // determine smaller power
					Cpower[c] = Apower[a];    // then save to C array
				} else {                      // when Apower[a] > Bpower[b]
					Cpower[c] = Bpower[b];    // B power save to C array
				}
				c++;            // update index for GCD arrays
			}
		}
	}
	Cfactors[c] = 1;            // ensure arrays are terminated by 1
	Cpower[c] = 1;
    return;                     // function termination
}

// take two numbers' arrays of factors and powers to produce Least
// Common Multiple
void LCM(int Afactors[S], int Apower[S],
         int Bfactors[S], int Bpower[S],
         int Cfactors[S], int Cpower[S])
{
	int a = 0, b = 0, c = 0;    // variables to record arrays' addresses

	while (Afactors[a] != 1 && Bfactors[b] != 1) {
		if (Afactors[a] < Bfactors[b]) {
			Cfactors[c] = Afactors[a];   // choose smaller prime factor and
			Cpower[c] = Apower[a];       // its power then save to C arrays
			a++;                         // update A's and C's index
			c++;
		} else if (Afactors[a] > Bfactors[b]) {
			Cfactors[c] = Bfactors[b];
			Cpower[c] = Bpower[b];
			b++;
			c++;
		} else {
			Cfactors[c] = Afactors[a];    // when factors are same, choose 
			if (Apower[a] > Bpower[b]) {  // larger power then save to C
				Cpower[c] = Apower[a];    // power array
			} else {
				Cpower[c] = Bpower[b];
			}
			a++;                          // update A~C's indexes
			b++;
			c++;
		}
	}
	if (Afactors[a] == 1) {               // A is prime
		while (Bfactors[b] != 1) {        // B isn't prime
			Cfactors[c] = Bfactors[b];    // save B's factors and powers to
			Cpower[c++] = Bpower[b++];    // C's arrays and update index of
			                              // LCM arrays
		}
	} else {
		while (Afactors[a] != 1) {        // A isn't prime
			Cfactors[c] = Afactors[a];    // save A's factors and powers to
			Cpower[c++] = Apower[a++];    // C's arrays and update index of
			                              // LCM arrays
		}
	}
	Cfactors[c] = 1;            // ensure arrays are terminated by 1
	Cpower[c] = 1;
	return;
}

// print out factors and powers of 2 numbers by product form
void write(int factors[S], int power[S])
{
	int i, j;                      // variables for loops
	int product = 1;               // initialize product value

	for (i = 0; factors[i] != 1; i++) {  // loop through all elements in
		for (j = 0; j < power[i]; j++)   // array and keep multiplying
			product *= factors[i];
		if (i)                     // condition to print times sign '*'
		    printf(" * ");         // print '*' after first number
		printf("%d", factors[i]);  // print out prime number
    	if (power[i] != 1)
	    	printf("^%d", power[i]);     // print out power of each factor
	}
	if (product == 1)              // case when 2 numbers are relatively
		printf("1");               // prime, their GCD equals 1
	printf(" = %d\n", product);    // print out the product
	return;                        // function termination
}
