.section .text
.global rand_3

################################################################################
# a0: base address of array A
# a1: number of elements in array A
# a2: seed
#
# Generate pseudo-random numbers.
# Optimize with:
# 1. new instruction: lfsr
# 2. loop unrolling
################################################################################
rand_3:

  sw a2, 0(a0)  #a[0]=seed
  addi a3, zero, 1  #counter
  addi a0, a0, 4  #next array address
  li t0, 0x380000c3  #lfsr const
  addi t1, a2, 0  #tmp=seed

forloop:

  bge a3, a1, exit  #if counter>array_number, exit from loop
  
  .word 0x53730b  #lfsr t1, t1, t0
  sw t1, 0(a0)  #store results
  .word 0x53730b  #lfsr t1, t1, t0
  sw t1, 4(a0)  #store results
  .word 0x53730b  #lfsr t1, t1, t0
  sw t1, 8(a0)  #store results
  .word 0x53730b  #lfsr t1, t1, t0
  sw t1, 12(a0)  #store results
 

  addi a0, a0, 16  #next array address
  addi a3, a3, 4  #counter++

  j forloop

exit:
ret
