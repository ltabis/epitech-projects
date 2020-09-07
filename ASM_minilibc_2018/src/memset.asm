bits    64                      ; set architecture

global  memset:function         ; export memset

;; RDI RSI RDX arguments
memset:
    xor RCX, RCX                ; set counter to 0, xor is faster than mov
    mov RAX, RDI                ; set return value to dest pointer

.loop:                          ; loop label
    cmp RCX, RDX                ; check if end of n bytes
    je  .end                    ; checking if value is 0 (null terminated string)
    mov [RDI + RCX], SIL        ; placing parameter value inside pointer SIL (8 bits register)
    inc RCX                     ; counter incrementation
    jmp .loop                   ; continue to iterate

.end:
    ret                         ; returning result (end of stack) / resume execution flow
