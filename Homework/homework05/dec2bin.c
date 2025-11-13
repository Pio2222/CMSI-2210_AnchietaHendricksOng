#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    unsigned int num;
    int i;

    if (argc == 2) {
        num = (unsigned int)atoi(argv[1]);
    } else {
        printf("Enter a base-10 number: ");
        scanf("%u", &num);
    }

    printf("32-bit binary: ");
    for (i = 31; i >= 0; i--) {
        unsigned int bit = (num >> i) & 1;
        printf("%u", bit);
    }
    printf("\n");

    return 0;
}

