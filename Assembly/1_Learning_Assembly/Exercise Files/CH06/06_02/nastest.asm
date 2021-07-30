section .data
  welcome: db  "Welcome to Nasm",0x0D,0x0A
  wlen:    equ $-welcome
           db  0
section .bss
  numb:    resb 3

section .text
global _start
_start:
  mov  rax,1
  mov  rsi,welcome
  mov  rdx,wlen
  syscall

  mov  byte [numb],0x31
  mov  byte [numb+1],0x0D
  mov  byte [numb+2],0x0A
loop:
  mov  rax,1
  mov  rsi,numb
  mov  rdx,3
  syscall
  inc  byte [numb]
  cmp  byte [numb],0x3A
  jne  loop

byebye:
  mov  rax,60
  xor  rdi,rdi
  syscall
