; Babak Poursartip
; 10/12/2021


section .data
    text1 db "What is your name? "
    text2 db "Hello, "

section .bss ; to reserve data
    name resb 16 ; reserves 16 bytes for the name. 

section .text
    global _start
_start:  ; it should be there. Like main.
    
    call _printText1
    call _getName
    call _printText2
    call _printName

    mov rax, 60
    mov rdi, 0
    syscall
    ; This is sys exit, signals the end of the code. 


_printText1:
    mov rax, 1 
    mov rdi, 1
    mov rsi, text1
    mov rdx, 19
    syscall
    ret

_printText2:
    mov rax, 1
    mov rdi, 1
    mov rsi, text2
    mov rdx, 7
    syscall
    ret

_printName:
    mov rax, 1
    mov rdi, 1
    mov rsi, name
    mov rdx, 16
    syscall
    ret

_getName:
  mov rax, 0 ; To get the user input, the ID is 0.
  mov rdi, 0
  mov rsi, name
  mov rdx, 16
  syscall
  ret