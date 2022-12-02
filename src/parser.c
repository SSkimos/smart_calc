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

  char *buffer_string = NULL;
  int buffer_value = 0;
  int length = strlen(current_str);
  char *ptr = &current_str[0];

//  for (int i = 0; i < length; i++) {
//    if (*ptr - '0' >= 0 && *ptr - '0' <= 9) {
//      int exp = 1;
//      while (*ptr - '0' >= 0 && *ptr - '0' <= 9) {
//        if (!buffer_string) {
//          buffer_string = malloc(sizeof(char) * 2);
//          buffer_string[0] = '\0';
//          buffer_string[0] = *ptr;
//          ptr++;
//        } else {
//          buffer_string = realloc(&buffer_string, (int)strlen(buffer_string) + 1);
//          buffer_string[strlen(buffer_string)] = *ptr;
//          ptr++;
//        }
//      }
//      if (*ptr == '.') {
//        ptr++;
//        while (*ptr - '0' >= 0 && *ptr - '0' <= 9) {
//         //
//        }
//      } else {
//        push(&stack, buffer_value);
//      }
//    }
//  }
  // TODO: придумать коды ошибок
  return buffer_string;
}
