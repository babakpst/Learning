.Const
SW_SHOW EQU 5

.Data
hInst	DQ	0
;    command  db  "C:\Windows\System32\notepad.exe",0
;    command  db  "C:\Windows\System32\cmd.exe",0
    command  db  "C:\Windows\System32\WindowsPowerShell\v1.0\powershell_ise.exe",0
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
    invoke WinExec, addr command, SW_SHOW
    ret
	
EndF
