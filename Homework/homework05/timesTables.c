#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Please enter 1 number\n");
        return 1;
    }

    int N = atoi(argv[1]);
    if (N < 2) {
        printf("Please enter a number greater than or equal to 2.\n");
        return 1;
    }

    printf("%3c", 'x');
    for (int i = 1; i <= N; i++) {
        printf("%6d", i);
    }
    printf("\n\n");

    for (int i = 1; i <= 12; i++) {
        printf("%3d :", i);
        for (int j = 1; j <= N; j++) {
            printf("%6d", i * j);
        }
        printf("\n");
    }

    return 0;
}
