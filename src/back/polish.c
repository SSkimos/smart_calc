#include "calc.h"

void revert_stack(struct s21_stack *old, struct s21_stack *new) {
  while (peek(old) != NULL) {
    push(new, pop(old));
  }
}

long double polish(char *str) {
  char *c_first = NULL;
  char *c_second = NULL;
  char ans[1000] = {'\0'};
  long double n_first = 0.0;
  long double n_second = 0.0;
  char *operation = NULL;
  char *new_str = NULL;
  long double answer = 0.0;

  struct s21_stack buffer = make_stack();
  parser(&buffer, str);
  struct s21_stack stack = make_stack();
  revert_stack(&buffer, &stack);

  while (peek(&stack)) {
    if (peek(&stack)) {
      c_first = pop(&stack);
    }
    if (peek(&stack)) {
      c_second = pop(&stack);
    }
    if (peek(&stack)) {
      operation = pop(&stack);
    }
    char *ptr = NULL;
    n_first = strtold(c_first, &ptr);
    n_second = strtold(c_second, &ptr);
    if (strcmp("+", operation) == 0) {
      answer = answer + n_first + n_second;
    }
  }
  return answer;
}
