
STDIN equ 0
STDOUT equ 1
STDERR equ 2

SYS_READ equ 0
SYS_WRITE equ 1
SYS_EXIT equ 60

%macro exit 0
    mov rax, SYS_EXIT
    mov rdi, 0
    syscall
%endmacro

%macro printDigit 1
    mov rax, %1
    call _printRAXDigit
%endmacro

%macro printDigitSum 2 ; this is the number of input arguments
  mov rax, %1
  add rax, %2
  call _printRAXDigit
%endmacro
