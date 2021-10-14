; Babak Poursartip
; 10/13/2021


section .data
    digit db 0,10

;section .bss ; to reserve data
;    name resb 16 ; reserves 16 bytes for the name. 

section .text
    global _start
_start:  ; it should be there. Like main.

    mov rax, 48    
    call _printRAXDigit

    mov rax, 7
    call _printRAXDigit
    
    mov rax, 9
    call _printRAXDigit

    mov rax, 1
    add rax, 4
    call _printRAXDigit

    mov rax, 4
    mov rbx, 1
    ;div rbx
    call _printRAXDigit
 
    push 4
    push 8
    push 3
    
    pop rax
    call _printRAXDigit

    pop rax
    call _printRAXDigit

    pop rax
    call _printRAXDigit

    mov rax, 60
    mov rdi, 0
    syscall
    ; This is sys exit, signals the end of the code. 

_printRAXDigit:
    add rax, 48
    mov [digit], al ; al takes the least significant bytes from the rax register (first 8 bit out of 6)
    mov rax, 1 
    mov rdi, 1
    mov rsi, digit
    mov rdx, 2 ;print 2 bytes.
    syscall
    ret

