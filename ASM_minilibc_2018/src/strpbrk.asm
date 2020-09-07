bits    64                      ; set architecture

global  strpbrk:function        ; export strpbrk / RDI RSI parameters

strpbrk:
    xor RAX, RAX                ; set result to 0 in case of non-match
    cmp RDI, 0                  ; check if pointer null
    je  .end

.loop:                          ; loop label
    xor RAX, RAX                ; set result to 0 in case of non-match
    cmp byte [RDI], 0           ; check if end of string
    je  .end

    xor RCX, RCX                ; set counter to 0
    mov RAX, RDI                ; set result to current s pointer
    mov R8B, byte [RDI]         ; get current char to test
.loopaccepte:
    cmp byte [RSI + RCX], R8B   ; check if current char is matching
    je .end
    cmp byte [RSI + RCX], 0     ; check if all chars not matching
    je .continue
    inc RCX                     ; inc counter to move on next byte
    jmp .loopaccepte
.continue:
    inc RDI                     ; main string pointer incrementation
    jmp .loop                   ; continue to iterate

.end:
    ret
