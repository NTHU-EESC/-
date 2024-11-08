.section .text
.global search_2

################################################################################
# a0: base address of array A
# a1: number of elements in array A
# a2: target number
#
# Linear search.
# Optimize with:
# 1. loop unrolling
################################################################################
search_2:

addi t0, zero, 0  #counter=0

forloop:
  
  bge t0, a1, exit2  #exit the loop if counter>=array_length
  
  slli t1, t0, 2  #t1=counter*4
  add t1, a0, t1  #t1=array_address+t1
  lw t2, 0(t1)  #t2=value of a[i]
  beq t2, a2, exit1
  addi t0, t0, 1  #counter++

  addi t1, t1, 4  #next array index
  lw t2, 0(t1)  #t2=value of a[i+1]
  beq t2, a2, exit1
  addi t0, t0, 1  #counter++

  addi t1, t1, 4  #next array index
  lw t2, 0(t1)  #t2=value of a[i+2]
  beq t2, a2, exit1
  addi t0, t0, 1  #counter++

  addi t1, t1, 4  #next array index
  lw t2, 0(t1)  #t2=value of a[i+3]
  beq t2, a2, exit1
  addi t0, t0, 1  #counter++

  j forloop

exit1:

  addi a0, t0, 0  #return counter
  j exit

exit2:
  
  addi a0, zero, -1  #return -1

exit:

ret
