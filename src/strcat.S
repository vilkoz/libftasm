global _ft_strcat

section .data

section .text

_ft_strcat:
	push rbp
	mov rbp, rsp

search_s1_end_loop:
	inc rsi
	cmp byte [rsi], 0
	jne search_s1_end_loop

copy_s2_to_s1_loop:
	mov byte al, [rdi]
	mov byte [rsi], al
	inc rsi
	inc rdi
	cmp byte [rdi], 0
	jne copy_s2_to_s1_loop
	
	mov rsp, rbp
	pop rbp
	ret
