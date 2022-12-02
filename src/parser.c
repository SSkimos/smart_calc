#include "calc.h"
#include <string.h>
#include <stdlib.h>


struct s21_stack make_stack() {
  struct s21_stack stack;
  stack.data = NULL;
  stack.size = 0;
  return stack;
}

char *parser(char *current_str) {
  struct s21_stack stack = make_stack();  // temp operand stack
  struct s21_stack ans = make_stack();  // final stack

  int iterator = 0;

  // main iter func
  for (int i = 0; i < strlen(current_str); i++) {
    if (current_str[i] - '0' >= 0 && current_str[i] - '0' <= 9) {
      //TODO: it is number
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
  return buffer_string;
}
