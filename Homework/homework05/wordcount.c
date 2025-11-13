#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *file;
    int ch;
    int word_count = 0;
    int in_word = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n", argv[1]);
        perror("Details");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        if (isspace(ch)) {
            if (in_word) {
                word_count++;
                in_word = 0;
            }
        } else {
            in_word = 1;
        }
    }

    if (in_word) {
        word_count++;
    }

    if (ferror(file)) {
        fprintf(stderr, "Error: Problem reading file '%s'\n", argv[1]);
        fclose(file);
        return 1;
    }

    if (fclose(file) != 0) {
        fprintf(stderr, "Error: Problem closing file '%s'\n", argv[1]);
        return 1;
    }

    printf("Number of words in '%s': %d\n", argv[1], word_count);
    return 0;
}
