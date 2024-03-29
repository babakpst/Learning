.Data
hInst	DQ	0
;----Demo1
;align   16
;val128	db 01h,13h,2Ch,68h,0DDh,13h,7Ah,04h,0C0h,53h,77h,62h,9Ah,0FFh,00h,0B6h
;---Demo2
qmask	dq	08000800080008000h
quadin	dq	0F34A60176D229C03h
quadout	dq	0

.Code

start:
	Invoke GetModuleHandleA, 0
	Mov [hInst], Rax
	Invoke Main
	Invoke ExitProcess, 0

Main Frame
	;=====================
	; Demo 1
	;=====================
;    movaps  xmm1,[val128]
;    movhlps xmm2,xmm1
	;=====================
	; Demo 2
	;=====================
    mov			edi, addr quadout
    movq		mm0, [quadin]
    movq		mm1, [qmask]
    maskmovq	mm0, mm1

	ret
EndF
