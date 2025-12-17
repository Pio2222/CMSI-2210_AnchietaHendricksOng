#include <stdio.h>
#include <stdint.h>
// added to try to get this to link
#include <winsock2.h>


uint32_t makeNBOC(uint32_t x);

int main() {
    uint32_t test_values[] = {
        0x12345678,
        0xAB23EF34,
        0x0BEEEF04,
        0xDEADB65F,
        0x87654321
    };
    int test_size = sizeof(test_values) / sizeof(test_values[0]);

    for (int i = 0; i < test_size; i++) {
        printf("0x%08X\n",makeNBOC(test_values[i]));
    }

    return 0;
}
