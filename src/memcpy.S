global _ft_memcpy
section .data

section .text

_ft_memcpy:
	push rbp
	push rdi ; dest string
	push rsi ; source string
	push rdx ; size
	mov rbp, rsp
	cmp rdi, 0
	je exit_null_arg
	cmp rsi, 0
	je exit_null_arg
	cmp rdx, 0
	jle exit_null_arg
	mov r8, rdi ; save initial arg_0

	mov rcx, rdx
	rep movsb

	mov rax, r8 ; return initial argument
	mov rsp, rbp
	pop rdx
	pop rdi
	pop rsi
	pop rbp
	ret

exit_null_arg:
	mov rax, 0
	mov rsp, rbp
	pop rdx
	pop rdi
	pop rsi
	pop rbp
	ret

