.Data
hInst	DQ		0
msg  db  "Valhalla",0
fmt  db  "The norse gods live in %s",0Ah,0

.Code
start:
	Invoke GetModuleHandleA,0
	Mov [hInst], Rax
	Invoke Main
	Invoke ExitProcess, 0

Main Frame
	;=====================
	; Write your code here
	;=====================
    invoke printf,addr fmt,addr msg,0		; output the formatted line
	Ret
EndF

