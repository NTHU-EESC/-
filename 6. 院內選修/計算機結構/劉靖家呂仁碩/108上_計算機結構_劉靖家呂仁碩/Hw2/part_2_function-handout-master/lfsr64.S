########################################
# Make 'lfsr64' a function: 
#   Similar to the previous task, the only difference is lfsr64 now becomes a function.
#   That is,
#   a0 --> status
#   a1 --> feedback
#	the return value should be put in a0 before ret
#	uint64_t lfsr64(uint64_t status, uint64_t feedback){
#		uint64_t lfsr=status;
#		lfsr = (lfsr & 1) ? (lfsr >> 1) ^ feedback : (lfsr >> 1);
#		return lfsr;
#	}
#   as designated in declaraction of lfsr64() in generate_maze.h
########################################

.section .data
.align 1

.section .text
.global lfsr64 
lfsr64:

  # your code goes here
  # remember to save register such as s0 or ra onto the stack if you used it in the assembly. 
  andi t0 , a0   , 1    # t0 = status&1
  srli t1 , a0   , 1    # t1 = status>>1
  addi t2 , zero , 1    # t2 = 1  
  
  beq  t0, t2   , IF    # if (status&1 == 1 ) go to IF
  
       addi a0 , t1 , 0    #    new status = status>>1
       j EXIT             #
       
      
  IF :
       xor   t0 , t1 , a1   #   t0 =  (status>>1)^feed back   
       addi a0 , t0 , 0      #   new status = (status>>1)^feed back  
  
  EXIT :
  
  ret      #return, same as "jr ra"