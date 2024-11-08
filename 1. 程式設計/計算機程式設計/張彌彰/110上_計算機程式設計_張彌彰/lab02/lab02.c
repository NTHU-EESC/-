// EE231002 Lab02. Day of the Year and Day of the week
// 110060007, 黃俊穎
// 2022/01/01

#include <stdio.h>                  // I/O library

int main(void)                      // the main function
{
	int year, month, day;             // variables to store the inputs
	int totalDays, dayOfYear, dayOfWeek;
	// variables to calculate the answer

  	printf("Enter a date (y/m/d): ");        // prompt for date 
  	scanf("%d/%d/%d", &year, &month, &day);  // read the input

	// start calculating dayOfYear first
	dayOfYear = day;	              // the days passed this month
  	switch (month) { 
    // start calculating the days of each month passed
    	case 12:  dayOfYear += 30;    // add the days in Nov.
		case 11:  dayOfYear += 31;    // add the days in Oct.
		case 10:  dayOfYear += 30;    // add the days in Sep.
		case 9:  dayOfYear += 31;    // add the days in Aug.
		case 8:  dayOfYear += 31;    // add the days in Jul.
		case 7:  dayOfYear += 30;    // add the days in Jun.
		case 6:  dayOfYear += 31;    // add the days in May.
		case 5:  dayOfYear += 30;    // add the days in Apr.
		case 4:  dayOfYear += 31;    // add the days in Mar.
		case 3:  dayOfYear += 28;    // add the days in normal year's Feb.
		         if(0 == year % 4 && 0 != year % 100 || 0 == year % 400){
				                      // check if that year is leap year
				 	dayOfYear += 1;   // plus the additional day in Feb.
				 }
		case 2:  dayOfYear += 31;     // add the days in Jan.
  	}
    // finish calculating the days of each month passed

	// start calculating totalDays from 1/1/1
	year--;               // neglect the latest year's days 
	totalDays = year * 365;         // every year has at least 365 days
	totalDays += year / 4;          // leap year happens every 4 years
	totalDays -= year / 100;        // minus the day(2/29) every 100 years 
	totalDays += year / 400;        // add the day (2/29) every 400 years 
	totalDays += dayOfYear;         // add the days this year 

	printf("Total Gregorian Calendar days: %d\n", totalDays);
   		                            // print out the totalDays
  	printf("Day of year: %d\n", dayOfYear);  // print out the day of year 
	// finish calculating totalDays from 1/1/1

   	// start calculating the day of the week
	dayOfWeek = totalDays % 7;      // mod 7 to indicate the day if the week
	printf("Day of week: ");
                                    // start printing out the day of week

	switch (dayOfWeek) {              // analyze the reminder
    	case 0:  printf("Sunday");    break; // 0 is Sunday
    	case 1:  printf("Monday");    break; // 1 is Monday
		case 2:  printf("Tuesday");   break; // 2 is Tuesday
		case 3:  printf("Wednesday"); break; // 3 is Wednesday
		case 4:  printf("Thursday");  break; // 4 is Thursday
    	case 5:  printf("Friday");    break; // 5 is Friday
		case 6:  printf("Saturday");  break; // 6 is Saturday
	}
	printf("\n");                  // change the next line
    // finish calculating the day of the week

	return 0;                       // finish the whole main program
}
