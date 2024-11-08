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

  
     addi t0,zero,0  # t0=i=0


   Loop:

     bge t0,a1, exit   # if i>= len (不符合i<len) 則離開迴圈 
    
     slli t1,t0,2      #  令t1 = i*4 (因為要取的addres是4bytes單位的)
     add  t1,t1,a0     #  此時t1= 'a[i]的address'
     lw   t2,0(t1)     #  令t2=a[i]
     
     beq  t2,a2,findtarget  # 若 a[i] == target 則跳到 findtarget 
  
     addi t0,t0,1


    j Loop




     findtarget :
     
     addi a0,t0,0  #   return value a0 = i(t0)
     ret  

     exit:
      
     addi a0,zero,-1  #   return value a0 = -1
     ret  
    
