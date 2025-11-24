; void daxpy_asm(double A, double* X, double* Y, int size, double* result);

section .text
bits 64
default rel

global asmDAXPY

asmDAXPY:
    push rbp
    mov rbp, rsp
    
    xor r10d, r10d          ; index i
    mov rax, [rbp+48]       ; result array pointer

computeLoop:
    cmp r10d, r9d
    jge complete

    ; Load X[i] and multiply by A
    movsd xmm1, [rdx + r10 * 8]
    mulsd xmm1, xmm0

    ; Load Y[i] and add to A*X[i]
    movsd xmm2, [r8 + r10 * 8]
    addsd xmm1, xmm2

    ; Store to result[i]
    movsd [rax + r10 * 8], xmm1

    inc r10d
    jmp computeLoop

complete:
    pop rbp
    ret