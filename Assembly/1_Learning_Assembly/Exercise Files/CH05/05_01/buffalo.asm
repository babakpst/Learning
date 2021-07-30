Title Buffer Overflow Demonstrator
;---------------------------------
include \masm32\include\masm32rt.inc 
.data  
   packet  db "Magnus",0 
   Hello    db "Hello <name here>", 0 
   
include ECProtos.inc ; .Code
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
    mov  ebx, [ebp+8]                ; name parameter
    sub   esp, 32                          ; make room for packet data
    mov  edx, esp                       ; start of name, for saving now
    mov  esi, esp                        ; start of name, for reading later
mcon1: 
    mov  al, byte ptr [ebx]        ; let's move the packet data into local  
    mov  byte ptr [edx], al        ; character at a time...
    inc     ebx
    inc    edx
    cmp  al,0                                ; ....until we find the zero delimiter
    jnz    mcon1

    mov  edi, [ebp+12]                ; Welcome message
    add   edi, 6                            ; position to where we put name
mcon2: 
    mov  al, byte ptr [esi]          ; get start of name from local
    mov   byte ptr [edi], al         ; store it in welcome message
    inc     edi
    inc     esi 
    cmp  al,0                                 ; keep going until zero delimeter
    jnz  mcon2 

    mov  esp,ebp                        ; release local storage
    pop  ebp
    ret  8                                       ; release call parameter
mcon endp

end start 
