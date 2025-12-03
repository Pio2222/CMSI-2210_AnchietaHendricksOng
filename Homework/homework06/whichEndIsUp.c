#include <stdio.h>

int main() {
    unsigned int x = 0x12345678;
    unsigned char *ptr = (unsigned char*)&x;

    if (*ptr == 0x78) {
        printf("Little-endian\n");
    } else if (*ptr == 0x12) {
        printf("Big-endian\n");
    } else {
        printf("Unknown endianness\n");
    }

    return 0;
}