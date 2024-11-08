.section .data
# There are two global variables:
#  1. list: Store the input numbers.
#  2. size: the number of the list
# You can modify the following two lines to test your program,
# but DO NOT change the line number
array: .dword 15, 20, 6, 35, 70, 7, 14, 36, 1, 21, 13, 3, 24, 5, 22, 2, 4, 10, 8, 12
size: .dword 20

.section .text
.global main
main:

  # save return pointer
  addi  sp, sp, -8
  sd  ra, 0(sp)

  la  a0, array  #assign array address to a0
  ld  s0, size  #assign array size to s0

  #jump to function
  jal  bulidminheap  

  li  a0, 0      #assigne 0 to a0
  ld  ra, 0(sp)
  addi  sp, sp, 8

  ret            #return (jump to the addr store in register ra)


#### registers used ####
# a0: array address
# s0: total array size
# s1: build heap index
# s2: current node index
########################
.global bulidminheap
bulidminheap:
  
  #save return pointer
  addi  sp, sp, -8
  sd  ra, 0(sp)

  #divide array size by 2
  li  t0, 2
  div  s1, s0, t0
  
loop1:
  beq  s1, zero, exit1  #loop condition 
  addi  s2, s1, 0 
  jal  minheapify  #jump to function
  addi  s1, s1, -1  #index--
  j  loop1

exit1:

  ld  ra, 0(sp)
  addi  sp, sp, 8

  ret

#### registers used ####
# a0: array address
# s0: total array size
# s1: build heap index
# s2: current node index
# s3: left child index
# s4: right child index
# s5: smallest index
########################
.global minheapify
minheapify:

  #save return pointer
  addi  sp, sp, -8
  sd  ra, 0(sp)
  
  #assign node index
  li  t0, 2
  mul  s3, s2, t0  #left = current*2
  addi  s4, s3, 1  #right = left+1

  #leftchild check
  bgt  s3, s0, label1  #if left > size, jump to label1

  addi  t0, s3, -1
  slli  t1, t0, 3  #t1 = left*8
  add  t1, a0, t1  #t1 = array address + left*8 (get left child address)
  ld  t2, 0(t1)  #get left child value

  addi  t0, s2, -1
  slli  t1, t0, 3  #t1 = node*8
  add  t1, a0, t1  #t1 = array address + current node*8 (get current node address)
  ld  t3, 0(t1)  #get current node value
  
  bge  t2, t3, label1  #if left child value >= current node value, jump to label1

  addi  s5, s3, 0  #smallest = left
  j  label2

label1:
  addi  s5, s2, 0  #smallest = node

label2:

  #rightchild check
  bgt  s4, s0, label3  #if right > size, jump to label3

  addi  t0, s4, -1
  slli  t1, t0, 3  #t1 = right*8
  add  t1, a0, t1  #t1 = array address + right*8 (get right child address)
  ld  t2, 0(t1)  #get right child value

  addi  t0, s5, -1
  slli  t1, t0, 3  #t1 = smallest*8
  add  t1, a0, t1  #t1 = array address + smallest*8 (get smallest address)
  ld  t3, 0(t1)  #get smallest value

  bge  t2, t3, label3  #if right child value >= smallest value, jump to label3

  addi  s5, s4, 0  #smallest = right

label3:

  #smallest check, if true, operate swap and recursion
  
  beq  s5, s2, label4  #if smallest = current node, jump to label4

  jal  swap  #jump to swap function
  addi  s2, s5, 0  #current node = smallest
  jal  minheapify  #recursive call

label4:
  
  #load saved registers
  ld  ra, 0(sp)
  addi  sp, sp, 8

  ret

#### registers used ####
# a0: array address
# s2: current node index
# s5: smallest index
########################
.global swap
swap:
  
  #get address and value
  addi  t0, s2, -1
  slli  t0, t0, 3  #t0 = current*8
  add  t0, a0, t0  #t0 = array address + current*8 (get current node address)
  ld  t1, 0(t0)  #get current node value

  addi  t2, s5, -1
  slli  t2, t2, 3  #t2 = smallest*8
  add  t2, a0, t2  #t2 = array address + smallest*8 (get smallest address)
  ld  t3, 0(t2)  #get smallest value

  #store value
  sd  t1, 0(t2)
  sd  t3, 0(t0)

  ret

