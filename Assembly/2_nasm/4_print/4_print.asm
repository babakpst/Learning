; Babak Poursartip
; 10/13/2021

; A subroutine to print a text 
; The issue with the current subroutine is that we need to include the length of the subroutine.
; To avoid this issue, we add 0 to the end of the string. 

; ===================
section .data
    ; text is the name assigned to the actual memory with this text.
    ; db stands for define bytes
    ; registers are 64 bits in x86_64 bit.
    text db "hello, world", 10,0
    text2 db "world?",10,0
section .text
    global _start
    
_start:  ; it should be there. Like main.
    ;mov rax, 1
    ;mov rdi, 1
    ;mov rsi, text
    ;mov rdx, 13
    ;syscall
    ; Indeed, this syscall will use the above arguments.

    mov rax, text
    call _print

    mov rax, text2
    call _print

    mov rax, 60
    mov rdi, 0
    syscall
    ; This is sys exit, signals the end of the code. 

; input: rax as a pointer to string
; output: print string at rax
_print:
    push rax
    mov rbx,0
_pirntLoop:
    inc rax
    inc rbx
    mov cl, [rax] ; 8 bit equivalent of rcx
    cmp cl, 0 ; end of the string
    jne _pirntLoop

    mov rax, 1
    mov rdi, 1
    pop rsi
    mov rdx, rbx ; rbx is the length now.
    syscall
    ret

