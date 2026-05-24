#ifndef MYSH_H
#define MYSH_H

#define MAX_ARGS 128
#define MAX_INPUT 1024

// Represents a single command
// e.g. "ls -la /home" → args = ["ls", "-la", "/home", NULL], argc = 3
typedef struct {
    char *args[MAX_ARGS];   // NULL-terminated argument array for execvp
    int argc;               // number of arguments
    char *input_file;       // NULL unless < redirection
    char *output_file;      // NULL unless > or >> redirection
    int append;             // 1 if >>, 0 if >
} Command;

// Represents a full pipeline
// e.g. "ls | grep foo | wc -l" → 3 commands
typedef struct {
    Command commands[MAX_ARGS];
    int num_commands;
} Pipeline;

// lexer.c
char **tokenize(char *input, int *token_count);

// parser.c
Pipeline parse(char **tokens, int token_count);

// executor.c
void execute(Pipeline *pipeline);

// builtins.c
int is_builtin(char *cmd);
void run_builtin(Command *cmd);

#endif