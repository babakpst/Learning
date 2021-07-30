global nasum
section .data
section .text
nasum:
    lea   rax,[rdi+rsi]
    ret 
