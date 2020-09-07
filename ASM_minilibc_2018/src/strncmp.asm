bits    64                      ; set architecture

global  strncmp:function         ; export strncmp

;; RDI RSI RDX arguments
strncmp:
    xor R8, R8                  ; set counter to 0, xor is faster than mov
    xor R9, R9                  ; set counter to 0, xor is faster than mov
    xor RCX, RCX                ; set counter to 0, xor is faster than mov
    xor RAX, RAX                ; set return value to null
    cmp RDI, 0                  ; check if string parameter null
    je  .end
    cmp RSI, 0                  ; check if string parameter null
    je  .end

.loop:                          ; loop label
    mov R8B, [RDI]              ; Stocking next s1 char value into R8B
    mov R9B, [RSI]              ; Stocking next s2 char value into R9B

    cmp byte [RDI], 0           ; check if end of string
    je  .end
    cmp byte [RSI], 0           ; check if end of string
    je  .end
    cmp RCX, RDX                ; checking if value n is atteinded
    je  .stop

    cmp R8B, R9B                ; are charaters equal ?
    jne .end                    ; if not, go to end
    add AL, R8B                 ; add it to the result
    inc RSI                     ; counter incrementation
    inc RDI                     ; counter incrementation
    inc RCX                     ; counter incrementation
    jmp .loop                   ; continue to iterate

.stop:
    mov RAX, 0
    ret

.end:
    sub R8, R9                  ; subtract the two chars values
    mov RAX, R8                 ; assign return value
    ret                         ; returning result (end of stack) / resume execution flow
