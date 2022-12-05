#include "calc.h"

void revert_stack(struct s21_stack *old, struct s21_stack *new) {
  while (peek(old) != NULL) {
    push(new, pop(old));
  }
}

char *polish(char *str) {
  char *c_first = NULL;
  char *c_second = NULL;
  char *ans = NULL;
  long double n_first = 0.0;
  long double n_second = 0.0;
  char *operation = NULL;
  char *new_str = NULL;

  struct s21_stack buffer = make_stack();
  parser(&buffer, str);
  struct s21_stack stack = make_stack();
  revert_stack(&buffer, &stack);

  while (peek(&stack)) {
    if (peek(&stack)) {
      c_first = pop(&stack);
    }
    if (peek(&stack)) {
      if (peek(&stack)) {
        c_second = pop(&stack);
      }
    }
    if (peek(&stack)) {
      operation = pop(&stack);
    }
    char *ptr = NULL;
    n_first = atof(c_first);
    n_second = atof(c_second);
    if (strcmp("+", operation)) {
      long double answer = 0.0;
      answer = n_first + n_second;
      ans = strdup()
    }
  }
  return str;
}