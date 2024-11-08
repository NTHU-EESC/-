1. The downloaded directory has two sub-directory:  
    * main_debug 
    * main_test

2. You should start with the `main.S` in main_debug directory. The task is to implement merge in the main.S. Run `Make` to generate a riscv file and `spike -d <filename>` to debug your program. For more debugging info, check out lab pages.

3. To check for more test cases and if your program(main.S) will work in online judge, you can `cd main_test`, (optionally modify array in main.c), run `Make`, and `spike lfsr.riscv` to see the results. 

