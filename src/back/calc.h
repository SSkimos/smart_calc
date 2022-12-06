#ifndef calc
#define calc

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ZERO_LEVEL 0
#define FIRST_LEVEL 1
#define SECOND_LEVEL 2
#define THIRD_LEVEL 3
#define FOURTH_LEVEL 4

typedef struct s21_stack {
    char **data;
    int size;
} s21_stack;

// stack methods
void push(struct s21_stack *stack, char *value);
char *pop(struct s21_stack *stack);
char *peek(struct s21_stack *stack);
struct s21_stack make_stack();
void clear_stack(struct s21_stack *stack);

// parser methods
struct s21_stack *parser(struct s21_stack *output_stack, char *current_str);

//polish methods
long double polish(char *str, long double *x);
long double binary_calc(long double a, long double b,
                              char *third_arg, long double answer, int flag);

#endif
