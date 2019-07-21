global _ft_strlen
section .data

section .text

_ft_strlen:
	push rbp
	push rdi
	mov rbp, rsp
	cmp rdi, 0
	je exit_null_arg
	mov r8, rdi ; save initial arg_0

search_loop:
	mov rcx, 4096 ; search for one page at time
	mov al, 0
	repne scasb
	cmp rcx, 0
	je search_loop

	dec rdi
	sub rdi, r8 ; calc distance to the first \0
	mov rax, rdi
	mov rsp, rbp
	pop rdi
	pop rbp
	ret

exit_null_arg:
	mov rax, 0
	mov rsp, rbp
	pop rdi
	pop rbp
	ret

