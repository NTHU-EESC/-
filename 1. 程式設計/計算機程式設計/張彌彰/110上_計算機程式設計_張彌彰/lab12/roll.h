// EE231002 Lab12. Poker Dice
// roll.h: macros and function declarations
// 2021/12/27

#define FiveKind 0
#define FourKind 1
#define FullHouse 2
#define Straight 3
#define ThreeKind 4
#define TwoPair 5
#define OnePair 6
#define Bust 7

void rollDiceFair(int dice[5]);   // roll fair dice
void rollDiceUnfair(int dice[5]); // roll unfair dice
int rank(int dice[5]);            // Given dice, return corresponding rank
