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

      // если пусто, возвращаю его
      if (!peek(&stack)) {
        // one arg case
        char *ptr = NULL;
        a = (strcmp("x", zero_arg)) ? strtold(zero_arg, &ptr) : *x;
        answer += a;
        return answer;
      }
    }

    // беру первое значение
    if (peek(&stack)) {
      first_arg = pop(&stack);
    }

    // проверяю первое значение на унарный
    if (!strcmp("M", first_arg) || !strcmp("P", first_arg)) {
      unary = strcmp("M", first_arg) ? 1 : -1;
      char *ptr = NULL;
      answer = (strcmp("x", zero_arg)) ? strtold(zero_arg, &ptr) : *x;
      answer *= unary;
      unary = 0;
      flag = 0;
    } else {
      // могу работать дальше

      // беру второе значение
      if (!is_unary_operand(first_arg)) {
        if (peek(&stack)) {
          second_arg = pop(&stack);

          // если это унарник, сработает магия
          if (!strcmp("M", second_arg) || !strcmp("P", second_arg)) {
            unary = strcmp("M", first_arg) ? -1 : 1;

            if (peek(&stack) && is_binary_operand(peek(&stack))) {
              second_arg = pop(&stack);
            }
          }
        }
      }

      // иначе начинаю считать
      if (flag) {
        if (second_arg) {
          if (is_binary_operand(second_arg)) {
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
          }
        } else if (is_unary_operand(first_arg)) {
          char *ptr = NULL;
          a = (strcmp("x", zero_arg)) ? strtold(zero_arg, &ptr) : *x;
          answer = unary_calc(a, first_arg, answer, flag);
        }
        flag = 0;
      } else {
        if (is_unary_operand(first_arg)) {
          char *ptr = NULL;
          answer = unary_calc(answer, first_arg, answer, 0);
        } else if (is_binary_operand(second_arg)) {
          char *ptr = NULL;
          a = (strcmp("x", first_arg)) ? strtold(first_arg, &ptr) : *x;
          if (unary != 0) {
            a *= unary;
          }
          answer = binary_calc(a, b, second_arg, answer, flag);
        }
      }
      unary = 0;
    }
  }
  return answer;
}

double binary_calc(double a, double b, char *third_arg, double answer,
                   int flag) {
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
  if (strcmp("v", c) == 0) {
    flag = 1;
  } else if (strcmp("l", c) == 0) {
    flag = 1;
  } else if (strcmp("L", c) == 0) {
    flag = 1;
  } else if (strcmp("s", c) == 0) {
    flag = 1;
  } else if (strcmp("c", c) == 0) {
    flag = 1;
  } else if (strcmp("t", c) == 0) {
    flag = 1;
  } else if (strcmp("S", c) == 0) {
    flag = 1;
  } else if (strcmp("C", c) == 0) {
    flag = 1;
  } else if (strcmp("T", c) == 0) {
    flag = 1;
  }
  return flag;
}

int is_binary_operand(char *c) {
  int flag = 0;
  if (strcmp("+", c) == 0) {
    flag = 1;
  } else if (strcmp("^", c) == 0) {
    flag = 1;
  } else if (strcmp("-", c) == 0) {
    flag = 1;
  } else if (strcmp("*", c) == 0) {
    flag = 1;
  } else if (strcmp("/", c) == 0) {
    flag = 1;
  } else if (strcmp("%", c) == 0) {
    flag = 1;
  }
  return flag;
}
