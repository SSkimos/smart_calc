#include "calc.h"

void relocate_values(struct s21_stack *tmp_stack,
                     struct s21_stack *output_stack, int priority) {
  char list[18] = "(+-PM*/%^cstCSTvlL";
  char *value = NULL;
  int i = 0;
  int j = 0;
  if (priority == ZERO_LEVEL) {
    if (peek(tmp_stack)) {
      if (peek(tmp_stack)[0] != list[0]) {
        value = pop(tmp_stack);
        push(output_stack, value);
        relocate_values(tmp_stack, output_stack, priority);
      } else {
        pop(tmp_stack);
      }
    }
  } else {
    if (priority == FIRST_LEVEL) {
      i = 17;
      j = 0;
    }
    if (priority == SECOND_LEVEL) {
      i = 17;
      j = 4;
    }
    if (priority == THIRD_LEVEL) {
      i = 17;
      j = 6;
    }
    if (priority == FOURTH_LEVEL) {
      i = 17;
      j = 8;
    }
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
  struct s21_stack tmp_stack = make_stack(); // temp operand stack
  int iterator = 0;
  char *value = NULL;

  // main iter func
  for (int i = 0; i < strlen(current_str); i++) {
    if (current_str[i] - '0' >= 0 && current_str[i] - '0' <= 9) {
      char *number = NULL;
      number = find_number(&i, number, current_str);
      if (number) {
        push(output_stack, number);
        free(number);
        number = NULL;
      }
    }
    if (current_str[i] == 'x') {
      push(output_stack, "x");
    } else if (current_str[i] == '(') {
      push(&tmp_stack, "(");
    } else if (current_str[i] == ')') {
      relocate_values(&tmp_stack, output_stack, ZERO_LEVEL);
    } else if (current_str[i] == '+') {
      if (!is_number(&current_str[i - 1]) && current_str[i - 1] != 'x' &&
          current_str[i - 1] != ')') {
        relocate_values(&tmp_stack, output_stack, FIRST_LEVEL);
        push(&tmp_stack, "P");
      } else if (i == 0) {
        push(&tmp_stack, "M");
      } else {
        relocate_values(&tmp_stack, output_stack, FIRST_LEVEL);
        push(&tmp_stack, "+");
      }
    } else if (current_str[i] == '-') {
      if (!is_number(&current_str[i - 1]) && current_str[i - 1] != 'x' &&
          current_str[i - 1] != ')') {
        relocate_values(&tmp_stack, output_stack, FIRST_LEVEL);
        push(&tmp_stack, "M");
      } else if (i == 0) {
        push(&tmp_stack, "M");
      } else {
        relocate_values(&tmp_stack, output_stack, FIRST_LEVEL);
        push(&tmp_stack, "-");
      }
    } else if (current_str[i] == '*') {
      relocate_values(&tmp_stack, output_stack, SECOND_LEVEL);
      push(&tmp_stack, "*");
    } else if (current_str[i] == '/') {
      relocate_values(&tmp_stack, output_stack, SECOND_LEVEL);
      push(&tmp_stack, "/");
    } else if (current_str[i] == '%') {
      relocate_values(&tmp_stack, output_stack, SECOND_LEVEL);
      push(&tmp_stack, "%");
    } else if (current_str[i] == '^') {
      relocate_values(&tmp_stack, output_stack, THIRD_LEVEL);
      push(&tmp_stack, "^");
    } else if (current_str[i] == 'c' && current_str[i + 1] == 'o' &&
               current_str[i + 2] == 's') {
      i += 2;
      relocate_values(&tmp_stack, output_stack, FOURTH_LEVEL);
      push(&tmp_stack, "c");
    } else if (current_str[i] == 's' && current_str[i + 1] == 'i' &&
               current_str[i + 2] == 'n') {
      i += 2;
      relocate_values(&tmp_stack, output_stack, FOURTH_LEVEL);
      push(&tmp_stack, "s");
    } else if (current_str[i] == 't' && current_str[i + 1] == 'a' &&
               current_str[i + 2] == 'n') {
      i += 2;
      relocate_values(&tmp_stack, output_stack, FOURTH_LEVEL);
      push(&tmp_stack, "t");
    } else if (current_str[i] == 'a' && current_str[i + 1] == 'c' &&
               current_str[i + 2] == 'o' && current_str[i + 3] == 's') {
      i += 3;
      relocate_values(&tmp_stack, output_stack, FOURTH_LEVEL);
      push(&tmp_stack, "C");
    } else if (current_str[i] == 'a' && current_str[i + 1] == 's' &&
               current_str[i + 2] == 'i' && current_str[i + 3] == 'n') {
      i += 3;
      relocate_values(&tmp_stack, output_stack, FOURTH_LEVEL);
      push(&tmp_stack, "S");
    } else if (current_str[i] == 'a' && current_str[i + 1] == 't' &&
               current_str[i + 2] == 'a' && current_str[i + 3] == 'n') {
      i += 3;
      relocate_values(&tmp_stack, output_stack, FOURTH_LEVEL);
      push(&tmp_stack, "T");
    } else if (current_str[i] == 's' && current_str[i + 1] == 'q' &&
               current_str[i + 2] == 'r' && current_str[i + 3] == 't') {
      i += 3;
      relocate_values(&tmp_stack, output_stack, FOURTH_LEVEL);
      push(&tmp_stack, "v");
    } else if (current_str[i] == 'l' && current_str[i + 1] == 'n') {
      i += 1;
      relocate_values(&tmp_stack, output_stack, FOURTH_LEVEL);
      push(&tmp_stack, "L");
    } else if (current_str[i] == 'l' && current_str[i + 1] == 'o' &&
               current_str[i + 2] == 'g') {
      i += 2;
      relocate_values(&tmp_stack, output_stack, FOURTH_LEVEL);
      push(&tmp_stack, "l");
    }
  }
  while (peek(&tmp_stack) != NULL) {
    value = pop(&tmp_stack);
    push(output_stack, value);
    free(value);
  }
  clear_stack(&tmp_stack);
  return output_stack;
}

char *find_number(int *i, char *number, char *current_str) {
  int size = 0;
  if (!number) {
    number = (char *)calloc(2, sizeof(char));
    number[0] = '\0';
  }
  while (current_str[*i] - '0' >= 0 && current_str[*i] - '0' <= 9) {
    number = realloc(number, size + 1);
    number[size] = current_str[*i];
    size++;
    (*i)++;
  }
  if (current_str[*i] == '.' || current_str[*i] == ',') {
    number = realloc(number, size + 1);
    number[size] = '.';
    size++;
    (*i)++;
    while (current_str[*i] - '0' >= 0 && current_str[*i] - '0' <= 9) {
      number = realloc(number, size + 1);
      number[size] = current_str[*i];
      size++;
      (*i)++;
    }
  }
  number = realloc(number, size + 1);
  number[size] = '\0';
  return number;
}

int check_brackets(char *str) {
  int sum = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (str[i] == ')') {
      sum += 1;
    } else if (str[i] == '(') {
      sum -= 1;
    }
  }
  return sum;
}

int check_x(char *str) {
  int sum = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (str[i] == 'x') {
      sum++;
    }
  }
  return sum;
}
