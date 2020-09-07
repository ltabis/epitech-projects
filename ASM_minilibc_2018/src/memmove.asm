bits    64                      ; set architecture

global  memmove:function         ; export memmov

;; RDI RSI arguments
memmove:
    xor RCX, RCX                ; set counter to 0, xor is faster than mov
    xor RAX, RAX                ; set return value to null

    cmp RDI, 0                  ; check if string parameter null
    je  .end
    cmp RSI, 0                  ; check if string parameter null
    je  .end
    mov RAX, RDI
    cmp RDI, RSI                ; checks if pointers are equal (in that case we have nothing to copy)
    je  .end

    cmp [RDI + RDX], RSI        ; checks if we can copy to the right or the left
    jle .right_copy

    std                         ; set flag DF for movsb (copies downards) -> RDX--
    rep movsb                   ; copy RSI into RDI to left
    jmp .end

.right_copy:
    rep movsb                   ; copy RSI into RDI to right

.end:
    ret                         ; returning result (end of stack) / resume execution flow
