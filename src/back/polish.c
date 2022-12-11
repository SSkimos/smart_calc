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

      // если пусто, возвращаю его
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
    }

    // если я нашел унарный оператор
    if (!strcmp("M", first_arg) || !strcmp("P", first_arg)) {
      printf("43 M or P here op here\n");
      unary = strcmp("M", first_arg) ? 1 : -1;
      // TODO: придумать как обработать унарный прикол
    } else {
      printf("46 not unary op here\n");
      // беру второе значение
      if (peek(&stack)) {
        if (peek(&stack)) {
          second_arg = pop(&stack);
          printf("second = %s\n", second_arg);
        }
      }

      if (flag) {
        printf("first op here 56\n");
        if (second_arg) {
          printf("58 second arg\n");
          if (is_binary_operand(second_arg)) {
            printf("60\n");
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
            printf("76 answer = %f\n", answer);
          }
          unary = 0;
        } else if (is_unary_operand(first_arg)) {
          printf("80 uanry operand\n");
          char *ptr = NULL;
          a = (strcmp("x", zero_arg)) ? strtold(zero_arg, &ptr) : *x;
          answer = unary_calc(a, first_arg, answer, flag);
          printf("82 answer = %f\n", answer);
          unary = 0;
        }
        flag = 0;
      } else {
        printf("second+ op here 89\n");
        if (is_unary_operand(first_arg)) {
          char *ptr = NULL;
          answer = unary_calc(answer, first_arg, answer, 0);
          printf("90 answer = %f\n", answer);
          unary = 0;
        } else if (is_binary_operand(second_arg)) {
          char *ptr = NULL;
          a = (strcmp("x", first_arg)) ? strtold(first_arg, &ptr) : *x;
          answer = binary_calc(a, b, second_arg, answer, flag);
          printf("96 answer = %f\n", answer);
          unary = 0;
        }
      }
    }
  }
  if (unary != 0) {
    char *ptr = NULL;
    a = (strcmp("x", zero_arg)) ? strtold(zero_arg, &ptr) : *x;
    answer += a;
    answer *= unary;
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
