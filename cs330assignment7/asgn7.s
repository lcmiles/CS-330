.data               # start of data section
# put any global or static variables here
A: .quad 10
B: .quad 2

.section .rodata    # start of read-only data section
# constants here, such as strings
# modifying these during runtime causes a segmentation fault, so be cautious!
.printATimesFive: .string "A * 5 when A = %d is equal to %d\n"
.printAminusBPlusATimesB: .string "(A - B) + (A * B) when A = %d & B = %d is equal to %d \n"
.printAPlusBMinusADivB: .string "(A + B) - (A / B) when A = %d & B = %d is equal to %d \n"


.text           # start of text /code
# everything inside .text is read-only, which includes your code!
.global main  # required, tells gcc where to begin execution

# === functions here ===

#Description: Multiples variable A by 5
#Registers: %rdi (input variable A), %rax (output)
ATimesFive:

    push %rdi #push %rdi onto stack
    push %rsi #push %rsi onto stack

    movq $5, %rsi #move literal 5 into %rsi
    imul %rsi, %rdi #multiply int stored in %rdi by int stored in %rdsi (5) and store result in %rdi

    movq %rdi, %rax #move result in %rdi to %rax

    pop %rsi #pop %rsi off the stack
    pop %rdi #pop %rdi off the stack

    ret

#Description: Performs the operation (A + B) - (A / B)
#Registers: %rsi (input variable A), %rdi (input variable B), %rax (output)
APlusBMinusADivB:

    push %rdi #push %rdi onto stack
    push %rsi #push %rsi onto stack
    push %rdx #push %rdx onto stack
    push %rcx #push %rcx onto stack

    movq %rdi, %rdx #move int stored in %rdi into %rdx for later division

    movq %rsi, %rcx #move int stored in %rsi into %rcx for later division

    add %rdi, %rsi #add int stored in %rdi to int stored in %rsi and store result in %rsi

    movq %rdx, %rax #move the int stored in %rdx (A) into %rax for subtraction operation
    xor %rdx, %rdx #clear the register %rdx via bitwise exclusive or operation
    movq %rcx, %rdx #move the int stored in %rcx (B) into %rdx for later division
    cqto #sign-extend %rcx to %rdx for division
    idiv %rcx #integer division of %rax by %rcx (B)

    movq %rax, %rcx #move the result (A/B) into %rax for subtraction
    sub %rcx, %rsi #subtract the reslult stored in %rax (A / B) from %rcx (A + B) and store the result in %rsi
    movq %rsi, %rax #move result into %rax

    pop %rcx #pop %rcx off of the stack
    pop %rdx #pop %rdx off of the stack
    pop %rsi #pop %rsi off of the stack
    pop %rdi #pop %rdi off of the stack

    ret

#Description: Performs the operation (A - B) + (A * B)
#Registers: %rsi (input variable A), %rdi (input variable B), %rax (output)
AminusBPlusATimesB:

    push %rdi #push %rdi onto the stack
    push %rsi #push %rsi onto the stack
    push %rdx #push %rdx onto the stack
    push %rcx #push %rcx onto the stack

    movq %rdi, %rdx #move int stored in %rdi to %rdx for later multiplication

    movq %rsi, %rcx #move int stored in %rsi to %rcx for later multiplication
    
    sub %rsi, %rdi #subtract int stored in %rsi (B) from int stored in %rdi (A) and store result in %rdi

    imul %rdx, %rcx #multiply int stored in %rdx (A) by int stored in %rcx and store result in %rcx

    add %rcx, %rdi #add result stored in %rcx (A * B) to %rdi (A - B) and store result in %rdi

    movq %rdi, %rax #move result from %rdi to %rax

    pop %rcx #pop %rcx off the stack
    pop %rdx #pop %rdx off the stack
    pop %rsi #pop %rsi off the stack
    pop %rdi #pop %rdi off the stack

    ret
main:           # start of main() function
    # preamble
    pushq %rbp 
    movq %rsp, %rbp

    # === code here ===

    mov A, %rdi #move value of A into %rdi
    call ATimesFive #call ATimesFive function

    mov $.printATimesFive, %rdi #move the format string into %rdi
    mov A, %rsi #move the value of into %rsi
    mov %rax, %rdx #move the result of ATimesFive stored in %rax to %rdx
    xor %rax, %rax #clear the register %rax via bitwise exclusive or operation
    call printf #call printf to print results
    xor %rdi, %rdi #clear the register %rdi via bitwise exclusive or operation
    xor %rsi, %rsi #clear the register %rsi via bitwise exclusive or operation
    xor %rdx, %rdx #clear the register %rdx via bitwise exclusive or operation

    mov A, %rdi #move value of A into %rdi
    mov B, %rsi #move value of B into %rsi
    call APlusBMinusADivB #call APlusBMinuesADivB function

    mov $.printAPlusBMinusADivB, %rdi #move format string into %rdi
    mov A, %rsi #move value of A into %rsi
    mov B, %rdx #move value of B into %rdx
    mov %rax, %rcx #move result of APlusBMinuesADivB stored in %rax into %rcx
    xor %rax, %rax #clear the register %rax via bitwise exclusive or operation
    call printf #call printf to print results
    xor %rdi, %rdi #clear the register %rdi via bitwise exclusive or operation
    xor %rsi, %rsi #clear the register %rsi via bitwise exclusive or operation
    xor %rdx, %rdx #clear the register %rdx via bitwise exclusive or operation
    xor %rcx, %rcx #clear the register %rcx via bitwise exclusive or operation

    mov A, %rdi #move value of A into %rdi
    mov B, %rsi #move value of A into %rsi
    call AminusBPlusATimesB #call AminusBPlusATimesB function

    mov $.printAminusBPlusATimesB, %rdi #move the format string into %rdi
    mov A, %rsi #move the value of A into %rsi
    mov B, %rdx #move the value of B into %rdx
    mov %rax, %rcx #move the result of the AminusBPlusATimesB into %rcx
    xor %rax, %rax #clear the register %rax via bitwise exclusive or operation
    call printf #call printf to print results

    # return
    movq $0, %rax   # place return value in rax
    leave           # undo preamble, clean up the stack
    ret             # return
