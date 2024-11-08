// EE231002 Lab09. GCD and LCM
// 108061112, 林靖
// Nov. 23, 2019

#include <stdio.h>

#define S 20

void factorize(int N, int factors[S], int power[S]);
void GCD(int Afactors[S], int Apower[S],
		 int Bfactors[S], int Bpower[S],
		 int Cfactors[S], int Cpower[S]);
void LCM(int Afactors[S], int Apower[S],
		 int Bfactors[S], int Bpower[S],
		 int Cfactors[S], int Cpower[S]);
void write(int factors[S], int power[S]);

int main(void)
{
	int inputA, inputB;
	int Afactors[S], Apower[S] = {0};
	int Bfactors[S], Bpower[S] = {0};
	int Cfactors[S], Cpower[S] = {0};
	printf("input A: ");
	scanf("%d", &inputA);
	printf("input B: ");
	scanf("%d", &inputB);
	printf("  A = ");
	factorize(inputA, Afactors, Apower);
	write(Afactors, Apower);
	printf("  B = ");
	factorize(inputB, Bfactors, Bpower);
	write(Bfactors, Bpower);
	printf("  GCD(A,B) = ");
	GCD(Afactors, Apower, Bfactors, Bpower, Cfactors, Cpower);
	write(Cfactors, Cpower);
	printf("  LCM(A,B) = ");
	LCM(Afactors, Apower, Bfactors, Bpower, Cfactors, Cpower);
	write(Cfactors, Cpower);
	return 0;
}

void factorize(int N, int factors[S], int power[S])
{
	int seed = 6;
	int i = 0;
	int minus, plus;
	
	while (N % 2 == 0) {
		N /= 2;
		power[i]++;
	}
	if (power[i]) {
		factors[i] = 2;
		i++;
	}
	while (N % 3 == 0) {
		N /= 3;
		power[i]++;
	}
	if (power[i]) {
		factors[i] = 3;
		i++;
	}
/*
	for (divisor = 3; divisor <= N / 3; divisor += 2) {
		while (N % divisor == 0) {
			N /= divisor;
			power[i]++;
		}
		if (power[i]) {
			factors[i] = divisor;
			i++;
		}
	}
*/
	for (seed = 6; seed - 1 <= N / 5; seed += 6) {
		minus = seed - 1;
		plus = seed + 1;
		while (N % minus == 0) {
			N /= minus;
			power[i]++;
		}
		if (power[i]) {
			factors[i] = minus;
			i++;
		}
		while (N % minus == 0) {
			N /= minus;
			power[i]++;
		}
		if (power[i]) {
			factors[i] = minus;
			i++;
		}
	}
	factors[i] = N;
	power[i] = 1;
	i++;
	factors[i] = 1;
	power[i] = 1;
	return;
}

void GCD(int Afactors[S], int Apower[S],
		 int Bfactors[S], int Bpower[S],
		 int Cfactors[S], int Cpower[S])
{
	int a, b, c = 0;

	for (a = 0; Afactors[a] != 1; a++) {
		for (b = c; Bfactors[b] <= Afactors[a] && Bfactors[b] != 1; b++) {
			if (Afactors[a] == Bfactors[b]) {
				Cfactors[c] = Afactors[a];
				if (Apower[a] < Bpower[b]) {
					Cpower[c] = Apower[a];
				} else {
					Cpower[c] = Bpower[b];
				}
				c++;
			}
		}
	}
	Cfactors[c] = 1;
	Cpower[c] = 1;
	return;
}

void LCM(int Afactors[S], int Apower[S],
		 int Bfactors[S], int Bpower[S],
		 int Cfactors[S], int Cpower[S])
{
	int a = 0, b = 0, c = 0;

	while (Afactors[a] != 1 && Bfactors[b] != 1) {
		if (Afactors[a] < Bfactors[b]) {
			Cfactors[c] = Afactors[a];
			Cpower[c] = Apower[a];
			a++;
		} else if (Afactors[a] > Bfactors[b]) {
			Cfactors[c] = Bfactors[b];
			Cpower[c] = Bpower[b];
			b++;
		} else {
			Cfactors[c] = Afactors[a];
			if (Apower[a] > Bpower[b]) {
				Cpower[c] = Apower[a];
			} else {
				Cpower[c] = Bpower[b];
			}
			a++;
			b++;
		}
		c++;
	}
	for ( ; Afactors[a] != 1; a++) {
		Cfactors[c] = Afactors[a];
		Cpower[c] = Apower[a];
		c++;
	}
	for ( ; Bfactors[b] != 1; b++) {
		Cfactors[c] = Bfactors[b];
		Cpower[c] = Bpower[b];
		c++;
	}
	Cfactors[c] = 1;
	Cpower[c] = 1;
	return;
}

void write(int factors[S], int power[S])
{
	int i, j;
	int product = 1;

	for (i = 0; factors[i] != 1; i++) {
		for (j = 0; j < power[i]; j++)
			product *= factors[i];
		if (i)
			printf(" * ");
		printf("%d", factors[i]);
		if (power[i] != 1)
			printf("^%d", power[i]);
	}
	if (product == 1)
		printf("1");
	printf(" = %d\n", product);
	return;
}
