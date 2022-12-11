#include "calc.h"

double polish(char *str, double *x) {
  char *zero_arg = NULL;
  char *first_arg = NULL;
  char *second_arg = NULL;
  double a = 0.0;
  double b = 0.0;
  double answer = 0.0;
  int flag = 1;
  int unary = 0;

  struct s21_stack buffer = make_stack();
  parser(&buffer, str);
  struct s21_stack stack = make_stack();
  revert_stack(&buffer, &stack);

  while (peek(&stack)) {

    // беру нулевое значение и проверяю что дальше не пусто
    if (peek(&stack) && flag) {
      zero_arg = pop(&stack);
      printf("zero = %s\n", zero_arg);
      if (!peek(&stack)) {
        // one arg case
        char *ptr = NULL;
        a = (strcmp("x", zero_arg)) ? strtold(zero_arg, &ptr) : *x;
        answer += a;
        return answer;
      }
    }

    // беру первое значение и проверяю на унарный оператор
    if (peek(&stack)) {
      first_arg = pop(&stack);
      printf("first = %s\n", first_arg);
      if (is_binary_operand(first_arg)) {
        // unary cases
        if (strcmp("-", first_arg) == 0) {
          char *ptr = NULL;
          a = (strcmp("x", zero_arg)) ? strtold(zero_arg, &ptr) : *x;
          answer = 0 - a;
        } else if (strcmp("+", first_arg) == 0 && flag) {
          char *ptr = NULL;
          a = (strcmp("x", zero_arg)) ? strtold(zero_arg, &ptr) : *x;
          answer = a;
        }
      }
    }

    if (!flag && is_number(first_arg) && is_binary_operand(peek(&stack))) {
      printf("Я ЗАЕБАЛСЯ!\n");
    }

    // беру второе значение
    if (peek(&stack) && !is_unary_operand(first_arg)) {
      if (peek(&stack) && is_binary_operand(peek(&stack))) {
        second_arg = pop(&stack);
        printf("second = %s\n", second_arg);
      } else if (peek(&stack) && !flag && !is_unary_operand(peek(&stack))) {
        second_arg = pop(&stack);
        printf("secsecond = %s\n", second_arg);
      }
    }

    if (flag) {
      printf("129\n");
      if (second_arg) {
        printf("131\n");
        if (is_binary_operand(second_arg)) {
          printf("133\n");
          char *ptr = NULL;
          if ((strcmp("x", zero_arg) == 0) && (strcmp("x", first_arg) == 0)) {
            a = *x;
            b = *x;
          } else if ((strcmp("x", zero_arg) == 0)) {
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
          printf("149 answer = %f\n", answer);
        }
      } else if (is_unary_operand(first_arg)) {
        printf("161\n");
        char *ptr = NULL;
        a = (strcmp("x", zero_arg)) ? strtold(zero_arg, &ptr) : *x;
        answer = unary_calc(a, first_arg, answer, flag);
        printf("165 answer = %f\n", answer);
      }
      flag = 0;
    } else {
      if (is_unary_operand(first_arg)) {
        char *ptr = NULL;
        answer = unary_calc(answer, first_arg, answer, 0);
        printf("172 answer = %f\n", answer);
      } else if (is_binary_operand(second_arg)) {
        char *ptr = NULL;
        a = (strcmp("x", first_arg)) ? strtold(first_arg, &ptr) : *x;
        answer = binary_calc(a, b, second_arg, answer, flag);
        printf("177 answer = %f\n", answer);
      }
    }
    printf("ite1 done\n");
  }
  printf("answer = %f\n", answer);
  printf("===========\n");
  return answer;
}

double binary_calc(double a, double b, char *third_arg, double answer,
                   int flag) {
  printf("binary\n");
  printf("a = %f, b = %f, oper = %s, ans = %f\n", a, b, third_arg, answer);
  if (strcmp("+", third_arg) == 0) {
    answer = flag ? a + b : answer + a;
  } else if (strcmp("^", third_arg) == 0) {
    answer = flag ? answer + pow(a, b) : pow(answer, a);
  } else if (strcmp("-", third_arg) == 0) {
    answer = flag ? (a - b) : answer - a;
  } else if (strcmp("*", third_arg) == 0) {
    answer = flag ? answer + (a * b) : answer * a;
  } else if (strcmp("/", third_arg) == 0) {
    answer = flag ? (answer + (a / b)) : (answer / a);
  } else if (strcmp("%", third_arg) == 0) {
    answer = flag ? answer + (fmod(a, b)) : fmod(answer, a);
  }
  return answer;
}

double unary_calc(double a, char *second_arg, double answer, int flag) {
  printf("unary\n");
  printf("a = %f, sec = %s, ans = %f\n", a, second_arg, answer);
  if (strcmp("v", second_arg) == 0) {
    answer = flag ? sqrt(a) : sqrt(answer);
  } else if (strcmp("l", second_arg) == 0) {
    answer = flag ? log10(a) : log10(answer);
  } else if (strcmp("L", second_arg) == 0) {
    answer = flag ? log(a) : log(answer);
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

int is_unary_operand(char *c) {
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
