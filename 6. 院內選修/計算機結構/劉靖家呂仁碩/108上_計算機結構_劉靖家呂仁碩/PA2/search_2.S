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

    addi t0,zero,0  # t0=i=0


     Loop:

     bge t0,a1, exit   # if i>= len (不符合i<len) 則離開迴圈 
    
     slli t1,t0,2      #  令t1 = i*4 (因為要取的addres是4bytes單位的)
     add  t1,t1,a0     #  此時t1= 'a[i]的address'

     ### 第一次 [i]
     lw   t2,0(t1)   
     beq  t2,a2,findtarget1 

     ### 第二次  [i+1]
     lw   t2,4(t1)     
     beq  t2,a2,findtarget2
   
     ### 第三次  [i+2]
     lw   t2,8(t1)   
     beq  t2,a2,findtarget3 

     ### 第四次  [i+3]
     lw   t2,12(t1)    
     beq  t2,a2,findtarget4
  
     addi t0,t0,4


    j Loop


     # 使用4種find target的狀況 才能判斷i是多少 

     findtarget1 :
     
     addi a0,t0,0  #   return value a0 = i
     ret  
   
     
     findtarget2 :
     
     addi a0,t0,1  #   return value a0 = i+1
     ret  


     findtarget3 :
     
     addi a0,t0,2  #   return value a0 = i+2
     ret  


     findtarget4 :
     
     addi a0,t0,3  #   return value a0 = i+3
     ret  

     exit:
      
     addi a0,zero,-1  #   return value a0 = -1
     ret  
    