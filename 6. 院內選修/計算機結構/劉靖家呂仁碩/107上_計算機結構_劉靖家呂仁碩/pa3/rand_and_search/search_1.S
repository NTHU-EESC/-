.section .text
.global search_1

################################################################################
# a0: base address of array A
# a1: number of elements in array A
# a2: target number
#
# Linear search.
################################################################################
search_1:

  addi t0, zero, 0  #counter=0

forloop:
  
  bge t0, a1, exit2  #exit the loop if counter>=array_length
  
  slli t1, t0, 2  #t1=counter*4
  add t2, a0, t1  #t2=array_address+t1
  lw t3, 0(t2)  #t3=value of a[i]

  beq t3, a2, exit1

  addi t0, t0, 1  #counter++

  j forloop

exit1:

  addi a0, t0, 0  #return counter
  j exit

exit2:
  
  addi a0, zero, -1  #return -1

exit:

ret
