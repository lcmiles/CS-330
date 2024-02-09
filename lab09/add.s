.data               # start of data section
# put any global or static variables here

.section .rodata    # start of read-only data section
# constants here, such as strings
# modifying these during runtime causes a segmentation fault, so be cautious!
printString: .string "a=$\%d, b=%d, a+b=%d\n"


.text               # start of text /code
# everything inside .text is read-only, which includes your code!
.global main        # required, tells gcc where to begin execution

# === functions here ===
special_add:
push %rdi
push %rsi

add %rdi, %rsi
mov %rsi, %rax

pop %rsi
pop %rdi

ret

main:               # start of main() function
# preamble
pushq %rbp
movq %rsp, %rbp

# === main() code here ===
mov $3, %rdi
mov $2, %rsi
xor %rax, %rax
call special_add

mov $printString, %rdi
mov $3, %rsi
mov $2, %rdx
mov %rax, %rcx
xor %rax, %rax
call printf


# clean up and return
movq $0, %rax       # place return value in rax
leave               # undo preamble, clean up the stack
ret                 # return
