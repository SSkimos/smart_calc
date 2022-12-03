#include "calc.h"

char *find_number(int *i, char *number, char *current_str);

struct s21_stack *parser(struct s21_stack *output_stack, char *current_str) {
  struct s21_stack tmp_stack = make_stack();  // temp operand stack
  int iterator = 0;
  FILE *logs;
  logs = fopen("parser_logs.txt", "a");

  // main iter func
  for (int i = 0; i < strlen(current_str); i++) {
    fprintf(logs, ":debug: current iterator = '%d'\n", i);
    if (current_str[i] - '0' >= 0 && current_str[i] - '0' <= 9) {
      //TODO: add parser float number
      char *number = NULL;
      push(output_stack, find_number(&i, number, current_str));
    }
    if (current_str[i] == '(') {
      push(&tmp_stack, "(");
    }
    if (current_str[i] == ')') {
      while (strcmp(peek(&tmp_stack), "(") != 0) {
        push(output_stack, pop(&tmp_stack));
      }
      pop(&tmp_stack);
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
        push(output_stack, pop(&tmp_stack));
      }
      push(&tmp_stack, "*");
    }
    if (current_str[i] == '/') {
      // 3
      while ((strcmp(peek(&tmp_stack), "*") == 0)) {
        push(output_stack, pop(&tmp_stack));
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
    push(output_stack, pop(&tmp_stack));
  }
  // TODO: придумать коды ошибок
  fclose(logs);
  return output_stack;
}

char *find_number(int *i, char *number, char *current_str) {
    //TODO: add parser float number
    number = (char*)malloc(sizeof(char));
    number[0] = '\0';
    while (current_str[*i] - '0' >= 0 && current_str[*i] - '0' <= 9) {
        number = realloc(number, (int)strlen(number) + 1);
        number[(int)strlen(number)] = current_str[*i];
        (*i)++;
    }
    return number;
}
