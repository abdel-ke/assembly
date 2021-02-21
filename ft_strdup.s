section .text
	global _ft_strdup
	extern _malloc
	extern _ft_strcpy
	extern _ft_strlen
_ft_strdup:
	push rdi
	call _ft_strlen
	inc rax
	call _malloc
	cmp rax, 0
	je	_err
	mov rdi, rax
	pop rsi
	call _ft_strcpy
_err:
	ret