.name  "hohoho"
.comment "Santa in da house"

deff:
	fork %:init
	live %:live
	st		r16, -8
	st		r16, -50
	st		r16, -42
	st		r16, -51
	st		r16, -60
	st		r16, -69
	st		r16, -78
	st		r16, -87
	st		r16, -96
	st		r16, -105
	st		r16, -114
	st		r16, -123
	st		r16, -132
	st		r16, -141
	st		r16, -150
	st		r16, -159
	live %:live
	ld %0, r16
	zjmp %:deff

init:
	live %:live
	fork %:pisatel
	live %:live
	ld %23, r10
	sti r10, %:live, %22
	sti r1, %:live, %18

spy:
	ld %40, r11
	fork %:live
	live %:live
	lfork %500
	live %:live
	lfork %1500
	live %:live
	lfork %2500
	live %:live
	lfork %3000
	ld %0, r16
	live %:live
	zjmp %:spy

pisatel:
	ldi %:l2, %0, r2
	sti r2, %:l2, %40
	ldi %:l2, %4, r3
	sti r3, %:l2, %44

pisatel2:
	ldi %:l2, %7, r4
	sti r4, %:l2, %47
	ldi %:l2, %11, r5
	sti r5, %:l2, %51

pisatel3:
	ldi %:l2, %19, r6
	sti r6, %:l2, %54

pisatel4:
	ldi %:l2, %22, r7
	sti r7, %:l2, %57
	ldi %:l2, %26, r8
	sti r8, %:l2, %61
	ld %0, r16
	live %48
	zjmp %:pisatel

l2:
	sti r1, %:live, %1
	ldi %:l2, %11, r9

live:	
	live %4
	ld %0, r16
	zjmp %:l2
