.Data
hInst	DQ	0
bout    dd  0
inkey   db  0,0,0
prompt  db  'Enter character: '
.Code
start:
	Invoke GetModuleHandleA, 0
	Mov [hInst], Rax
	Invoke Main
	Invoke ExitProcess, 0

Main Frame
	;=====================
	; Write your code here
	;=====================
	arg     -11
	invoke  GetStdHandle
	arg     0,addr bout
	arg     17, addr prompt
	arg     eax
	invoke  WriteFile
	arg     -10
	invoke  GetStdHandle
	arg     0,0
	arg     3, addr inkey
	arg     eax
	invoke  ReadFile
	Ret
EndF