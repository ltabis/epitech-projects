bits    64                      ; set architecture

global  rindex:function         ; export rindex / RDI RSI parameters

rindex:
    mov RAX, 0                  ; set counter to 0, xor is faster than mov
    cmp RDI, 0                  ; check if pointer null
    je  .end
.loop:                          ; loop label
    cmp byte [RDI], 0           ; check if end of string
    je  .end

    cmp byte [RDI], SIL         ; check if character match
    je .occurrence

.resume:
    inc RDI                     ; counter incrementation
    jmp .loop                   ; continue to iterate

.occurrence:
    mov RAX, RDI                ; update return value (test character match)
    jmp .resume

.end:
    ret

