        global _main
        extern _printf
        extern _atoi

        section .text

_main:
        mov ecx, [esp+4]
        cmp ecx, 2
        jl usage

        mov edx, [esp+8]
        push dword [edx+4]
        call _atoi
        add esp, 4

        mov bl, al
        xor ecx, ecx

count_bits:
        test bl, bl
        jz decide

        shr bl, 1
        adc ecx, 0
        jmp count_bits

decide:
        test ecx, 1
        jz even_ones

        push dword 0
        push outfmt
        call _printf
        add esp, 8
        ret

even_ones:
        push dword 1
        push outfmt
        call _printf
        add esp, 8
        ret

usage:
        push usagefmt
        call _printf
        add esp, 4
        ret

        section .data
        outfmt db "%d", 10, 0
        usagefmt db "Usage: paritygen <byte value 0-255>", 10, 0