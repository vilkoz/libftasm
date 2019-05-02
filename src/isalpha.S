global _ft_isalpha

section .data

section .text

_ft_isalpha:
	push rbp
	push rdi
	push rsi
	mov rbp, rsp

	cmp rdi, 'A'
	jl return_false
	cmp rdi, 'Z'
	jle return_true
	cmp rdi, 'a'
	jl return_false
	cmp rdi, 'z'
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
