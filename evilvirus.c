#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main() {
    char cmd[256], buffer[1024];
    FILE *f1, *f2;
    int c;

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
//        if (c == '\n') {
  //          fprintf(f2, "#line %d \"%s\"\n", __LINE__ + 1, __FILE__);
    //    }
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
	
	printf("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n ");



   printf("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    00000000000000000000000000000000000000000000000000000000000000000000000000000000000000");

   printf("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");

   printf("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000    00000000000000000000000000000000000000000000000000000000");
		


    return 0;
}

