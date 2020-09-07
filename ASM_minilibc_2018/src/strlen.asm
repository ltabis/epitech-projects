bits    64                      ; set architecture

global  strlen:function         ; export strlen

strlen:
    xor RCX, RCX                ; set counter to 0, xor is faster than mov

.loop:                          ; loop label
    cmp byte [RDI + RCX], 0     ; check if end of string
    je  .end                    ; checking if value is 0 (null terminated string)
    inc RCX                     ; counter incrementation
    jmp .loop                   ; continue to iterate

.end:
    mov RAX, RCX                ; rax = return value
    ret
