#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define FILE_SIZE 1000000

int main() {
    char cmd[256], buffer[BUFFER_SIZE];
    FILE *f1, *f2;
    int c, count = 0;

    f1 = fopen(__FILE__, "r");
    if (!f1) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    f2 = fopen("new_copy.c", "w");
    if (!f2) {
        fprintf(stderr, "Error creating file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    while ((c = getc(f1)) != EOF) {
        if (putc(c, f2) == EOF) {
            fprintf(stderr, "Error writing to file: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
        if (c == '\n') {
            fprintf(f2, "#line %d \"%s\"\n", __LINE__ + 1, __FILE__);
        }
        count++;
    }

    // Fill up the remaining buffer space with zeros
    while (count < FILE_SIZE) {
        memset(buffer, '0', BUFFER_SIZE);
        fwrite(buffer, BUFFER_SIZE, 1, f2);
        count += BUFFER_SIZE;
    }

    if (fclose(f1) != 0) {
        fprintf(stderr, "Error closing input file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (fclose(f2) != 0) {
        fprintf(stderr, "Error closing output file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    snprintf(cmd, sizeof(cmd), "gcc new_copy.c -o new_copy");

    if (system(cmd) != 0) {
        fprintf(stderr, "Error compiling file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    snprintf(cmd, sizeof(cmd), "./new_copy");

    if (system(cmd) != 0) {
        fprintf(stderr, "Error running executable: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    snprintf(cmd, sizeof(cmd), "./new_copy");

    if (system(cmd) != 0) {
        fprintf(stderr, "Error running executable: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    return 0;
}
