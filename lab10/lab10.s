.data               # start of data section
# put any global or static variables here
myPrintString: .string "%d * %d = %d\n"
myDivPrintString: .string "Answer is %d\n"

.section .rodata    # start of read-only data section
# constants here, such as strings
# modifying these during runtime causes a segmentation fault, so be cautious!


.text           # start of text /code
# everything inside .text is read-only, which includes your code!
.global main  # required, tells gcc where to begin execution

# === functions here ===
divByTwo:

pushq %rbx
movq $2, %rbx
divq %rdi, %rax
cqto # convert quad to octal, sign extend rax into rdx
idivq %rbx # %rdx (%rax) / %rbx (2) --> %rax
popq %rbx

ret

main:           # start of main() function
# preamble

pushq %rbp
movq %rsp, %rbp

# === code here ===

movq $2, %rax # a = 2 in %rax
movq $3, %rbx # b = 3 in %rbx
pushq %rax # a on stack

imulq %rbx # %rax (a) * %rbx (b) --> %rax

movq $myPrintString, %rdi 
pop %rsi # pop %rax off stack
movq %rbx, %rdx
movq %rax, %rcx

movq $0, %rax
xorq %rax, %rax
call printf

xorq %rax,%rax
movq $10, %rdi
call divByTwo

movq $myDivPrintString, %rdi
movq %rax, %rsi
xorq %rax, %rax
call myDivPrintString

# return
movq $0, %rax   # place return value in rax
leave           # undo preamble, clean up the stack
ret             # return
