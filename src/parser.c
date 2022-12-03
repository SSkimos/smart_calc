#include "calc.h"

char *find_number(int *i, char *number, char *current_str);

struct s21_stack *parser(struct s21_stack *output_stack, char *current_str) {
  struct s21_stack tmp_stack = make_stack();  // temp operand stack
  int iterator = 0;
  char *value = NULL;
  FILE *logs;
  logs = fopen("parser_logs.txt", "a");

  // main iter func
  for (int i = 0; i < strlen(current_str); i++) {
    fprintf(logs, ":debug: current iterator = '%d'\n", i);
    if (current_str[i] - '0' >= 0 && current_str[i] - '0' <= 9) {
      //TODO: add parser float number
      char *number = NULL;
      number = find_number(&i, number, current_str);
      if (number) {
        push(output_stack, number);
      }
      if (number) {
        free(number);
        number = NULL;
      }
    }
    if (current_str[i] == '(') {
      push(&tmp_stack, "(");
    }
    if (current_str[i] == ')') {
      while (strcmp(peek(&tmp_stack), "(") != 0) {
        value = pop(&tmp_stack);
        push(output_stack, value);
        free(value);
      }
      value = pop(&tmp_stack);
      free(value);
    }
    if (current_str[i] == '+') {
      // 2
      push(&tmp_stack, "+");
    }
    if (current_str[i] == '-') {
      // 2
      push(&tmp_stack, "-");
    }
    if (current_str[i] == '*') {
      // 3
      while ((strcmp(peek(&tmp_stack), "/") == 0)) {
        value = pop(&tmp_stack);
        push(output_stack, value);
        free(value);
      }
      push(&tmp_stack, "*");
    }
    if (current_str[i] == '/') {
      // 3
      while ((strcmp(peek(&tmp_stack), "*") == 0)) {
        value = pop(&tmp_stack);
        push(output_stack, value);
        free(value);
      }
      push(&tmp_stack, "/");
    }
    if (current_str[i] == '^') {
      // 4
      //TODO: it is degree
    }
    if (current_str[i] == '~') {
      //TODO: it is unary minus
    }
  }
  while (peek(&tmp_stack) != NULL) {
    value = pop(&tmp_stack);
    push(output_stack, value);
    free(value);
  }
  // TODO: придумать коды ошибок
  clear_stack(&tmp_stack);
  fclose(logs);
  return output_stack;
}

char *find_number(int *i, char *number, char *current_str) {
  //TODO: add parser float number
  int size = 0;
  if (!number) {
    number = (char*)calloc(2, sizeof(char));
    number[0] = '\0';
  }
  while (current_str[*i] - '0' >= 0 && current_str[*i] - '0' <= 9) {
    number = realloc(number, size + 1);
    number[size] = current_str[*i];
    size++;
    (*i)++;
  }
  number = realloc(number, size + 1);
  number[size] = '\0';
  return number;
}
