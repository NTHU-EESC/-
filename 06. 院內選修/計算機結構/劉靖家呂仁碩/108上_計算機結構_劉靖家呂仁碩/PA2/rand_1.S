.section .text
.global rand_1

################################################################################
# a0: base address of array A (a)
# a1: number of elements in array A (len)
# a2: seed
#
# Generate pseudo-random numbers.
################################################################################
rand_1:
     
      sw a2,0(a0)  # store seed(=a2) into 0(a0) --> 令 a[0]=seed
      addi t0,zero,1 # t0=i=1

    
   Loop:

      bge t0,a1, exit   # if i>= len (不符合i<len) 則離開迴圈 

      ###int32_t tmp = a[i - 1];  (先取得a[i]的address後-4即可得到a[i-1]的adress,這樣cycle數會比較少)

      slli t1,t0,2      #  令t1 = i*4 (因為要取的addres是4bytes單位的)
      add  t1,t1,a0     #  此時t1= 'a[i]的address'
      lw   t2,-4(t1)    #  令t2=a[i-1]= tmp



      ###  tmp = (tmp ^ (tmp << 1) ^ (tmp << 6) ^ (tmp << 7)) & 0x80; 

      slli t3,t2,1      #  t3=tmp<<1
      slli t4,t2,6      #  t4=tmp<<6
      slli t5,t2,7      #  t5=tmp<<7

      xor  t6,t2,t3     #  t6=t2^t3 --> 先做tmp ^ (tmp << 1)
      xor  t6,t6,t4     #  t6=t6^t4 --> 再做tmp ^ (tmp << 1) ^ (tmp << 6) 
      xor  t6,t6,t5     #  t6=t6^t5 --> 完成(tmp ^ (tmp << 1) ^ (tmp << 6) ^ (tmp << 7))
      andi t6,t6,0x80   #  最終t6 = (tmp ^ (tmp << 1) ^ (tmp << 6) ^ (tmp << 7)) & 0x80;



      ###a[i] = (a[i - 1] >> 1) | tmp;   

      srli t2,t2,1      #  t2=t2>>1 -->先做 t2= a[i - 1] >> 1
      or   t2,t2,t6     #  t2=t2|t6 -->再做 t2= (a[i - 1] >> 1) | tmp;   
      sw   t2,0(t1)     #  完成   a[i] = (a[i - 1] >> 1) | tmp;   (把t2存到'a[i]的address')
      

      ### i++
      addi t0,t0,1


     j Loop

     exit:

     ret
