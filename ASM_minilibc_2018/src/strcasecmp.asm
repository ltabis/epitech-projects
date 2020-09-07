bits    64                      ; set architecture

global  strcasecmp:function         ; export strcasecmp

;; RDI RSI arguments
strcasecmp:
    xor R8, R8                  ; set char container to null
    xor R9, R9                  ; set char container to null
    xor RAX, RAX                ; set return value to null
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

    inc RSI                     ; pointer incrementation
    inc RDI                     ; pointer incrementation

    cmp R8B, 97                 ; are lowercase charaters equal ?
    jge .lowercase
    cmp R8B, 65                 ; are charaters sup A ?
    jge .uppercase
.continue:
    cmp R8B, R9B                ; are lowercase charaters equal ?
    je  .loop

    jmp .end                    ; end of comparison

.lowercase:                     ; check >= a && <= z
    cmp R8B, 122
    jle .lowercasebis
    jmp .continue               ; check regular

.uppercase:
    cmp R8B, 90                 ; check >= A && <= Z
    jle .uppercasebis
    jmp .continue

.lowercasebis:
    sub R8B, 32                 ; check if the other character is also uppercase
    cmp R8B, R9B
    je .loop

    add R8B, 32                 ; Failed, check regular characters just in case
    jmp .continue

.uppercasebis:
    add R8B, 32                 ; check if the other character is also lowercased
    cmp R8B, R9B
    je .loop

    sub R8B, 32                 ; Failed, check regular characters just in case
    jmp .continue

.end:
    sub R8, R9                  ; subtract the two chars values
    mov RAX, R8                 ; assign result to return value
    ret                         ; returning result (end of stack) / resume execution flow
