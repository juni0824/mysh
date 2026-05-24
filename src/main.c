#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mysh.h"

int main() {
    char input[MAX_INPUT];

    while (1) {
        printf("mysh> ");
        fflush(stdout);
        if (fgets(input, MAX_INPUT, stdin) == NULL) {
            break; // EOF
        }

        input[strcspn(input, "\n")] = '\0'; // Remove newline
        if (strlen(input) == 0) {
            continue; // Empty input
        }

        //tokenize input
        //parse tokens into pipeline
        printf("input: %s\n", input);
        //execute pipeline
    }

    return 0;
}