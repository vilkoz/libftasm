global _ft_puts

section .data

line_break: db 10

section .text

_ft_puts:
	push rbp
	push rdi
	push rsi
	mov rbp, rsp
	
	mov rax, 0x2000004      ; write
	mov rsi, rdi			; output string
	mov rdi, 1				; stdout

	mov rdx, 0				; length
length_loop:
	mov byte cl, [rsi + rdx]
	inc rdx
	cmp cl, 0
	jne length_loop
	dec rdx

	syscall

	mov rax, rdx			; save return value

	mov rax, 0x2000004      ; write
	mov rdi, 1				; stdout
	mov rsi, line_break		; output string (\n)
	mov rdx, 1				; output string len
	syscall

exit:
	mov rsp, rbp
	pop rsi
	pop rdi
	pop rbp
	ret
