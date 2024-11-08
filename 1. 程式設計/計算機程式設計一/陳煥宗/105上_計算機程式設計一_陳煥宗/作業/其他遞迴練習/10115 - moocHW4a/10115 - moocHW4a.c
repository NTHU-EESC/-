#include <stdio.h>
#include <string.h>
#define MAXBITS 16

char bits[3];
char input[MAXBITS+1];
char answer[MAXBITS+1];
int NBITS;

void check_bits(int cur_bit, int num_hits);
char flip(char ch);
void Permutations(int num, int choose);

int main(void)
{
    int nhits;

    /* Read the two symbols for the binary bits,
    e.g, OI, 01, OX, or -+, etc. */
    scanf("%2s", bits);

    /* Read the input bit string. */
    scanf("%s", input);
    NBITS = strlen(input);

    /* The answers will be stored in the array answer[] */
    answer[NBITS] = '\0';

    /* Read the number of correct bits */
    scanf("%d", &nhits);

    /* Call the recursive function check_bits
    Start from the leftmost bit. */
    check_bits(0, nhits);

    return 0;
}

/*
1.
The value of cur_bit keeps increasing as we
recursively call check_bits().
2.
If input[cur_bit] is correct, the value of num_hits
should decrease; otherwise we should keep num_hits unchanged
and check the next bit.
3.
Copy the bit from input[cur_bit] or flip the bit,
and store the result in the array answer[].
4.
If the recursive call reaches the end of the input,
it is done and we may print the answer using
    printf("%s", answer);
*/
void check_bits(int cur_bit, int num_hits)
{
    int i, j, k;
    if(num_hits == 0) printf("%s\n",answer);

}

/*
Flip the bit. For example,
0 <--> 1
O <--> I
...
*/
char flip(char ch)
{
    return ( (ch==bits[0]) ? bits[1] : bits[0] );
}

void Permutations(int num, int choose)
{
    int test[num]={0};
    if(choose==0)
    Permutations(num,choose-1);
}














