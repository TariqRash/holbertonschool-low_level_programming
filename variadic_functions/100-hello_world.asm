section .data
    msg db "Hello, World", 10, 0
    msg_len equ $ - msg - 1

section .text
    global main
    extern printf
    extern exit

main:
    mov rax, 1
    mov rdi, 1
    mov rsi, msg
    mov rdx, msg_len
    syscall

    mov rax, 60
    mov rdi, 0
    syscall
