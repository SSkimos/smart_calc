#include "calc.h"

void revert_stack(struct s21_stack *old, struct s21_stack *new) {
  while (peek(old) != NULL) {
    push(new, pop(old));
  }
}

int is_number(char *ptr) {
  int flag = 0;
  if ((ptr[0] - '0' > 0 && ptr[0] - '0' < 9) || ptr[0] == '.') {
    flag = 1;
  }
  return flag;
}

long double polish(char *str) {
  char *first_arg = NULL;
  char *second_arg = NULL;
  char *third_arg = NULL;
  long double a = 0.0;
  long double b = 0.0;
  long double answer = 0.0;

  struct s21_stack buffer = make_stack();
  parser(&buffer, str);
  struct s21_stack stack = make_stack();
  revert_stack(&buffer, &stack);

  while (peek(&stack)) {
    if (peek(&stack)) {
      first_arg = pop(&stack);
    }
    if (peek(&stack)) {
      second_arg = pop(&stack);
    }
    if (is_number(second_arg)) {
      if (peek(&stack)) {
        third_arg = pop(&stack);
      }
      char *ptr = NULL;
      a = strtold(first_arg, &ptr);
      b = strtold(second_arg, &ptr);
      if (strcmp("+", third_arg) == 0) {
        answer = answer + a + b;
      }
    } else {
      // TODO: sin/cos/etc
    }
  }
  return answer;
}
