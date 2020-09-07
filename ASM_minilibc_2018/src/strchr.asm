bits    64                      ; set architecture

global  strchr:function         ; export strchr / RDI RSI parameters

strchr:
    mov RAX, 0
    cmp RDI, 0                  ; check if pointer null
    je  .end

    mov RAX, RDI                ; return value (test end of string)
.loop:                          ; loop label
    cmp byte [RDI], 0           ; check if end of strin
    je  .end

    mov RAX, RDI                ; return value (test character match)
    cmp [RDI], SIL              ; check if character matches or not ESI = 32 bits (int)
    je  .end                    ; checking if value is 0 (null terminated string)
    inc RDI                     ; counter incrementation
    jmp .loop                   ; continue to iterate

.end:
    ret
