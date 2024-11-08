// Q1 110060007 黃俊穎
// Your program reads in two sets of time in hh:mm:ss format, where
//   hh is the hour in 24 hours per day format, i.e., 00 <= hh <= 23,
//   mm is the minute of the hour, thus, 00 <= mm <= 59,
//   ss is the second of the minute, and 00 <= ss <= 59,
// and prints out the difference, also in hh:mm:ss format.
// Example of program execution:
//
// $ ./a.out
// Time1: 22:22:22
// Time2: 11:11:11
// Difference: 11:11:11
// $ ./a.out
// Time1: 11:11:11
// Time2: 22:22:22
// Difference: 11:11:11
//
// First example has inputs: 22:22:22 and 11:11:11
// And the second example has input: 11:11:11 and 22:22:22
//
#include <stdio.h>

int main(void)
{
    int hh1, mm1, ss1;
	int hh2, mm2, ss2;
	int total_sec1;
	int total_sec2;
    int diff;
    int ans_hh, ans_mm, ans_ss;

    printf("Time1: ");
	scanf("%d:%d:%d", &hh1, &mm1, &ss1);
	printf("Time2: ");
	scanf("%d:%d:%d", &hh2, &mm2, &ss2);

    total_sec1 = hh1 * 60 ^ 2 + mm1 * 60 + ss1;
	total_sec2 = hh2 * 60 ^ 2 + mm2 * 60 + ss2;
	diff = total_sec1 - total_sec2;

	if (diff < 0) {
		diff =  diff * (-1);
	}
	ans_hh = (int)(diff / 3600);
    ans_mm = (int)((diff - ans_hh * 3600) / 60);
	ans_ss = diff - ans_hh * 3600 - ans_mm * 60;

    printf("Difference: %d:%d:%d", ans_hh, ans_mm, ans_ss);
	return 0;
}
