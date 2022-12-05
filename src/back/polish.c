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
  int flag = 0;

  struct s21_stack buffer = make_stack();
  parser(&buffer, str);
  struct s21_stack stack = make_stack();
  revert_stack(&buffer, &stack);

  while (peek(&stack)) {
//    printf("ans = %Lf\n", answer);
    if (peek(&stack)) {
      first_arg = pop(&stack);
    }
    if (peek(&stack) && !second_arg) {
      second_arg = pop(&stack);
      // unary minus
      if (strcmp("-", second_arg) == 0) {
        printf("huy\n\n\n\n");
        char *ptr = NULL;
        a = strtold(first_arg, &ptr);
        answer = 0 - a;
        flag = 1;
        // unary minus
      } else if (strcmp("+", second_arg) == 0) {
        char *ptr = NULL;
        a = strtold(first_arg, &ptr);
        answer = a;
        flag = 1;
      }
      flag = 1;
    }
    if (is_number(second_arg)) {
      if (peek(&stack)) {
        third_arg = pop(&stack);
//        printf("th = %s\n", third_arg);
      }
      char *ptr = NULL;
      a = strtold(first_arg, &ptr);
      b = strtold(second_arg, &ptr);
      if (strcmp("+", third_arg) == 0) {
        if (!flag) {
          answer = answer + a;
        } else {
          answer = answer + a + b;
        }
      }
      if (strcmp("-", third_arg) == 0) {
        if (!flag) {
          answer = answer - a-b;
        } else {
          answer = answer + (a-b);
        }
      }
      if (strcmp("*", third_arg) == 0) {
        if (!flag) {
          answer = answer * a;
        } else {
          answer = answer + (a * b);
        }
      }
      if (strcmp("/", third_arg) == 0) {
        if (!flag) {
          answer = (answer / a);
        } else {
          answer = (answer + (a/b));
        }
      }
      if (strcmp("%", third_arg) == 0) {
        if (!flag) {
          answer = (fmod(answer, a));
        } else {
          answer = (answer + (fmod(a, b)));
        }
      }
      flag = 0;
    } else {
      char *ptr = NULL;
      a = strtold(first_arg, &ptr);
      if (strcmp("s", second_arg) == 0) {
        if (!flag) {
          answer = sin(answer);
        } else {
          answer = sin(a);
        }
      }
    }
  }
  return answer;
}
