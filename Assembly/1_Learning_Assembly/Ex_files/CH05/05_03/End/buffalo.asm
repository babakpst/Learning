Title Buffer Overflow Demonstrator
;---------------------------------
include \masm32\include\masm32rt.inc 
.data  
packet   dword 9 dup (61616161h)
returner dword 00404028h
payload  byte  68h,33h,40h,40h,00h,68h,34h,10h,40h,00h,0C3h,
               49h,27h,76h,65h,20h,62h,65h,65h,6Eh,20h,42h,75h,
               66h,66h,61h,6Ch,6Fh,27h,64h,21h,00h
Hello    db "Hello <name here>", 0 
   
.code 
start:  
    push offset Hello 
    push offset packet
    call   mcon    
    invoke StdOut, addr Hello
    invoke ExitProcess, 0 
	
;=======================
; Message constructor
;=======================
mcon proc 
    push ebp
    mov  ebp,esp
    mov  ebx, [ebp+8]              ; name parameter
    sub  esp, 32                   ; make room for packet data
    mov  edx, esp                  ; start of name, for saving now
    mov  esi, esp                  ; start of name, for reading later
mcon1: 
    mov  al, byte ptr [ebx]        ; let's move the packet data into local  
    mov  byte ptr [edx], al        ; character at a time...
    inc  ebx
    inc  edx
    cmp  al,0                      ; ....until we find the zero delimiter
    jnz  mcon1

    mov  edi, [ebp+12]             ; Welcome message
    add  edi, 6                    ; position to where we put name
mcon2: 
    mov  al, byte ptr [esi]        ; get start of name from local
    mov  byte ptr [edi], al        ; store it in welcome message
    inc  edi
    inc  esi 
    cmp  al,0                      ; keep going until zero delimeter
    jnz  mcon2 

    mov  esp,ebp                   ; release local storage
    pop  ebp
    ret  8                         ; release call parameter
mcon endp

end start