
mov a,#127
setb p3.2
setb p3.3
setb p2.0

loop:
mov p1,a
jnb p3.2,left
jnb p3.3,right
jnb p2.0,debounce


sjmp loop 

debounce:

acall function

wait:
jnb p2.0,wait
rl a

acall function

sjmp loop

left:
rr a

mov r0,#3
delay0:
acall function
djnz r0,delay0

sjmp loop

right:
rl a

mov r3,#3
delay3:
acall function
djnz r3,delay3

sjmp loop


function:
mov r6,#255
delay6:
mov r7,#255
delay7:
djnz r7,delay7
djnz r6,delay6
ret

end