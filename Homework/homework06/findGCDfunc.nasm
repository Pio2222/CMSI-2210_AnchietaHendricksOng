global findGCDfunc

section .text

findGCDfunc:
    push ebp
    mov ebp, esp
    push ebx
    mov eax, [ebp+8]
    mov ebx, [ebp+12]
gcd_loop:
    cmp ebx, 0
    je done
    xor edx, edx
    div ebx
    mov eax, ebx
    mov ebx, edx
    jmp gcd_loop
done:
    pop ebx
    mov esp, ebp
    pop ebp
    ret
