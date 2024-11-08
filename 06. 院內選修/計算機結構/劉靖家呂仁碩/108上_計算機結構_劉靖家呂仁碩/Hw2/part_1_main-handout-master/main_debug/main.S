.section .data
.align 8

# There are two global variables:
#  * seed: 
#  * feedback: 
# You can modify the following lines to test your program
seed: .dword SEED
feedback: .dword FEEDBACK

.section .text
.global main
main:

  # your code goes here
  
  la t0, seed        # take the address of  seed  / feedback
  la t1 , feedback  

  ld t2,  0(t0)      # load seed = t2
  ld t3 , 0(t1)      # load feedback = t3

  andi t4 , t2   , 1    # t4 = seed&1
  srli t5 , t2   , 1    # t5 = seed>>1
  addi t6 , zero , 1    # t6 = 1  
  
  beq  t4 , t6   , IF    # if (seed&1 == 1 ) go to IF
  
       sd   t5 , 0(t0)    #    new seed = seed>>1
       j EXIT             #
       
      
  IF :
       xor   t5 , t5 , t3   #   t4 =  (seed>>1)^feed back   
       sd    t5 , 0(t0)       #   new seed = (seed>>1)^feed back  
  
  EXIT :
  
  # do not modify following
  li  a0, 0      #assign 0 to a0
  ret            #return (jump to the addr store in register ra)

