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

typedef struct s21_credit_input {
    double sum;
    double term;
    double percent;
    int type;
} s21_credit_input;

typedef struct s21_credit_out {
    double monthly_payment;
    double interest_charges;
    double dept;
} s21_credit_out;

// stack methods
void push(struct s21_stack *stack, char *value);
char *pop(struct s21_stack *stack);
char *peek(struct s21_stack *stack);
struct s21_stack make_stack();
void clear_stack(struct s21_stack *stack);

// parser methods
struct s21_stack *parser(struct s21_stack *output_stack, char *current_str);

//polish methods
double polish(char *str, double *x);
double binary_calc(double a, double b,
                              char *third_arg, double answer, int flag);
double unary_calc(double a, char *second_arg, double answer, int flag);

// credit calc
void credit_calc(struct s21_credit_input *credit_input, struct s21_credit_out *credit_out);

#endif
