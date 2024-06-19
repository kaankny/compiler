global main
extern printf

section .text

main:
	sub rsp, 60

	mov r8, 12

	mov r9, 3

	imul r8, r9

	lea rcx, [rel format]
	mov rdx, r8
	call printf

	mov r8, 18

	mov r9, 2

	mov r10, 4

	imul r9, r10

	sub r8, r9

	lea rcx, [rel format]
	mov rdx, r8
	call printf

	mov r8, 1

	mov r9, 2

	add r8, r9

	mov r9, 9

	add r8, r9

	mov r9, 5

	mov r10, 2

	mov rax, r9
	cqo
	idiv r10
	mov r9, rax

	sub r8, r9

	mov r9, 3

	mov r10, 5

	imul r9, r10

	add r8, r9

	lea rcx, [rel format]
	mov rdx, r8
	call printf

	add rsp, 60
	ret

section .data
	format db "%d", 10, 0

