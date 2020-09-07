bits    64                      ; set architecture

global  strcspn:function        ; export strcspn / RDI RSI s + reject parameters

strcspn:
    xor RAX, RAX                ; set result to 0 in case of non-match
    cmp RDI, 0                  ; check if pointer null
    je  .end

.loop:                          ; loop label
    cmp byte [RDI], 0           ; check if end of string
    je  .end

    xor RCX, RCX                ; set counter to 0
    mov R8B, byte [RDI]         ; get current char to test
.loopreject:
    cmp byte [RSI + RCX], R8B   ; check if current char is matching
    je .end
    cmp byte [RSI + RCX], 0     ; check if all chars not matching
    je .continue
    inc RCX                     ; inc counter to move on next byte
    jmp .loopreject
.continue:
    inc RDI                     ; main string pointer incrementation
    inc RAX
    jmp .loop                   ; continue to iterate

.end:
    ret
