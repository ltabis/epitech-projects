bits    64                      ; set architecture

global  memcpy:function         ; export memcpy

;; RDI RSI RDX arguments
memcpy:
    xor RCX, RCX                ; set counter to 0, xor is faster than mov
    xor RAX, RAX                ; set return value to null
    cmp RDI, 0                  ; check if string parameter null
    je  .end
    cmp RSI, 0                  ; check if string parameter null
    je  .end
    mov RAX, RDI                ; set return value to dest pointer
    cmp RDI, RSI                ; check if pointers are the same (in that case we have nothing to copy)
    je  .end

.loop:                          ; loop label
    mov R8B, [RSI]              ; Stocking next char value into R8B
    cmp byte [RSI], 0           ; check if end of string
    je  .end                    ; checking if value is 0 (null terminated string)
    cmp RCX, RDX                ; check if end of n bytes
    je  .end                    ; checking if value is 0 (null terminated string)
    mov [RDI + RCX], R8B        ; placing parameter value inside pointer
    inc RCX                     ; counter incrementation
    inc RSI                     ; counter incrementation
    jmp .loop                   ; continue to iterate

.end:
    ret                         ; returning result (end of stack) / resume execution flow
