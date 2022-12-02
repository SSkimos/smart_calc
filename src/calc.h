#ifndef calc
#define calc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s21_stack {
    char **data;
    int size;
} s21_stack;

// stack methods
void push(struct s21_stack *stack, char *value);
char *pop(struct s21_stack *stack);
char *peek(struct s21_stack *stack);

// parser methods
char *parser(char *current_str);

#endif
