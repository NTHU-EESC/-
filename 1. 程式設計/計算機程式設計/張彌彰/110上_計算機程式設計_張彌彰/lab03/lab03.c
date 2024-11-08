// EE231002 Lab03. Solving a Diophantine Equation
// 110060007, 黃俊穎
// 2021/10/25

#include <stdio.h>                 // I/O library

int main(void)                     // start the main function
{
  int a, b, c;                     // variables of the equation
  int cMax;                        // the upper bound of the variable c
  int nas = 0;                     // the number of the answer

                                   // start finding the c's valid limit
  for(c = 1; c * c * c - 5000 * 5000 - 5000 < 0; c++) {
      cMax = c;                    // find the maximum of c value
  }
  
                                   // find the solutions of the equation
  for(c = 2; c <= cMax; c++) {
      // c starts from 2 because a + b * b is always greater than 1
      for(b = 1; b <= 5000; b++) {
	      a = c * c * c - b * b;   // calculate a for next determination
		  if(a > 0 && a <= 5000) { // detect if a is in the range
		      printf("Sol %d: %d + %d∧2 = %d∧3\n", ++nas, a, b, c);
			  // show the results of all valid sets of solution
		  }
	  }
  }

  printf("Number of solutions found: %d\n", nas);
  // show the total number of solutions

  return 0;                        // finish the main function
}
