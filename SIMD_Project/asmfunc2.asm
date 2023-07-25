; Steven John A. Pascaran / CSC 755M
section .text
bits 64
default rel ;[]
global SIMDprocess

SIMDprocess:
; rcx - ARRAY_SIZE, rdx - ptr to out r8 - ptr to in, r9 - not used
shr rcx, 3 ; divide by 8

L1:
vmovdqu ymm1, [r8-12]
vmovdqu ymm3, [r8-8]
vaddps ymm2, ymm1, ymm3
vmovdqu ymm1, [r8-4]
vaddps ymm2, ymm1, ymm2
vmovdqu ymm1, [r8]
vaddps ymm2, ymm1, ymm2
vmovdqu ymm1, [r8+4]
vaddps ymm2, ymm1, ymm2
vmovdqu ymm1, [r8+8]
vaddps ymm2, ymm1, ymm2
vmovdqu ymm1, [r8+12]
vaddps ymm2, ymm1, ymm2
vmovdqu [rdx], ymm2
add r8, 32
add rdx, 32
loop L1

ret