#include "calc.h"

char *s21_strdup(char *old_str) {
  char *new_str = NULL;
  if (old_str) {
    new_str = malloc((int)strlen(old_str));
    strcpy(new_str, old_str);
  }
  return new_str;
}

void push(struct s21_stack *stack, char *value) {
  if (stack->size == 0) {
    stack->data = calloc(1, sizeof(char *));
  } else if (stack->size >= 1) {
    stack->data = realloc(stack->data, (stack->size + 1) * sizeof(char *));
  } else {
    printf("err: invalid push\n");
  }
  stack->data[stack->size] = strdup(value);
  stack->size += 1;
}

char *pop(struct s21_stack *stack) {
  char *elem = NULL;
  if (stack->size > 0) {
    elem = s21_strdup(stack->data[stack->size - 1]);
    free((stack->data[stack->size - 1]));
    stack->size--;
  }
  return elem;
}

char *peek(struct s21_stack *stack) {
  char *elem = NULL;
  if (stack->size > 0) {
    elem = s21_strdup(stack->data[stack->size - 1]);
  }
  return elem;
}

struct s21_stack make_stack() {
  struct s21_stack stack;
  stack.data = NULL;
  stack.size = 0;
  return stack;
}

void clear_stack(struct s21_stack *stack) {
  while (peek(stack) != NULL) {
    pop(stack);
  }
}
