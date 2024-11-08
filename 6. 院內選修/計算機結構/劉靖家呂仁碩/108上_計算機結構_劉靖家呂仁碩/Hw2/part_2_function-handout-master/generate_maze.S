########################################
# Make 'generate_maze' a function: 
#   Now, generate_maze becomes a function.
#   That is,
#   a0 --> maze[]
#   a1 --> h
#   a2 --> w 
#   a3 --> i_i 
#   a4 --> i_j 
#   a5 --> address of seed 
#   as designated in declaraction of generate_maze() in main.c
#	To call the function, remember to put function arguments into specified registers
########################################

.section .text
.align	1

.globl	generate_maze
generate_maze:
  
  # your code goes here
  # remember to save register such as s0 or ra onto the stack if you used it in the assembly. 

  ##	first store the initial map with i_i,i_j is '1' ##
   addi t0 , zero , 1   #  t0 = 0x0000000000000001 (j)
   sll  t1 , t0   , a4  #  t1 = t0<<i_j   (j << i_j)
   slli t2 , a3   , 3   #  t2 =   i_i<<3 (i_i * 8 , because 64bit = 8 bytes )
   add  t2 , a0   ,t2   #  now t2 = address of  maze[i_i]
   ld   x30 , 0(t2)      #  x30 = maze[i_i]
   xor  x30 , x30 , t1    #  new x30= x30^t1  [ maze[i_i]^(j<<i_j) ]
   sd   x30 , 0(t2)      #  new maze[i_i] = new x30 

   

   addi sp,sp,-64

   sd   ra,56(sp)    # store x1 = ra , caller posiotn address !!! (PC+4)
     
   sd   t2,48(sp)    # store t2 = the address of maze[i_i]  (because in lfsr64.S use it )

   #########store the information to stack###########
   sd a0,0(sp)      # maze
   sd a1,8(sp)      # h
   sd a2,16(sp)     # w
   sd a3,24(sp)     # i_i
   sd a4,32(sp)     # i_j
   sd a5,40(sp)     # seed




LOOP:
      ############### available_dir(maze, i_i, i_j) ###############  
	  # input a0 a1 a2 , 
	  # output a0 = range		#   a0 = maze no need to ld

		
          ld a1 , 24(sp) 			#   a1 = i_i
          ld a2 , 32(sp) 		    #   a2 = i_j
          jal x1, available_dir		#   range = a0 , for now    
          addi x5 , zero , -1		#   x5 = -1
          beq x5 , a0 , EXIT		#   if range == -1 break;
      

      ############### random_dir(seed, range)  ###############  
	  # input a0, a1;
	  # ouput a0;
          addi a1,a0,0            #   a1 = range (previous a0) 
          ld a0,40(sp)            #   a0 = seed 
          jal x1, random_dir  	  #   r=random_dir(seed, range);
                                  #   r = a0 , for now 

          
       
      ############### choose_dir(maze, i_i, i_j, r) ###############  
	  # input a0, a1, a2, a3;
	  # ouput a0 = direction;

          addi a3,a0,0            #   a3 = r (previous a0) 
          ld a0,0(sp)             #   a0 = maze
          ld a1,24(sp) 	 		  #   a1 = i_i
          ld a2,32(sp) 	  	      #   a2 = i_j
          jal x1, choose_dir      #   direction=choose_dir(maze, i_i, i_j, r);
                                  #   direction=a0
        
       

	  ld   t2, 48(sp)        # t2 = maze[i_i]
	 
	 ############### rebuild i_i , i_j = a6, a7
          ld a6,24(sp)     # i_i  
   	  ld a7,32(sp)     # i_j
          addi t0,zero,1

 
         

	############### if (direction == 0) >>>  right
		beq   a0, zero, right   # if (direction == 0), go to "right"
  
	############### if (direction == 1) >>>  down
	        addi  t3, zero, 1       # t3 = 1
		beq   a0, t3, down      # if (direction == 1), go to "down"
  
	############### if (direction == 2) >>>  left
		addi  t3,   t3, 1       # t3 = 2
		beq   a0,   t3, left	 # if (direction == 2), go to "left"
  
	############### else if (direction == 3) >>>  up
 		addi  t3,   t3, 1       # t3 = 2
		beq   a0,   t3, up	 # if (direction == 3), go to "up"


	############### maze[i_i]= maze[i_i]^(j<< (i_j+1)) 
	right:
     	 ld   x30 , 0(t2)       #  x30 = maze[i_i]
         addi t4 , a7 , 1      #  t4 = i_j+1
     	 sll  t4 , t0 , t4     #  new t4 = t0<<t4   (j << i_j+1)
     	 xor  x30 , x30 , t4     #  new x30= x30^t4  [ maze[i_i]^(j<< (i_j+1)) ]
     	 sd   x30 , 0(t2)       #  new maze[i_i] = new x30 
		 
		# next_i=i_i;  next_j=i_j+2;  a6 doesn't change  , a7 = a7+2
         addi  a7, a7 , 2
         j last 

	############### maze[i_i]= maze[i_i]^(j<< (i_j+1))
	down: 
    	 addi t2 , t2 , 8     #  address + 8bytes = address of maze[i_i+1]
     	 ld   x30 , 0(t2)       #  x30 = maze[i_i+1]
     	 sll  t4 , t0 , a7     #  t4 = t0<<a4   (j << i_j)
     	 xor  x30 , x30 , t4     #  new t3= t3^t4  [ maze[i_i+1]^(j<<i_j) ]
     	 sd   x30 , 0(t2)       #  new maze[i_i+1] = new t3 

		# next_i=i_i+2;   next_j=i_j;   a7 doesn't change  , a6 = a6+2
         addi  a6, a6 , 2
         j last 

	############### maze[i_i] = maze[i_i] ^ (tmp<< (i_j-1));
	left:
                 

		 ld   x30, 0(t2)        # load the value of t2 to x31 (x31 = maze[i_i])
		 addi  t4, a7, -1        # x5 = i_j - 1
		 sll   t4, t0, t4       # (tmp<< (i_j-1)) (store in x7)
		 xor  x30, x30, t4       # maze[i_i] = maze[i_i] ^ (tmp<< (i_j-1))
		 sd   x30, 0(t2)        # store the value of x31 to x30 (maze[i_i] = x31)
  
		  ### i_j = i_j-2;
		  addi a7, a7, -2          
	 j last 

	############### maze[i_i]= maze[i_i]^(j<< (i_j-1))
	up:
    	 addi t2 , t2 , -8     #  address + 8bytes = address of maze[i_i-1]
     	 ld   x30 , 0(t2)       #  x30 = maze[i_i+1]
     	 sll  t4 , t0 , a7     #  t4 = t0<<a4   (j << i_j)
     	 xor  x30 , x30 , t4     #  new t3= t3^t4  [ maze[i_i+1]^(j<<i_j) ]
     	 sd   x30 , 0(t2)       #  new maze[i_i+1] = new t3 

		# next_i=i_i-2;   next_j=i_j;   a7 doesn't change  , a6 = a6-2
         addi  a6, a6 , -2
         j last 
		 
##############################################################  
last:
  
  ### generate_maze(maze, h, w, i_i, i_j, seed)
  ### input: a0, a1, a2, a3, a4, a5
  



  ld   a0, 0(sp)          # a0 = maze[]
  addi a3, a6, 0          # a3 = i_i
  addi a4, a7, 0          # a4 = i_j
  ld   a1, 8(sp)          # a1 = h
  ld   a2, 16(sp)         # a2 = w
  ld   a5, 40(sp)         # a5 = seed


  
  
  jal x1, generate_maze
  
  ### rebuild all value after calling generate_maze
  
  ld   a0, 0(sp)          # a0 = maze[]  
  ld   a1, 8(sp)          # a1 = h
  ld   a2, 16(sp)         # a2 = w
  ld   a3, 24(sp)         # a3 = i_i
  ld   a4, 32(sp)         # a4 = i_j
  ld   a5, 40(sp)         # a5 = seed  
  
  j LOOP

EXIT:
  
  ld   x1, 56(sp)         # restore x1 from stack   
  addi sp, sp, 64     


  ret      #return, same as "jr ra"


	# do not modify following, it's the function for you to call
	.align	1
	.globl	available_dir
	.type	available_dir, @function
available_dir:
	slli	a1,a1,3
	add	a1,a0,a1
	li	a5,1
	ld	a3,0(a1)
	sll	a2,a5,a2
	ld	a4,16(a1)
	slli	a5,a2,2
	and	a5,a5,a3
	snez	a5,a5
	and	a4,a2,a4
	sext.w	a0,a5
	beqz	a4,.L2
	addiw	a0,a5,1
.L2:
	ld	a4,-16(a1)
	srli	a5,a2,2
	and	a5,a5,a3
	and	a2,a2,a4
	beqz	a5,.L3
	addiw	a0,a0,1
	beqz	a2,.L11
.L4:
	addiw	a0,a0,1
	ret
.L3:
	bnez	a2,.L4
	beqz	a0,.L12
	ret
.L11:
	ret
.L12:
	li	a0,-1
	ret
	.size	available_dir, .-available_dir
	.align	1
	.globl	random_dir
	.type	random_dir, @function
random_dir:
	ld	a5,0(a0)
	andi	a4,a5,1
	srli	a5,a5,1
	beqz	a4,.L14
	li	a4,-1
	slli	a4,a4,63
	addi	a4,a4,13
	xor	a5,a5,a4
.L14:
	remu	a1,a5,a1
	sd	a5,0(a0)
	sext.w	a0,a1
	ret
	.size	random_dir, .-random_dir
	.align	1
	.globl	choose_dir
	.type	choose_dir, @function
choose_dir:
	slli	a1,a1,3
	add	a0,a0,a1
	li	a5,1
	ld	a6,0(a0)
	sll	a2,a5,a2
	slli	a1,a2,2
	and	a1,a1,a6
	addi	sp,sp,-16
	li	a5,0
	beqz	a1,.L19
	sw	zero,0(sp)
	li	a5,1
.L19:
	ld	a1,16(a0)
	and	a1,a2,a1
	beqz	a1,.L20
	slli	a4,a5,2
	addi	a1,sp,16
	add	a4,a1,a4
	li	a1,1
	sw	a1,-16(a4)
	addiw	a5,a5,1
.L20:
	srli	a4,a2,2
	and	a4,a4,a6
	beqz	a4,.L21
	slli	a4,a5,2
	addi	a1,sp,16
	add	a4,a1,a4
	li	a1,2
	sw	a1,-16(a4)
	addiw	a5,a5,1
.L21:
	ld	a4,-16(a0)
	and	a2,a2,a4
	beqz	a2,.L22
	addi	a4,sp,16
	slli	a5,a5,2
	add	a5,a4,a5
	li	a4,3
	sw	a4,-16(a5)
.L22:
	addi	a5,sp,16
	slli	a3,a3,2
	add	a3,a5,a3
	lw	a0,-16(a3)
	addi	sp,sp,16
	jr	ra
	.size	choose_dir, .-choose_dir

	.align	1
	.globl	random_lfsr
	.type	random_lfsr, @function
random_lfsr:
	remu	a0,a0,a1
	ret
	.size	random_lfsr, .-random_lfsr
	.globl	FEEDBACK
	.section	.srodata,"a"
	.align	3
	.type	FEEDBACK, @object
	.size	FEEDBACK, 8
FEEDBACK:
	.dword	-9223372036854775795
	.ident	"GCC: (SiFive GCC 8.2.0-2019.05.3) 8.2.0"
