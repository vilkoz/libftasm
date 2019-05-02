global _ft_isalnum

section .data

section .text

_ft_isalnum:
	push rbp
	push rdi
	push rsi
	mov rbp, rsp

	cmp rdi, '0'
	jl return_false
	cmp rdi, '9'
	jl return_true
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
