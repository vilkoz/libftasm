global _ft_toupper

section .data

section .text

_ft_toupper:
	push rbp
	push rdi
	push rsi
	mov rbp, rsp

	cmp rdi, 'a'
	jl not_change
	cmp rdi, 'z'
	jg not_change
	jmp change

not_change:
	mov rax, rdi
	jmp exit
change:
	sub rax, 32
exit:
	mov rsp, rbp
	pop rsi
	pop rdi
	pop rbp
	ret
