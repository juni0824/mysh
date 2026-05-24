#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mysh.h"

// Function to tokenize the input string
char **tokenize(char *input, int *token_count){
    char **tokens = malloc(MAX_ARGS * sizeof(char*));
    int count = 0;
    int i = 0;

    while(input[i] != '\0') {
        // Skip whitespace
        if(input[i] == ' ' || input[i] == '\t') {
            ++i;
            continue;
        }

        // Handle quoted strings
        else if(input[i] == '"'){
            ++i; // Skip the opening quote
            int start = i;
            while(input[i] != '"' && input[i] != '\0') {
                ++i;
            }
            char* string = strndup(input + start, i - start);
            tokens[count++] = string;
            ++i;
            continue;
        }

        // normal token
        int start = i;
        while(input[i] != ' ' && input[i] != '\t' && input[i] != '\0'){
            ++i;
        }
        char* token = strndup(input + start, i - start);
        tokens[count++] = token;
    }
    
    tokens[count] = NULL;
    *token_count = count;
    return tokens;
}