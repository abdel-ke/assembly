section .data
   text db "hello world", 10
section .text
   global _print
_print:
   mov rax, 1
   mov rdi, 1
   mov rsi, text
   mov rdx, 12
   syscall

   mov rax, 60
   mov rdi, 0
   syscall