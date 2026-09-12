BITS 32

section .text

global jroc_context_switch_low

; Stage 23 context-switch ABI.
;
; Arguments:
;   [esp+4] = old context
;   [esp+8] = new context
;
; This establishes the assembly ABI. Full interrupt-frame
; restore and live task switching are integrated later.

jroc_context_switch_low:

    push ebp
    mov ebp, esp

    mov eax, [ebp + 8]
    mov edx, [ebp + 12]

    test eax, eax
    jz .done

    test edx, edx
    jz .done

.done:
    pop ebp
    ret
