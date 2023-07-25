; Steven John A. Pascaran / CSC 755M
section .text
bits 64
default rel ;[]
global x86_kernel

x86_kernel:
; rcx - ARRAY_SIZE, rdx - ptr to out r8 - ptr to in, r9 - not used

L1:
movss xmm1, [r8]
movss xmm3, [r8-12]
vaddss xmm2, xmm1, xmm3
movss xmm1, [r8-8]
vaddss xmm2, xmm1
movss xmm1, [r8-4]
vaddss xmm2, xmm1
movss xmm1, [r8+4]
vaddss xmm2, xmm1
movss xmm1, [r8+8]
vaddss xmm2, xmm1
movss xmm1, [r8+12]
vaddss xmm2, xmm1
vmovss [rdx], xmm2 ;rdx points to the output 
add r8, 4
add rdx, 4
loop L1

ret