#include "calc.h"

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
      number = (char*)malloc(sizeof(char));
      number[0] = '\0';
      while (current_str[i] - '0' >= 0 && current_str[i] - '0' <= 9) {
        number = realloc(number, strlen(number) + 1);
        number[(int)strlen(number)] = current_str[i];
        fprintf(logs, ":debug: number = '%s'\n", number);
        i++;
      }
      push(output_stack, number);
    }
    if (current_str[i] == '(') {
      //TODO: it is bracket
    }
    if (current_str[i] == '+') {
      //TODO: it is plus
    }
    if (current_str[i] == '-') {
      //TODO: it is minus
    }
    if (current_str[i] == '*') {
      //TODO: it is multiplication
    }
    if (current_str[i] == '/') {
      //TODO: it is division
    }
    if (current_str[i] == '^') {
      //TODO: it is degree
    }
    if (current_str[i] == '~') {
      //TODO: it is unary minus
    }
  }

  // TODO: придумать коды ошибок
  fclose(logs);
  return output_stack;
}
