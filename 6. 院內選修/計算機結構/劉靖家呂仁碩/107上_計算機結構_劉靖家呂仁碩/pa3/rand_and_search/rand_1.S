.section .text
.global rand_1

################################################################################
# a0: base address of array A
# a1: number of elements in array A
# a2: seed
# a3: for loop counter
# a4: value of a[i-1]

# t0: tmp
# t1: array_address counter
# t2~t4: shift bit temporary

# Generate pseudo-random numbers.
################################################################################
rand_1:

  sw a2, 0(a0)  #a[0]=seed
  addi a3, zero, 1  #a3=1

forloop:

  bge a3, a1, exit  #if counter>array_number, exit from loop
  
  addi t1, a3, -1  #t1=counter-1
  slli t1, t1, 2  #t1=t1*4
  add t1, t1, a0  #t1=t1+array_address
  lw a4, 0(t1)  #load value of a[i-1]
  addi t0, a4, 0  #tmp=a[i-1]

  slli t2, t0, 1  #t2=tmp<<1
  slli t3, t0, 6  #t3=tmp<<6
  slli t4, t0, 7  #t4=tmp<<7

  xor t0, t0, t2
  xor t0, t0, t3
  xor t0, t0, t4
  andi t0, t0, 128  #feedback calculation

  srli a4, a4, 1  #a4=a[i-1]>>1
  or t0, a4, t0  #feedback
  
  slli t1, a3, 2  #t1=counter*4
  add t1, t1, a0  #t1=t1+array_address 
  sw t0, 0(t1)

  addi a3, a3, 1  #counter++

  j forloop

exit:

ret 
