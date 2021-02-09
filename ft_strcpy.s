section .text
    global _ft_strcpy
_ft_strcpy:
    mov rax, 0
_print:
    mov cl, [rsi + rax]
    mov [rdi + rax], cl
    cmp byte [rsi + rax], 0
    je _end
    inc rax
    jmp _print
_end:
    mov cl, 0
    mov rax, rdi
    ret