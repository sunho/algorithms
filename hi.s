	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0
	.globl	_fib                            ## -- Begin function fib
	.p2align	4, 0x90
_fib:                                   ## @fib
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	pushq	%rax
	.cfi_def_cfa_offset 32
	.cfi_offset %rbx, -24
	.cfi_offset %rbp, -16
	movl	%edi, %ebx
	cmpl	$1, %edi
	jg	LBB0_2
## %bb.1:                               ## %recursion
	leal	-1(%rbx), %edi
	callq	_fib
	movl	%eax, %ebp
	addl	$-2, %ebx
	movl	%ebx, %edi
	callq	_fib
	movl	%eax, %ebx
	addl	%ebp, %ebx
LBB0_2:                                 ## %end
	movl	%ebx, %eax
	addq	$8, %rsp
	popq	%rbx
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$3, %edi
	callq	_fib
	leaq	L_.str(%rip), %rdi
	movl	%eax, %esi
	callq	_printf
	xorl	%eax, %eax
	popq	%rcx
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__literal4,4byte_literals
L_.str:                                 ## @.str
	.ascii	"%d\\0"

.subsections_via_symbols
