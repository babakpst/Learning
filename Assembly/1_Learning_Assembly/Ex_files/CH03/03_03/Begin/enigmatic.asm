.Data
hInst	DQ		0
;==================================
; working storage
;==================================
bin			dd  0   ; bytes read
bout		dd	0	; bytes written
hin			dq  0   ; handle for console input
hout        dq  0   ; handle for console output
charin      db  32 dup 0
welcome     db  'Enigma-like file encryptor',0Dh,0Ah
message1    db  0Ah, 0Dh, "Enter rotor for slot x: "
message2    db  "Enter start character slot x: "

;===================================
; Rotors which provide key stream
;=================================== 
rotor  struct
   hex			dq
   notch		db
ends
rotor1		rotor	<01F46C8037B9AD25Eh,0Fh>
rotor2		rotor	<0EFA87B439D5216C0h,03h>
rotor3		rotor	<00F732D168C4BA59Eh,0Dh>
rotor4		rotor	<0F0E8143CA2695B9Dh,00h>
rotor5		rotor	<0AB8736E1F0C295D4h,03h>

;===============================================
; Encryptor slots into which rotors are placed
;===============================================
slot  struct
   rotty    rotor
   rotno    db
   rotstart db
ends
slot1	slot
slot2	slot
slot3	slot

;==================================================
;Plugs for cross connecting at start and at end
;==================================================
plug1		db	00h
plug2		db	00h

.Code
start:
	Invoke GetModuleHandleA, 0
	Mov [hInst], Rax
	Invoke Main
	Invoke ExitProcess, 0

Main Frame
	;=====================
	; Get console handles
	;=====================
    arg -10                ;STD_INPUT_HANDLE
    invoke GetStdHandle    ;handle returned in eax
    mov [hin],eax          ;store 
    arg -11                ;STD_OUTPUT_HANDLE
    invoke GetStdHandle    ;handle returned in eax
    mov [hout],eax         ;store
    ;===========================================
    ; output welcome message
    ;===========================================
    arg 0,addr bout
    arg 28,addr welcome
    arg [hout]
    invoke WriteFile
    ;===========================================
    ; get rotor and start character for slot 1
    ;===========================================
    lea edx,addr message1
    mov b[edx+23],031h						; insert 1 into rotor message
    arg 0,addr bout
    arg 26,addr message1
    arg [hout]
    invoke WriteFile
    arg 0, addr bin
    arg 3, addr charin						; read character plus lf/cr
    arg [hin]
    invoke ReadFile
    xor eax,eax
    mov al,b[charin]
    sub al,031h								; change char 1-5 to binary 0-4
    shl	eax,4								; multiply by 16 (each rotor set is 16 bytes) to get offset of requetsed rotor
    mov rbx,[rotor1+eax]					; load hex dword from rotor
    mov [slot1.rotty.hex],rbx	 			; store hex dword into slot
    mov cl,[rotor1+eax+8]					; load notch byte from rotor
    mov [slot1.rotty.notch],cl				; move notch byte into slot.rotty.notch
    mov cl,[charin]							;
	mov [slot1.rotno],cl					; save rotor number in slot
    ;===========================================
    ; get slot start character 0-F
    ;===========================================
    lea edx,addr message2					
    mov b[edx+27],031h						; insert 1 into start position message
    arg 0, addr bout
    arg 30, addr message2
    arg [hout]
    invoke WriteFile
    arg 0, addr bin
    arg 3, addr charin						; read message plus crlf
    arg [hin]
    invoke ReadFile
    mov al,[charin]
	mov [slot1.rotstart],al					; save the start character
    sub al,030h								; convert character to binary
    cmp al,09h								; check if it was a number
	jle >starter1							; if so, skip to done
    sub al,7								; adjust for character
	cmp al,0Fh								; check if upper case
    jle >starter1							; if so, done
	sub al,020h								; final adjustment and done
starter1:
    mov rdx,rbx								; copy rbx into rdx as a scarificial copy
	rol rdx,4								; move nibble to lower
	and rdx,0Fh								;
    cmp al,dl								; is this the start point?
    je  >ready1
    rol rbx,4								; rotate the rotor
	jmp starter1
ready1:	
    mov edi, addr slot1.rotty.hex
    mov [edi],rbx							; store rotor correctly positioned

    ;===========================================
    ; get rotor and start character for slot 2
    ;===========================================
	nop
    ;===========================================
    ; get rotor and start character for slot 3
    ;===========================================
	nop
    ;===========================================================================
    ;  Read plugboard settings
    ;===========================================================================
    nop
    ;===========================================================================
    ;  Enigmatic encryptor now configured and ready to use
    ;===========================================================================
	ret
EndF
