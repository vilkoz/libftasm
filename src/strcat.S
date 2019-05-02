global _ft_strcat

section .data

section .text

_ft_strcat:
	push rbp
	push rdi
	push rsi
	mov rbp, rsp
	cmp rsi, 0
	je exit_null_arg
	cmp rdi, 0
	je exit_null_arg

	mov rax, rdi
search_s1_end_loop:
	inc rdi
	cmp byte [rdi], 0
	jne search_s1_end_loop

copy_s2_to_s1_loop:
	mov byte cl, [rsi]
	mov byte [rdi], cl
	inc rdi
	inc rsi
	cmp byte [rsi], 0
	jne copy_s2_to_s1_loop

	mov byte [rdi], 0
	
	mov rsp, rbp
	pop rsi
	pop rdi
	pop rbp
	ret

exit_null_arg:
	mov rax, 0
	mov rsp, rbp
	pop rsi
	pop rdi
	pop rbp
	ret
