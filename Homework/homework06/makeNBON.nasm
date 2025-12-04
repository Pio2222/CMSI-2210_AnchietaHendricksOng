global main
extern makeNBOC
extern printf

section .data
fmt:    db "Result: 0x%08X", 10, 0

test_values:
    dd 0x12345678
    dd 0xAB23EF34
    dd 0x0BEEEF04
    dd 0xDEADB65F
    dd 0x87654321

section .text

main:
    mov rcx, 5
    lea rbx, [test_values]

next_value:
    mov edi, [rbx]
    call makeNBOC

    mov rdi, fmt
    mov esi, eax
    xor eax, eax
    call printf

    add rbx, 4
    dec rcx
    jnz next_value

    xor eax, eax
    ret
