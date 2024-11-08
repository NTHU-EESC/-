.section .text
.global rand_2

################################################################################
# a0: base address of array A (a)
# a1: number of elements in array A (len)
# a2: seed
#
# Generate pseudo-random numbers.
################################################################################
rand_2:
     
      sw a2,0(a0)  # store seed(=a2) into 0(a0) --> 令 a[0]=seed
      addi t0,zero,1 # t0=i=1

      ### 令t3 = 0x380000c3 (固定的rs2)
      lui t3, 0x38000
      addi t3, t3, 0x0c3
    
   Loop:

      bge t0,a1, exit   # if i>= len (不符合i<len) 則離開迴圈 


      ###int32_t tmp = a[i - 1];  (先取得a[i]的address後-4即可得到a[i-1]的adress,這樣cycle數會比較少)

      slli t1,t0,2      #  令t1 = i*4 (因為要取的addres是4bytes單位的)
      add  t1,t1,a0     #  此時t1= 'a[i]的address'
      lw   t2,-4(t1)    #  令t2=a[i-1]= tmp


      ### lfsr t4,t2,t3
      .word 0x1c3fe8b


      ### 將結果(t4)存入a[i](t1)中

      sw   t4,0(t1)     
      

      ### i++
      addi t0,t0,1


     j Loop

     exit:

     ret
