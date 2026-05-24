#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mysh.h"

int main() {
    char input[MAX_INPUT];

    //loop to read user input
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
        int token_count = 0;
        char **tokens = tokenize(input, &token_count);
        for(int i = 0; i < token_count; i++) {
            printf("token[%d]: %s\n", i, tokens[i]);
        }
        //parse tokens into pipeline
        printf("input: %s\n", input);
        //execute pipeline
    }

    return 0;
}