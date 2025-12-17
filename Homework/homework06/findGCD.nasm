; global _start
; needs to be _main for windows
; no header in file with build instructions
global _main

section .bss
    inbuf  resb 128
    outbuf resb 32

section .text

;_start:
_main:
    mov eax,3
    mov ebx,0
    mov ecx,inbuf
    mov edx,128
    int 0x80

    mov ecx,eax
    mov esi,inbuf
    call parse_int
    mov edi,eax
    call parse_int
    mov ebx,eax

gcd:
    cmp ebx,0
    je done
    xor edx,edx
    mov eax,edi
    div ebx
    mov edi,ebx
    mov ebx,edx
    jmp gcd

done:
    mov eax,edi
    mov edi,outbuf
    call u32_to_dec

    mov eax,4
    mov ebx,1
    mov ecx,esi
    mov edx,edx
    int 0x80

    mov eax,1
    xor ebx,ebx
    int 0x80

parse_int:
.skip:
    cmp ecx,0
    je .end
    mov al,[esi]
    cmp al,'0'
    jb .adv
    cmp al,'9'
    jbe .num
.adv:
    inc esi
    dec ecx
    jmp .skip
.num:
    xor eax,eax
.loop:
    cmp ecx,0
    je .ret
    mov al,[esi]
    cmp al,'0'
    jb .ret
    cmp al,'9'
    ja .ret
    imul eax,eax,10
    sub al,'0'
    movzx edx,al
    add eax,edx
    inc esi
    dec ecx
    jmp .loop
.ret:
    ret
.end:
    xor eax,eax
    ret

u32_to_dec:
    mov ebx,10
    mov esi,edi
    add esi,31
    mov ecx,0
    cmp eax,0
    jne .loop2
    mov byte [esi],'0'
    mov edx,1
    ret
.loop2:
    xor edx,edx
    div ebx
    add dl,'0'
    mov [esi],dl
    dec esi
    inc ecx
    cmp eax,0
    jne .loop2
    inc esi
    mov edx,ecx
    ret
