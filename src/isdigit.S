global _ft_isdigit

section .data

section .text

_ft_isdigit:
	push rbp
	push rdi
	push rsi
	mov rbp, rsp

	cmp rdi, '0'
	jl return_false
	cmp rdi, '9'
	jg return_false

return_true:
	mov rax, 1
	jmp exit
return_false:
	mov rax, 0
exit:
	mov rsp, rbp
	pop rsi
	pop rdi
	pop rbp
	ret
