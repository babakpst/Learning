Title Buffer Overflow Demonstrator
;---------------------------------
include \masm32\include\masm32rt.inc 
.data  
   packet  dword 9 dup (61616161h),0040106Dh 
   Hello   db "Hello <name here>", 0 
   
.code 
start:  
    push offset Hello 
    push offset packet
    call sco   
    MsgBox 0, addr Hello, "Buffalo", MB_OK
    invoke ExitProcess, 0 
    
sco proc 
    mov ebp,esp
    mov ebx, [ebp+4]        ; name parameter
    sub sp, 32              ; make room for packet data
    mov edx, esp            ; start of name, for saving now
    mov ecx, esp            ; start of name, for reading later
nx: mov al, byte ptr [ebx]  ; let's move the packet data into local  
    mov byte ptr [edx], al  ; character at a time
    inc ebx
    inc edx
    cmp al,0                ; until we find the zero delimiter
    jnz nx

    mov edi, [ebp+8]        ; Welcome message
    add edi, 6              ; position to where we put name
s1: mov al, byte ptr [ecx]  ; get start of name from local
    mov byte ptr [edi], al  ; store it in welcome message
    inc edi
    inc ecx 
    cmp al,0                ; keep going until zero delimeter
    jnz s1 

    add sp, 32              ; release local storage
    ret 8                   ; release call parameter
sco endp

.data
    db 32 dup(0)
.code
xs: MsgBox 0, "We never get here", "Buffalo", MB_OK
    invoke ExitProcess,0     
end start
