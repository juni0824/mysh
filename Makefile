CC = gcc
CFLAGS = -Wall -Wextra -g -I./include

SRC = src/main.c src/lexer.c src/parser.c src/executor.c src/builtins.c
OBJ = $(SRC:.c=.o)
TARGET = mysh

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)