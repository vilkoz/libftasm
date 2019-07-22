global _ft_toupper

section .data

section .text

_ft_toupper:
	push rbp
	push rdi
	push rsi
	mov rbp, rsp

	cmp dil, 'a'
	jl not_change
	cmp dil, 'z'
	jg not_change
	jmp change

not_change:
	mov eax, edi
	jmp exit
change:
	mov eax, edi
	sub eax, 32
exit:
	mov rsp, rbp
	pop rsi
	pop rdi
	pop rbp
	ret
