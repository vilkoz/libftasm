global _ft_bzero

section .data

section .text

_ft_bzero:
	push rbp
	mov rbp, rsp

loop:
	dec rsi
	mov byte [rdi + rsi], 0
	jne loop
	
	mov rsp, rbp
	pop rbp
	ret
