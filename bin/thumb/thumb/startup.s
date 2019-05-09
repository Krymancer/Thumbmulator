.thumb
mov r0, #3
mov r1, #5
main:
add r2, r1, r0
push {r2}
swi #10
pop {r2}
sub r2, #1
cmp r2, #0
beq fim
mov r0, r2
b main
fim:
b .
