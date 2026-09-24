#include "../include/myfilefunctions.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// Worked example: wordCount — reads the file character by character
int wordCount(FILE* file, int* lines, int* words, int* chars) {
    if (file == NULL) return -1;
    *lines = 0; *words = 0; *chars = 0;
    int c, prev = ' ';
    while ((c = fgetc(file)) != EOF) {
        (*chars)++;
        if (c == '\n') (*lines)++;
        if (isspace(c) == 0 && isspace(prev) != 0) (*words)++;  // new word starts
        prev = c;
    }
    return 0;
}
// Note: add #include <ctype.h> for isspace()

// TODO: implement mygrep — read the file line by line (use fgets in a loop),
// check if search_str appears in each line (use strstr), and if so store a
// copy of that line (use strdup or malloc+strcpy) into the matches array
// (you'll need to malloc/realloc the array of char* as you find matches).
// Return how many matches found, or -1 on error.
int mygrep(FILE* fp, const char* search_str, char*** matches) {
        if (fp == NULL || search_str == NULL || matches == NULL) {
        return -1;
    }

    char **result = NULL;
    int count = 0;

    char *line = NULL;
    size_t cap = 0;
    ssize_t len;

    while ((len = getline(&line, &cap, fp)) != -1) {

        if (strstr(line, search_str) != NULL) {

            char **tmp = realloc(
                result,
                (count + 1) * sizeof(char *)
            );

            char *copy = malloc((size_t)len + 1);

            if (tmp == NULL || copy == NULL) {

                if (tmp != NULL) {
                    result = tmp;
                }

                free(copy);

                for (int i = 0; i < count; i++) {
                    free(result[i]);
                }

                free(result);
                free(line);

                return -1;
            }

            result = tmp;

            strcpy(copy, line);

            result[count] = copy;
            count++;
        }
    }

    free(line);

    *matches = result;

    return count;
}
