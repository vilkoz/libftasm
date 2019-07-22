global _ft_bzero

section .data

section .text

_ft_bzero:
	push rbp
	mov rbp, rsp
	cmp rsi, 0
	je exit_null_arg

loop:
	dec rsi
	mov byte [rdi + rsi], 0
	jne loop
	
exit_null_arg:
	mov rsp, rbp
	pop rbp
	ret
