	.file	"pre.cpp"
	.text
	.p2align 4,,15
	.globl	_Z3logPKc
	.type	_Z3logPKc, @function
_Z3logPKc:
.LFB0:
	.cfi_startproc
	movq	%rdi, %rax
	ret
	.cfi_endproc
.LFE0:
	.size	_Z3logPKc, .-_Z3logPKc
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
