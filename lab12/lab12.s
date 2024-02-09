.data               # start of data section
# put any global or static variables here

myArr: .quad 1, 2, 3, 4, 5

.section .rodata    # start of read-only data section
# constants here, such as strings
# modifying these during runtime causes a segmentation fault, so be cautious!

myArrSize: .quad 5
printString: .string "%d\n"


.text               # start of text /code
# everything inside .text is read-only, which includes your code!
.global main        # required, tells gcc where to begin execution

# === functions here ===

printArray:

    movq %rdi, %rax
    movq %rsi, %rbx
    movq $0, %rcx

    _loopStart:
    
    pushq %rax
    pushq %rbx
    pushq %rcx

    movq $printString, %rdi
    movq (%rax, %rcx, 8), %rsi
    xorq %rax, %rax
    call printf

    popq %rcx
    popq %rbx
    popq %rax

    inc %rcx

    cmpq %rbx, %rcx
    jl _loopStart

    ret

main:               # start of main() function
    # preamble
    pushq %rbp
    movq %rsp, %rbp

    movq $myArr, %rax
    movq $1, %rcx
    movq $10, (%rax, %rcx, 8)


    movq $40, %rdi
    xorq %rax, %rax
    call malloc

    movq $2, %rcx
    movq $42, (%rax, %rcx, 8)


    # === main() code here ===

    movq $myArr, %rdi
    movq %rax, %rdi
    movq (myArrSize), %rsi
    xorq %rax, %rax
    call printArray

    # clean up and return
    movq $0, %rax       # place return value in rax
    leave               # undo preamble, clean up the stack
    ret                 # return
