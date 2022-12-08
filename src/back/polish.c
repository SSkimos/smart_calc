#include "calc.h"

void revert_stack(struct s21_stack *old, struct s21_stack *new) {
  while (peek(old) != NULL) {
    push(new, pop(old));
  }
}

int is_number(char *ptr) {
  int flag = 0;
  if ((ptr[0] - '0' >= 0 && ptr[0] - '0' <= 9)) {
    flag = 1;
  }
  return flag;
}

int is_unary_operand (char *c) {
  int flag = 0;
  if (strcmp("v", c) == 0) { flag = 1; }
  if (strcmp("l", c) == 0) { flag = 1; }
  if (strcmp("L", c) == 0) { flag = 1; }
  if (strcmp("s", c) == 0) { flag = 1; }
  if (strcmp("c", c) == 0) { flag = 1; }
  if (strcmp("t", c) == 0) { flag = 1; }
  if (strcmp("S", c) == 0) { flag = 1; }
  if (strcmp("C", c) == 0) { flag = 1; }
  if (strcmp("T", c) == 0) { flag = 1; }
  return flag;
}

int is_binary_operand(char *c) {
  int flag = 0;
  if (strcmp("+", c) == 0) { flag = 1; }
  if (strcmp("^", c) == 0) { flag = 1; }
  if (strcmp("-", c) == 0) { flag = 1; }
  if (strcmp("*", c) == 0) { flag = 1; }
  if (strcmp("/", c) == 0) { flag = 1; }
  if (strcmp("%", c) == 0) { flag = 1; }
  return flag;
}

double polish(char *str, double *x) {
  char *zero_arg = NULL;
  char *first_arg = NULL;
  char *second_arg = NULL;
  double a = 0.0;
  double b = 0.0;
  double answer = 0.0;
  int flag = 1;

  struct s21_stack buffer = make_stack();
  parser(&buffer, str);
  struct s21_stack stack = make_stack();
  revert_stack(&buffer, &stack);

  while (peek(&stack)) {
    if (peek(&stack) && flag) {
      zero_arg = pop(&stack);
      if (!peek(&stack)) {
        // one arg case
        char *ptr = NULL; a = strtold(zero_arg, &ptr);
        answer += a;
        return answer;
      }
    }
    if (peek(&stack)) {
      first_arg = pop(&stack);
      if (is_binary_operand(first_arg) && flag) {
        // unary cases
        if (strcmp("-", first_arg) == 0) {
          char *ptr = NULL;
          a = strtold(zero_arg, &ptr);
          answer = 0 - a;
        } else if (strcmp("+", first_arg) == 0 && flag) {
          char *ptr = NULL;
          a = strtold(zero_arg, &ptr);
          answer = a;
        }
      }
    }
    if (peek(&stack)) {
      second_arg = pop(&stack);
    }
    if (flag) {
      if (second_arg) {
        if (is_binary_operand(second_arg)) {
          char *ptr = NULL;
          if ((strcmp("x", zero_arg) == 0)) {
            a = *x;
            b = strtold(first_arg, &ptr);
          } else if ((strcmp("x", first_arg) == 0)) {
            a = strtold(zero_arg, &ptr);
            b = *x;
          } else {
            a = strtod(zero_arg, NULL);
            b = strtod(first_arg, NULL);
          }
          answer = binary_calc(a, b, second_arg, answer, flag);
          flag = 0;
        }
      } else if (is_unary_operand(first_arg)) {
        char *ptr = NULL;
        a = (!x) ? strtold(zero_arg, &ptr) : *x;
        answer = unary_calc(a, first_arg, answer, flag);
        flag = 0;
      }
    } else {
      if (is_binary_operand(second_arg)) {
        char *ptr = NULL;
        a = (!x) ? strtold(first_arg, &ptr) : *x;
        answer = binary_calc(a, b, second_arg, answer, flag);
        flag = 0;
      } else if (is_unary_operand(second_arg)) {
        char *ptr = NULL;
        a = (!x) ? strtold(first_arg, &ptr) : *x;
        answer = unary_calc(a, second_arg, answer, flag);
        flag = 0;
      }
    }
  }
  return answer;
}

double binary_calc(double a, double b, char *third_arg, double answer, int flag) {
  if (strcmp("+", third_arg) == 0) {
    answer = flag ? answer + a + b : answer + a;
  } else if (strcmp("^", third_arg) == 0) {
    answer = flag ? answer + pow(a, b) : pow(answer, a);
  } else if (strcmp("-", third_arg) == 0) {
    answer = flag ? answer + (a-b) : answer - a - b;
  } else if (strcmp("*", third_arg) == 0) {
    answer = flag ? answer + (a * b) : answer * a;
  } else if (strcmp("/", third_arg) == 0) {
    answer = flag ? (answer + (a/b)) : (answer / a);
  } else if (strcmp("%", third_arg) == 0) {
    answer = flag ? answer + (fmod(a, b)) : fmod(answer, a);
  }
  return answer;
}

double unary_calc(double a, char *second_arg, double answer, int flag) {
  if (strcmp("v", second_arg) == 0) {
    answer = flag ? sqrt(a) : sqrt(answer);
  } else if (strcmp("l", second_arg) == 0) {
    if (fabs(a) - 1 < 1e-7 && answer == 0) {
      return NAN;
    } else if (fabs(answer) - 1 < 1e-7 && a == 0) {
      return NAN;
    }
    answer = flag ? log(a) : log(answer);
  } else if (strcmp("L", second_arg) == 0) {
    if (fabs(a) - 1 < 1e-7 && answer == 0) {
      return NAN;
    } else if (fabs(answer) - 1 < 1e-7 && a == 0) {
      return NAN;
    }
    answer = flag ? log10(a) : log10(answer);
  } else if (strcmp("s", second_arg) == 0) {
    answer = flag ? sin(a) : sin(answer);
  } else if (strcmp("c", second_arg) == 0) {
    answer = flag ? cos(a) : cos(answer);
  } else if (strcmp("s", second_arg) == 0) {
    answer = flag ? sin(a) : sin(answer);
  } else if (strcmp("t", second_arg) == 0) {
    answer = flag ? tan(a) : tan(answer);
  } else if (strcmp("C", second_arg) == 0) {
    answer = flag ? acos(a) : acos(answer);
  } else if (strcmp("S", second_arg) == 0) {
    answer = flag ? asin(a) : asin(answer);
  } else if (strcmp("T", second_arg) == 0) {
    answer = flag ? atan(a) : atan(answer);
  }
  return answer;
}
