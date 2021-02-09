section .text
   global _ft_strlen
_ft_strlen:
   mov rax, 0
_test:
   cmp [rdi + rax], byte 0
   je _end
   inc rax
   jmp _test
_end:
   ret