.Data
hInst	DQ	0
var1	dq	31
var2	dq	678
var3	dq	251
vardex  dd    3

.Code

start:
	Invoke GetModuleHandleA, 0
	Mov [hInst], Rax
	Invoke Main
	Invoke ExitProcess, 0

Main Frame
	;=====================
	;  Demo 1
  	;=====================
    mov  rax, [var1]
    mov  ecx, addr var1
    mov  rbx, [ecx]
	;=====================
	;  Demo 2
  	;=====================
    mov  edx,[vardex]
    dec  edx
    shl  edx,3
	mov  rbx, [ecx+edx]
	;=====================
	;  Demo 3
  	;=====================
    mov   edx, addr var3
    mov   b[edx], 0FFh
	;=====================
	;  Demo 4
  	;=====================
    lea  edx, var2
    mov  edx, addr var2
    lea  edx, [var1+vardex*8-8]
    mov  eax,[edx]
    ret
EndF
