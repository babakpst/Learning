.Data
hInst	DQ	0

.Code
start:
	Invoke GetModuleHandleA, 0
	Mov [hInst], Rax
	Invoke Main
	Invoke ExitProcess, 0

Main Frame

    ret
EndF