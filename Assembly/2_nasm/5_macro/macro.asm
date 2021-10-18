; Babak Poursartip
; 10/16/2021

%include "myMacro.asm"

section .data
    text db "hello, world", 10
    digit db 0,10

section .text
    global _start
    
_start:
    mov rax, SYS_WRITE
    mov rdi, STDOUT
    mov rsi, text
    mov rdx, 13
    syscall

    mov rax, 1   
    call _printRAXDigit

    printDigit 3

    printDigitSum 3,4
    exit

_printRAXDigit:
    add rax, 48
    mov [digit], al ; al takes the least significant bytes from the rax register (first 8 bit out of 6)
    mov rax, 1 
    mov rdi, 1
    mov rsi, digit
    mov rdx, 2 ;print 2 bytes.
    syscall
    ret
