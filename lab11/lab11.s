.data               # start of data section
# put any global or static variables here
myX: .quad 0
myY: .quad 0

.section .rodata    # start of read-only data section
# constants here, such as strings
# modifying these during runtime causes a segmentation fault, so be cautious!
printString: .string "Answer is %d\n"
scanString: .string "%d"
scanString2: .string "%d"


.text               # start of text /code
# everything inside .text is read-only, which includes your code!
.global main        # required, tells gcc where to begin execution

# === functions here ===

pow:
    movq $0, %rcx
    movq $1, %rax

    _forLoop: #for (int i=0;i<y;i++)
        imulq %rdi #rdi(x) * rax(answer) --> rax(answer)
        inc %rcx #i++ in rcx
        cmpq %rsi, %rcx #rcx(i) - rsi(y), setting eflags
        jl _forLoop #if rcx(i) < rsi(y) jump back to top of loop

    ret

main:               # start of main() function
    # preamble
    pushq %rbp
    movq %rsp, %rbp

    movq $scanString2, %rdi
    movq $myX, %rsi
    xorq %rax, %rax
    call scanf

    movq $scanString, %rdi
    movq $myY, %rsi
    xorq %rax, %rax
    call scanf

    # === main() code here ===

    movq myX, %rdi
    movq myY, %rsi
    xorq %rax, %rax
    call pow

    movq $printString, %rdi
    movq %rax, %rsi
    xorq %rax,%rax
    call printf

    # clean up and return
    movq $0, %rax       # place return value in rax
    leave               # undo preamble, clean up the stack
    ret                 # return
