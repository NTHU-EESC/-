1. The downloaded directory has following structure:

    ```
         part_2_function-handout
         ├── Makefile
         ├── README.md
         ├── common/
         ├── config.h
         ├── main.c
         ├── lfsr64.S
		 ├── generate_maze.h
		 └── generate_maze.S
		
    ```

2. The task is reimplement lfsr64 and generate_maze as a function. It is declared in generate_maze.h, and should be implemented in lfsr64.S and generate_maze.S. Run `Make` to to generate a riscv file and `spike <filename>` to debug. To test your own program, you can change values in config.h. 

3. **You need to compress lfsr64.S and generate_maze.S to pa1_part2.tar, then hand in pa1_part2.tar during submission.**  

