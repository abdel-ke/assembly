section .text
   global _ft_strlen
_ft_strlen:
   xor rax, rax
_test:
   cmp [rdi + rax], byte 0
   jz _end
   inc rax
   jmp _test
_end:
   ret