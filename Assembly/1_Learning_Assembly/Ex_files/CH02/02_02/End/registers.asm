.const
trouble  equ  0ABADDEEDh
.data
buffer   db  'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
bword    dw  25
bdouble  dd  0DEADBEEFh
.code
start:
    mov al,[buffer]
    mov al,[buffer+1]
    mov ax,bword
    mov eax,bdouble
    mov eax,trouble
    mov bdouble,eax 
    ret
end start