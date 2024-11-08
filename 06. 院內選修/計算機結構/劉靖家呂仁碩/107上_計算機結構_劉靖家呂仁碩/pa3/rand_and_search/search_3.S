.section .text
.global search_3

################################################################################
# a0: basae address of array A
# a1: number of elements in array A
# a2: target number
#
# Linear search.
# Optimize with:
# 1. loop unrolling
# 2. static reordering
################################################################################
search_3:

addi t0, zero, 0  #counter=0

forloop:
  
  bge t0, a1, exit2  #exit the loop if counter>=array_length
  
  lw t2, 0(a0)  #t2=value of a[i]
  lw t3, 4(a0)  #t3=value of a[i+1]
  lw t4, 8(a0)  #t4=value of a[i+2]
  lw t5, 12(a0)  #t5=value of a[i+3]

  beq t2, a2, exit1
  addi t0, t0, 1  #counter++

  beq t3, a2, exit1
  addi t0, t0, 1  #counter++

  beq t4, a2, exit1
  addi t0, t0, 1  #counter++

  beq t5, a2, exit1
  addi t0, t0, 1  #counter++

  addi a0, a0, 16

  j forloop

exit1:

  addi a0, t0, 0  #return counter
  j exit

exit2:
  
  addi a0, zero, -1  #return -1

exit:

ret
