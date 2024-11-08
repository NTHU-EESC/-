// EE231002 Lab09. GCD and LCM
// 108061112, 林靖
// Nov. 23, 2019

#include <stdio.h>						   // Standard input and output library

#define S 20							   // Size of array
										   // Convert N into its prime factors
void factorize(int N, int factors[S], int power[S]);
void GCD(int Afactors[S], int Apower[S],   // Takes two factors arrays and two
		 int Bfactors[S], int Bpower[S],   // power arrays to produce the arrays
		 int Cfactors[S], int Cpower[S]);  // of the Greatest Common Divisor.
void LCM(int Afactors[S], int Apower[S],
		 int Bfactors[S], int Bpower[S],   // To produce the arrays of the Least
		 int Cfactors[S], int Cpower[S]);  // Common Multiple.
void write(int factors[S], int power[S]);  // To print out the factors and power
										   // arrays using the product form.
int main(void)
{											// Called at program startup
	int inputA, inputB;						// Two integers to be factorized
	int Afactors[S], Apower[S] = {0};		// Factorized inputA
	int Bfactors[S], Bpower[S] = {0};		// Factorized inputB
	int Cfactors[S], Cpower[S];				// GCD or LCM of inputA & inputB
	printf("input A: ");					// Prompt user to input an integer
	scanf("%d", &inputA);					// Read in inputA
	printf("input B: ");					// Prompt user to input an integer
	scanf("%d", &inputB);					// Read in inputB
	factorize(inputA, Afactors, Apower);	// Convert inputA into its factors
	printf("  A = ");						// Print out factors and powers of
	write(Afactors, Apower);				// inputA using the product form.
	factorize(inputB, Bfactors, Bpower);	// Convert inputB into its factors
	printf("  B = ");						// Print out factors and powers of
	write(Bfactors, Bpower);				// inputB using the product form.
	GCD(Afactors, Apower, Bfactors, Bpower, Cfactors, Cpower); // Compute GCD
	printf("  GCD(A,B) = ");				// Print out GCD of inputA & inputB
	write(Cfactors, Cpower);				// using the product form.
	LCM(Afactors, Apower, Bfactors, Bpower, Cfactors, Cpower); // Compute LCM
	printf("  LCM(A,B) = ");				// Print out LCM of inputA & inputB
	write(Cfactors, Cpower);				// using the product form.
	return 0;								// Normal program termination
}

void factorize(int N, int factors[S], int power[S])
{									// Convert N into its prime factors
	int divisor = 2;				// Candidate factor, trial division
	int i = 0;						// Common index for arrays
	
	while (N % divisor == 0) {		// Keep dividing by 2 untill N become odd
		N /= divisor;				// Update N if divisible
		power[i]++;					// Update power if divisible
	}
	if (power[i]) {					// If power != 0 (divisible)
		factors[i] = divisor;		// Write divisor into array
		i++;						// Update common index for arrays
	}
	for (divisor = 3; divisor * divisor <= N; divisor += 2) {	// N must be odd
		while (N % divisor == 0) {	// Keep dividing if divisible
			N /= divisor;			// Update N if divisible
			power[i]++;				// Update power if divisible
		}
		if (power[i]) {				// If power != 0 (divisible)
			factors[i] = divisor;	// Write divisor into array
			i++;					// Update common index for arrays
		}
	}
	factors[i] = N;					// N must be 1 or a prime number now
	power[i] = 1;
	if (factors[i] != 1) {			// If N is a prime number
		i++; 
		factors[i] = 1;				// Ensure arrays are terminated by 1
		power[i] = 1;
	}
	return;							// Function termination
}

void GCD(int Afactors[S], int Apower[S],   // Takes two factors arrays and two
		 int Bfactors[S], int Bpower[S],   // power arrays to produce the arrays
		 int Cfactors[S], int Cpower[S])   // of the Greatest Common Divisor.
{
	int a, b, c = 0;					   // Indice for arrays of A, B, and GCD

	for (a = 0; Afactors[a] != 1; a++) {   // To find common prime factors
		for (b = c; Bfactors[b] <= Afactors[a] && Bfactors[b] != 1; b++) {
			if (Afactors[a] == Bfactors[b]) {	// Common prime factor
				Cfactors[c] = Afactors[a];		// Write the factor into array
				if (Apower[a] < Bpower[b]) {	// Determine the smaller power
					Cpower[c] = Apower[a];		// Write smaller one into array
				} else {
					Cpower[c] = Bpower[b];
				}
				c++;				// Update index for GCD arrays
			}
		}
	}
	Cfactors[c] = 1;				// Ensure arrays are terminated by 1		
	Cpower[c] = 1;
	return;							// Function termination
}

void LCM(int Afactors[S], int Apower[S],
		 int Bfactors[S], int Bpower[S],   // To produce the arrays of the Least
		 int Cfactors[S], int Cpower[S])   // Common Multiple.
{
	int a = 0, b = 0, c = 0;			   // Indice for arrays of A, B, and LCM

	while (Afactors[a] != 1 && Bfactors[b] != 1) {	// Sort from small to large
		if (Afactors[a] < Bfactors[b]) {			// If A is smaller than B
			Cfactors[c] = Afactors[a];				// Write the smaller ones
			Cpower[c] = Apower[a];					// into the arrays.
			a++;									// Update the index of A
		} else if (Afactors[a] > Bfactors[b]) {	// If B is smaller than A
			Cfactors[c] = Bfactors[b];			// Write the smaller ones into
			Cpower[c] = Bpower[b];				// the arrays.
			b++;								// Update the index of A
		} else {							// If A equal to B
			Cfactors[c] = Afactors[a];		// Write arbitrarily A or B factor
			if (Apower[a] > Bpower[b]) {	// Determine the larger power
				Cpower[c] = Apower[a];		// Write the larger power into array
			} else {
				Cpower[c] = Bpower[b];
			}
			a++;						// Update both A's & B's indice
			b++;
		}
		c++;							// Update the index of LCM arrays
	}
	for ( ; Afactors[a] != 1; a++) {
		Cfactors[c] = Afactors[a];		// Copy the remaining elements in A into
		Cpower[c] = Apower[a];;			// LCM arrays
		c++;							// Update indice of LCM arrays
	}
	for ( ; Bfactors[b] != 1; b++) {
		Cfactors[c] = Bfactors[b];		// Copy the remaining elements in B into
		Cpower[c] = Bpower[b];			// LCM arrays
		c++;							// Update indice of LCM arrays
	}
	Cfactors[c] = 1;					// Ensure arrays are terminated by 1
	Cpower[c] = 1;
	return;								// Function termination
}

void write(int factors[S], int power[S])   // To print out the factors and power
{										   // arrays using the product form.
	int i, j;							// Indice for looping
	int product = 1;					// Product of factors and powers arrays

	for (i = 0; factors[i] != 1; i++) {
		for (j = 0; j < power[i]; j++)
			product *= factors[i];		// Compute the factor to its power
		if (i)							// Condition to print multiplicate sign
			printf(" * ");				// The multiplicate sign
		printf("%d", factors[i]);		// The prime factor
		if (power[i] != 1)				// Condition to print power of factor
			printf("^%d", power[i]);	// The power of the factor
	}
	if (product == 1)					// Handle in case coprime
		printf("1");					// GCD = 1 if coprime
	printf(" = %d\n", product);			// Print out the product
	return;								// Function termination
}
