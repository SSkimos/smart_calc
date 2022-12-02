#include "calc.h"

void push(struct s21_stack *stack, char* value) {
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
  if (stack->size <= 0) {
    printf("err: invalid pop (no elements in stack)\n");
    exit(0);
  } else {
    char *elem = strdup(stack->data[stack->size - 1]);
    free((stack->data[stack->size - 1]));
    stack->size--;
    return elem;
  }
}

char *peek(struct s21_stack *stack) {
  if (stack->size <= 0) {
    printf("err: invalid peek (no elements in stack)\n");
    exit(0);
  } else {
    char *elem = strdup(stack->data[stack->size - 1]);
    return elem;
  }
}

struct s21_stack make_stack() {
  struct s21_stack stack;
  stack.data = NULL;
  stack.size = 0;
  return stack;
}
