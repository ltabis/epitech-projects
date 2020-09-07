bits    64                      ; set architecture

global  strcmp:function         ; export strcmp

;; RDI RSI arguments
strcmp:
    xor RAX, RAX                ; set return value to null
    xor R8, R8                ; set return value to null
    xor R9, R9                ; set return value to null    
    cmp RDI, 0                  ; check if string parameter null
    je  .end
    cmp RSI, 0                  ; check if string parameter null
    je  .end

.loop:                          ; loop label
    mov R8B, [RDI]              ; Stocking next s1 char value into R8B
    mov R9B, [RSI]              ; Stocking next s2 char value into R9B

    cmp byte [RDI], 0           ; check if end of string
    je  .end                    ; checking if value is 0 (null terminated string)
    cmp byte [RSI], 0           ; check if end of string
    je  .end                    ; checking if value is 0 (null terminated string)

    cmp R8B, R9B                ; are charaters equal ?
    jne .end                    ; if not, go to end
    add AL, R8B                 ; add it to the result
    inc RSI                     ; counter incrementation
    inc RDI                     ; counter incrementation
    jmp .loop                   ; continue to iterate

.end:
    sub R8, R9                  ; subtract the two chars values
    mov RAX, R8
    ret                         ; returning result (end of stack) / resume execution flow
