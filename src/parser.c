#include "calc.h"

char *find_number(int *i, char *number, char *current_str);

void relocate_values(struct s21_stack *tmp_stack, struct s21_stack *output_stack, int priority) {
  char list[7] = "(+-*/^";
  char *value = NULL;
  int i = 0;
  int j = 0;
  if (priority == ZERO_LEVEL) {
    if (peek(tmp_stack)) {
      if (peek(tmp_stack)[0] != list[i]) {
        value = pop(tmp_stack);
        push(output_stack, value);
        relocate_values(tmp_stack, output_stack, priority);
      } else {
        pop(tmp_stack);
      }
    }
  } else {
    if (priority == FIRST_LEVEL) { i = 5; j = 1; }
    if (priority == SECOND_LEVEL) { i = 5; j = 2; }
    if (priority == THIRD_LEVEL) { i = 5; j = 4; }
    for (; i > j; i--) {
      if (peek(tmp_stack)) {
        if (peek(tmp_stack)[0] == list[i]) {
          value = pop(tmp_stack);
          push(output_stack, value);
          relocate_values(tmp_stack, output_stack, priority);
        }
      }
    }
  }
}

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
        free(number);
        number = NULL;
      }
    }
    if (current_str[i] == '(') {
      push(&tmp_stack, "(");
    }
    if (current_str[i] == ')') {
      relocate_values(&tmp_stack, output_stack, ZERO_LEVEL);
    }
    if (current_str[i] == '+') {
      // 2
      relocate_values(&tmp_stack, output_stack, FIRST_LEVEL);
      push(&tmp_stack, "+");
    }
    if (current_str[i] == '-') {
      // 2
      relocate_values(&tmp_stack, output_stack, FIRST_LEVEL);
      push(&tmp_stack, "-");
    }
    if (current_str[i] == '*') {
      // 3
      relocate_values(&tmp_stack, output_stack, SECOND_LEVEL);
      push(&tmp_stack, "*");
    }
    if (current_str[i] == '/') {
      // 3
      relocate_values(&tmp_stack, output_stack, SECOND_LEVEL);
      push(&tmp_stack, "/");
    }
    if (current_str[i] == '^') {
      // 4
      relocate_values(&tmp_stack, output_stack, SECOND_LEVEL);
      push(&tmp_stack, "^");
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
