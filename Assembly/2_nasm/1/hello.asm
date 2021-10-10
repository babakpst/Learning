; Babak Poursartip
; 10/9/2021

; There are three sections in x86 assembly
;    1- .data: where all the data is being defined, before the execution.
;    2- .bss: where the data is allocated for future use.
;    3- .text: the actual code.

; We have LABELS in the code:
; We have _start.
; We have global.


; ===================
section .data
    ; text is the name assigned to the actual memory with this text.
    ; db stands for define bytes
    ; registers are 64 bits in x86_64 bit.
    text db "hello, world", 10
section .text
    global _start
    
_start:  ; it should be there. Like main.
    mov rax, 1
    mov rdi, 1
    mov rsi, text
    mov rdx, 13
    syscall
    ; Indeed, this syscall will use the above arguments.

    

    mov rax, 60
    mov rdi, 0
    syscall
    ; This is sys exit, signals the end of the code. 
