global _ft_tolower

section .data

section .text

_ft_tolower:
	push rbp
	push rdi
	push rsi
	mov rbp, rsp

	cmp rdi, 'A'
	jl not_change
	cmp rdi, 'Z'
	jg not_change
	jmp change

not_change:
	mov rax, rdi
	jmp exit
change:
	mov rax, rdi
	add rax, 32
exit:
	mov rsp, rbp
	pop rsi
	pop rdi
	pop rbp
	ret
