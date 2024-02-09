.data               # start of data section
# put any global or static variables here
    output_format:  .string " %d"
    newline:        .string "\n"
    prompt:         .string "Enter the number of Fibonacci numbers to generate: "
    n:              .long 0
    fib_array:      .space 80   # Space for Fibonacci sequence (20 numbers * 4 bytes each)

.section .rodata    # start of read-only data section
# constants here, such as strings

# modifying these during runtime causes a segmentation fault, so be cautious!
.text

.globl main

main:
    # Display prompt and get user input
    mov $4, %eax                    # syscall: write
    mov $1, %ebx                    # file descriptor: stdout
    lea prompt, %ecx                # pointer to the prompt string
    mov $strlen, %edx               # length of the prompt string
    int $0x80                       # interrupt to invoke syscall

    mov $3, %eax                    # syscall: read
    mov $0, %ebx                    # file descriptor: stdin
    lea n, %ecx                     # pointer to the variable n
    mov $4, %edx                    # number of bytes to read
    int $0x80                       # interrupt to invoke syscall

    movl n, %eax                    # load the value of n
    call fib                        # generate Fibonacci sequence

    # Call the print_fibonacci function
    mov $fib_array, %ecx            # pointer to the Fibonacci sequence array
    call print_fibonacci

    # Exit the program
    mov $1, %eax                    # syscall: exit
    xor %ebx, %ebx                  # exit code 0
    int $0x80                       # interrupt to invoke syscall

print_fibonacci:
    mov (%ecx), %edx                # load the next Fibonacci number
    test %edx, %edx                 # test if the Fibonacci number is 0
    jz end_print                    # if it's 0, exit the loop

    mov $output_format, %ecx        # pointer to the output format string
    mov $0, %ebx                    # file descriptor: stdout
    mov $1, %eax                    # syscall: write
    int $0x80                       # interrupt to invoke syscall

    add $4, %ecx                    # move to the next Fibonacci number
    jmp print_fibonacci             # repeat the process

end_print:
    ret

fib:
    # Generate the first n Fibonacci numbers
    mov $0, %edi                    # fib_array[0] = 0
    mov $1, %esi                    # fib_array[1] = 1
    movl n, %ecx                    # get the value of n

generate_fibonacci:
    cmp $2, %ecx                    # compare n with 2
    jl end_generate                 # if n < 2, exit loop

    mov %edi, fib_array             # store fib_array[index] in memory

    mov %edi, %edx                  # temporarily store fib_array[index]
    add %esi, %edi                  # fib_array[index] = fib_array[index] + fib_array[index - 1]
    mov %edx, %esi                  # fib_array[index - 1] = temporarily stored value

    add $4, fib_array               # move to the next location in the array
    dec %ecx                        # decrement index
    jmp generate_fibonacci         # jump back to the beginning of the loop

end_generate:
    ret

strlen:
    # Calculate the length of a null-terminated string
    mov %edi, %ecx                  # load the address of the string into ecx
    xor %eax, %eax                  # clear eax to store the length

find_length:
    cmpb $0, (%ecx)                 # check for null terminator
    je  end_length                  # jump to end if null terminator is found
    inc %ecx                        # move to the next character
    inc %eax                        # increment the length
    jmp find_length                 # repeat the process

end_length:
    ret
