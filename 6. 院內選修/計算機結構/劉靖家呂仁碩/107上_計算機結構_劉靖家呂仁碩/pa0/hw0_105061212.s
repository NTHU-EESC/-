	.file	"test.c"
	.option nopic
	.globl	student
	.data
	.align	3
	.type	student, @object
	.size	student, 288
student:
	.string	"Marry Hu"
	.zero	1
	.byte	65
	.zero	1
	.word	86
	.word	1
	.word	3
	.word	89
	.word	90
	.word	79
	.string	"Tim Chen"
	.zero	1
	.byte	66
	.zero	1
	.word	86
	.word	12
	.word	13
	.word	79
	.word	69
	.word	88
	.string	"Backy Wu"
	.zero	1
	.byte	65
	.zero	1
	.word	87
	.word	2
	.word	28
	.word	81
	.word	61
	.word	66
	.string	"John Hsu"
	.zero	1
	.byte	65
	.zero	1
	.word	87
	.word	7
	.word	22
	.word	69
	.word	88
	.word	72
	.string	"Tom Sun"
	.zero	2
	.byte	66
	.zero	1
	.word	87
	.word	6
	.word	8
	.word	77
	.word	62
	.word	89
	.string	"May Chen"
	.zero	1
	.byte	66
	.zero	1
	.word	88
	.word	8
	.word	27
	.word	78
	.word	93
	.word	91
	.string	"Amy Chu"
	.zero	2
	.byte	65
	.zero	1
	.word	87
	.word	5
	.word	16
	.word	82
	.word	73
	.word	68
	.string	"Ann Wang"
	.zero	1
	.byte	65
	.zero	1
	.word	87
	.word	9
	.word	28
	.word	66
	.word	79
	.word	78
	.section	.rodata
	.align	3
.LC0:
	.string	"The best English score student is %s\n"
	.align	3
.LC1:
	.string	"The average Math score of class A %.2f\n"
	.align	3
.LC2:
	.string	"The average Math score of class B %.2f\n"
	.align	3
.LC3:
	.string	"This month birthday student is"
	.align	3
.LC4:
	.string	"The highest average score student is %s\n"
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	add	sp,sp,-16
	sd	ra,8(sp)
	sd	s0,0(sp)
	add	s0,sp,16
	lui	a5,%hi(student)
	addi	a0,a5,%lo(student)
	call	max_eng
	mv	a5,a0
	mv	a4,a5
	mv	a5,a4
	sll	a5,a5,3
	add	a5,a5,a4
	sll	a5,a5,2
	lui	a4,%hi(student)
	addi	a4,a4,%lo(student)
	add	a5,a5,a4
	mv	a1,a5
	lui	a5,%hi(.LC0)
	addi	a0,a5,%lo(.LC0)
	call	printf
	li	a1,65
	lui	a5,%hi(student)
	addi	a0,a5,%lo(student)
	call	avg_math
	fmv.s	fa5,fa0
	fcvt.d.s	fa5,fa5
	fmv.x.d	a1,fa5
	lui	a5,%hi(.LC1)
	addi	a0,a5,%lo(.LC1)
	call	printf
	li	a1,66
	lui	a5,%hi(student)
	addi	a0,a5,%lo(student)
	call	avg_math
	fmv.s	fa5,fa0
	fcvt.d.s	fa5,fa5
	fmv.x.d	a1,fa5
	lui	a5,%hi(.LC2)
	addi	a0,a5,%lo(.LC2)
	call	printf
	lui	a5,%hi(.LC3)
	addi	a0,a5,%lo(.LC3)
	call	puts
	li	a1,12
	lui	a5,%hi(student)
	addi	a0,a5,%lo(student)
	call	happy_birthday
	lui	a5,%hi(student)
	addi	a0,a5,%lo(student)
	call	max_grade
	mv	a5,a0
	mv	a4,a5
	mv	a5,a4
	sll	a5,a5,3
	add	a5,a5,a4
	sll	a5,a5,2
	lui	a4,%hi(student)
	addi	a4,a4,%lo(student)
	add	a5,a5,a4
	mv	a1,a5
	lui	a5,%hi(.LC4)
	addi	a0,a5,%lo(.LC4)
	call	printf
	li	a5,0
	mv	a0,a5
	ld	ra,8(sp)
	ld	s0,0(sp)
	add	sp,sp,16
	jr	ra
	.size	main, .-main
	.align	1
	.globl	max_eng
	.type	max_eng, @function
max_eng:
	add	sp,sp,-48
	sd	s0,40(sp)
	add	s0,sp,48
	sd	a0,-40(s0)
	sw	zero,-24(s0)
	ld	a5,-40(s0)
	lw	a5,32(a5)
	sw	a5,-28(s0)
	li	a5,1
	sw	a5,-20(s0)
	j	.L4
.L6:
	lw	a4,-20(s0)
	mv	a5,a4
	sll	a5,a5,3
	add	a5,a5,a4
	sll	a5,a5,2
	mv	a4,a5
	ld	a5,-40(s0)
	add	a5,a5,a4
	lw	a4,32(a5)
	lw	a5,-28(s0)
	sext.w	a5,a5
	bge	a5,a4,.L5
	lw	a4,-20(s0)
	mv	a5,a4
	sll	a5,a5,3
	add	a5,a5,a4
	sll	a5,a5,2
	mv	a4,a5
	ld	a5,-40(s0)
	add	a5,a5,a4
	lw	a5,32(a5)
	sw	a5,-28(s0)
	lw	a5,-20(s0)
	sw	a5,-24(s0)
.L5:
	lw	a5,-20(s0)
	addw	a5,a5,1
	sw	a5,-20(s0)
.L4:
	lw	a5,-20(s0)
	sext.w	a4,a5
	li	a5,7
	ble	a4,a5,.L6
	lw	a5,-24(s0)
	mv	a0,a5
	ld	s0,40(sp)
	add	sp,sp,48
	jr	ra
	.size	max_eng, .-max_eng
	.align	1
	.globl	avg_math
	.type	avg_math, @function
avg_math:
	add	sp,sp,-48
	sd	s0,40(sp)
	add	s0,sp,48
	sd	a0,-40(s0)
	mv	a5,a1
	sb	a5,-41(s0)
	sw	zero,-24(s0)
	sw	zero,-28(s0)
	lbu	a5,-41(s0)
	and	a4,a5,0xff
	li	a5,65
	bne	a4,a5,.L9
	sw	zero,-20(s0)
	j	.L10
.L12:
	lw	a4,-20(s0)
	mv	a5,a4
	sll	a5,a5,3
	add	a5,a5,a4
	sll	a5,a5,2
	mv	a4,a5
	ld	a5,-40(s0)
	add	a5,a5,a4
	lbu	a5,10(a5)
	mv	a4,a5
	li	a5,65
	bne	a4,a5,.L11
	lw	a4,-20(s0)
	mv	a5,a4
	sll	a5,a5,3
	add	a5,a5,a4
	sll	a5,a5,2
	mv	a4,a5
	ld	a5,-40(s0)
	add	a5,a5,a4
	lw	a5,28(a5)
	fcvt.s.w	fa5,a5
	flw	fa4,-28(s0)
	fadd.s	fa5,fa4,fa5
	fsw	fa5,-28(s0)
	lw	a5,-24(s0)
	addw	a5,a5,1
	sw	a5,-24(s0)
.L11:
	lw	a5,-20(s0)
	addw	a5,a5,1
	sw	a5,-20(s0)
.L10:
	lw	a5,-20(s0)
	sext.w	a4,a5
	li	a5,7
	ble	a4,a5,.L12
	j	.L13
.L9:
	lbu	a5,-41(s0)
	and	a4,a5,0xff
	li	a5,66
	bne	a4,a5,.L13
	sw	zero,-20(s0)
	j	.L14
.L16:
	lw	a4,-20(s0)
	mv	a5,a4
	sll	a5,a5,3
	add	a5,a5,a4
	sll	a5,a5,2
	mv	a4,a5
	ld	a5,-40(s0)
	add	a5,a5,a4
	lbu	a5,10(a5)
	mv	a4,a5
	li	a5,66
	bne	a4,a5,.L15
	lw	a4,-20(s0)
	mv	a5,a4
	sll	a5,a5,3
	add	a5,a5,a4
	sll	a5,a5,2
	mv	a4,a5
	ld	a5,-40(s0)
	add	a5,a5,a4
	lw	a5,28(a5)
	fcvt.s.w	fa5,a5
	flw	fa4,-28(s0)
	fadd.s	fa5,fa4,fa5
	fsw	fa5,-28(s0)
	lw	a5,-24(s0)
	addw	a5,a5,1
	sw	a5,-24(s0)
.L15:
	lw	a5,-20(s0)
	addw	a5,a5,1
	sw	a5,-20(s0)
.L14:
	lw	a5,-20(s0)
	sext.w	a4,a5
	li	a5,7
	ble	a4,a5,.L16
.L13:
	lw	a5,-24(s0)
	fcvt.s.w	fa5,a5
	flw	fa4,-28(s0)
	fdiv.s	fa5,fa4,fa5
	fmv.s	fa0,fa5
	ld	s0,40(sp)
	add	sp,sp,48
	jr	ra
	.size	avg_math, .-avg_math
	.align	1
	.globl	happy_birthday
	.type	happy_birthday, @function
happy_birthday:
	add	sp,sp,-48
	sd	ra,40(sp)
	sd	s0,32(sp)
	add	s0,sp,48
	sd	a0,-40(s0)
	mv	a5,a1
	sw	a5,-44(s0)
	sw	zero,-20(s0)
	j	.L19
.L21:
	lw	a4,-20(s0)
	mv	a5,a4
	sll	a5,a5,3
	add	a5,a5,a4
	sll	a5,a5,2
	mv	a4,a5
	ld	a5,-40(s0)
	add	a5,a5,a4
	lw	a4,16(a5)
	lw	a5,-44(s0)
	sext.w	a5,a5
	bne	a5,a4,.L20
	lw	a4,-20(s0)
	mv	a5,a4
	sll	a5,a5,3
	add	a5,a5,a4
	sll	a5,a5,2
	mv	a4,a5
	ld	a5,-40(s0)
	add	a5,a5,a4
	mv	a0,a5
	call	puts
.L20:
	lw	a5,-20(s0)
	addw	a5,a5,1
	sw	a5,-20(s0)
.L19:
	lw	a5,-20(s0)
	sext.w	a4,a5
	li	a5,7
	ble	a4,a5,.L21
	nop
	ld	ra,40(sp)
	ld	s0,32(sp)
	add	sp,sp,48
	jr	ra
	.size	happy_birthday, .-happy_birthday
	.align	1
	.globl	max_grade
	.type	max_grade, @function
max_grade:
	add	sp,sp,-48
	sd	s0,40(sp)
	add	s0,sp,48
	sd	a0,-40(s0)
	sw	zero,-28(s0)
	ld	a5,-40(s0)
	lw	a4,24(a5)
	ld	a5,-40(s0)
	lw	a5,28(a5)
	addw	a5,a4,a5
	sext.w	a4,a5
	ld	a5,-40(s0)
	lw	a5,32(a5)
	addw	a5,a4,a5
	sw	a5,-24(s0)
	li	a5,1
	sw	a5,-20(s0)
	j	.L23
.L25:
	lw	a4,-20(s0)
	mv	a5,a4
	sll	a5,a5,3
	add	a5,a5,a4
	sll	a5,a5,2
	mv	a4,a5
	ld	a5,-40(s0)
	add	a5,a5,a4
	lw	a3,24(a5)
	lw	a4,-20(s0)
	mv	a5,a4
	sll	a5,a5,3
	add	a5,a5,a4
	sll	a5,a5,2
	mv	a4,a5
	ld	a5,-40(s0)
	add	a5,a5,a4
	lw	a5,28(a5)
	addw	a5,a3,a5
	sext.w	a3,a5
	lw	a4,-20(s0)
	mv	a5,a4
	sll	a5,a5,3
	add	a5,a5,a4
	sll	a5,a5,2
	mv	a4,a5
	ld	a5,-40(s0)
	add	a5,a5,a4
	lw	a5,32(a5)
	addw	a5,a3,a5
	sext.w	a4,a5
	lw	a5,-24(s0)
	sext.w	a5,a5
	bge	a5,a4,.L24
	lw	a4,-20(s0)
	mv	a5,a4
	sll	a5,a5,3
	add	a5,a5,a4
	sll	a5,a5,2
	mv	a4,a5
	ld	a5,-40(s0)
	add	a5,a5,a4
	lw	a3,24(a5)
	lw	a4,-20(s0)
	mv	a5,a4
	sll	a5,a5,3
	add	a5,a5,a4
	sll	a5,a5,2
	mv	a4,a5
	ld	a5,-40(s0)
	add	a5,a5,a4
	lw	a5,28(a5)
	addw	a5,a3,a5
	sext.w	a3,a5
	lw	a4,-20(s0)
	mv	a5,a4
	sll	a5,a5,3
	add	a5,a5,a4
	sll	a5,a5,2
	mv	a4,a5
	ld	a5,-40(s0)
	add	a5,a5,a4
	lw	a5,32(a5)
	addw	a5,a3,a5
	sw	a5,-24(s0)
	lw	a5,-20(s0)
	sw	a5,-28(s0)
.L24:
	lw	a5,-20(s0)
	addw	a5,a5,1
	sw	a5,-20(s0)
.L23:
	lw	a5,-20(s0)
	sext.w	a4,a5
	li	a5,7
	ble	a4,a5,.L25
	lw	a5,-28(s0)
	mv	a0,a5
	ld	s0,40(sp)
	add	sp,sp,48
	jr	ra
	.size	max_grade, .-max_grade
	.ident	"GCC: (GNU) 7.1.1 20170509"
