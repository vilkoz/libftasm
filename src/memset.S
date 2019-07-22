global _ft_memset
section .data

section .text

_ft_memset:
	push rbp
	push rdi ; target string
	push rsi ; char set
	push rdx ; count
	mov rbp, rsp
	cmp rdi, 0
	je exit_null_arg
	mov r8, rdi ; save initial arg_0

	mov rcx, rdx
	mov rax, rsi
	repne stosb

	dec rdi
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

