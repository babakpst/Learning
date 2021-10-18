section .bss
  digitSpace resb 100 ; reserves 100 bytes; printing many digits.
  digitSpacePos resb 8 ;  


section .text
  global _start

_start:

  mov rax, 256
  call _printRAX

  mov rax, 60
  mov rdi, 0
  syscall


_printRAX:  ; breaks the digits backward.
  mov rcx, digitSpace ; stores the string that we want to print. 
  mov rbx, 10 ; new line
  mov [rcx], rbx  ; adds a new line to the digitSpace
  inc rcx
  mov [digitSpacePos], rcx ; records how far in the string we are

_printRAXLoop: ; gets the digits of rax.
  mov rdx, 0
  mov rbx, 10
  div rbx
  push rax
  add rdx, 48
  
  mov rcx, [digitSpacePos]
  mov [rcx], dl
  inc rcx
  mov [digitSpacePos], rcx
  
  pop rax
  cmp rax, 0
  jne _printRAXLoop
  
_printRAXLoop2:
  mov rcx, [digitSpacePos]

  mov rax, 1
  mov rdi, 1
  mov rsi, rcx
  mov rdx, 1
  syscall
  
  mov rcx, [digitSpacePos]
  dec rcx
  mov [digitSpacePos], rcx
  
  cmp rcx, digitSpace
  jge _printRAXLoop2
  
  ret
