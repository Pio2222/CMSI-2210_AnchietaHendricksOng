#include <stdio.h>

int main(int argc, char *argv[]) {
    unsigned long long num = 0;
    unsigned int digits = 8;

    if (argc >= 2) {
        if (sscanf(argv[1], "%llu", &num) != 1) {
            printf("Invalid number.\n");
            return 1;
        }

        if (argc >= 3) {
            if (sscanf(argv[2], "%u", &digits) != 1) {
                printf("Invalid digit count. Using 8.\n");
                digits = 8;
            }
        }
    } else {
        printf("Enter a base-10 number: ");
        if (scanf("%llu", &num) != 1) {
            printf("Invalid number.\n");
            return 1;
        }

        printf("Enter number of hex digits (8 or 16): ");
        if (scanf("%u", &digits) != 1) {
            printf("Invalid digit count. Using 8.\n");
            digits = 8;
        }
    }

    if (digits != 8 && digits != 16) {
        printf("Invalid digit count (must be 8 or 16). Using 8.\n");
        digits = 8;
    }

    if (digits == 16) {
        printf("0x%016llX\n", num);
    } else {
        unsigned long long masked = num & 0xFFFFFFFFULL;
        printf("0x%08llX\n", masked);
    }

    return 0;
}
