#include <stdio.h>
  2 #include <stdlib.h>
  3 #include <string.h>
  4 
  5 int main() {
  6     char cmd[256], buffer[1024], *ptr;
  7     FILE *f1, *f2;
  8     size_t len;
  9     int c;
 10 
 11     f1 = fopen(__FILE__, "r");
 12     if (!f1) {
 13         perror("fopen");
 14         exit(1);
 15     }
 16 
 17     f2 = fopen("new_copy.c", "w");
 18     if (!f2) {
 19         perror("fopen");
 20         exit(1);
 21     }
 22 
 23     while ((c = getc(f1)) != EOF) {
 24         if (putc(c, f2) == EOF) {
 25             perror("putc");
 26             exit(1);
 27         }
 28     }
 29 
 30     fclose(f1);
 31     fclose(f2);
 32 
 33     snprintf(cmd, sizeof(cmd), "gcc new_copy.c -o new_copy");
 34     system(cmd);
 35 
 36     snprintf(cmd, sizeof(cmd), "./new_copy");
 37     system(cmd);
 38 
 39     snprintf(cmd, sizeof(cmd), "./new_copy");
 40     system(cmd);
 41 
 42     return 0;
 43 }
 44 
~                                                                                                                                                                                                                                  
~                       
