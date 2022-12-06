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

long double polish(char *str, long double *x) {
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
        // give operation
        third_arg = pop(&stack);
//        printf("th = %s\n", third_arg);
      }
      char *ptr = NULL;
      a = strtold(first_arg, &ptr);
      b = strtold(second_arg, &ptr);
      answer = binary_calc(a, b, third_arg, answer, flag);
      flag = 0;
    } else {
      char *ptr = NULL;
      a = strtold(first_arg, &ptr);
      answer = unary_calc(a, second_arg, answer, flag);
      flag = 0;
    }
  }
  return answer;
}

long double binary_calc(long double a, long double b, char *third_arg, long double answer, int flag) {
  if (strcmp("+", third_arg) == 0) {
    answer = flag ? answer + a + b : answer + a;
  } else if (strcmp("^", third_arg) == 0) {
    answer = flag ? answer + pow(a, b) : pow(answer, a);
  } else if (strcmp("-", third_arg) == 0) {
    answer = flag ? answer + (a-b) : answer - a-b;
  } else if (strcmp("*", third_arg) == 0) {
    answer = flag ? answer + (a * b) : answer * a;
  } else if (strcmp("/", third_arg) == 0) {
    answer = flag ? (answer + (a/b)) : (answer / a);
  } else if (strcmp("%", third_arg) == 0) {
    answer = flag ? answer + (fmod(a, b)) : fmod(answer, a);
  }
  return answer;
}

long double unary_calc(long double a, char *second_arg, long double answer, int flag) {
  if (strcmp("v", second_arg) == 0) {
    answer = flag ? sqrt(a) : sqrt(answer);
  } else if (strcmp("l", second_arg) == 0) {
    answer = flag ? log(a) : log(answer);
  } else if (strcmp("L", second_arg) == 0) {
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
