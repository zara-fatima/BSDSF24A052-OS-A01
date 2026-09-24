#include <stdio.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main() {
    printf("--- Testing String Functions ---\n");
    char dest[50];
    mystrcpy(dest, "Hello");
    printf("mystrcpy result: %s\n", dest);
    printf("mystrlen of dest: %d\n", mystrlen(dest));
    mystrcat(dest, " World");
    printf("mystrcat result: %s\n", dest);

    printf("\n--- Testing File Functions ---\n");
    FILE* f = fopen("src/main.c", "r");   // test on any existing file
    int lines, words, chars;
    wordCount(f, &lines, &words, &chars);
    printf("Lines: %d, Words: %d, Chars: %d\n", lines, words, chars);
    fclose(f);

    return 0;
}
