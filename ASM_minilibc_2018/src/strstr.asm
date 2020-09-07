bits    64                      ; set architecture

global  strstr:function        ; export strstr / RDI RSI haysack + needle parameters

strstr:
    mov RAX, 0                  ; set result to 0 in case of non-match
    cmp RDI, 0                  ; check if pointer null
    je  .end
    cmp RSI, 0                  ; check if pointer null
    je  .end

.loop:                          ; loop label
    mov RAX, 0                  ; set result to 0 in case of non-match
    cmp byte [RDI], 0           ; check if end of string
    je  .end

    mov RCX, 0                  ; set counter to 0

.loopreject:
    mov RAX, RDI
    mov R8B, byte [RDI + RCX]   ; get current char to test

    cmp byte [RSI + RCX], 0     ; all chars have matched
    je .end
    cmp byte [RSI + RCX], R8B   ; check if current char isn't matching
    jne .continue
    inc RCX                     ; inc counter to move on next byte
    jmp .loopreject

.continue:
    inc RDI                     ; main string pointer incrementation
    jmp .loop                   ; continue to iterate

.end:
    ret
