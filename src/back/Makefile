CC = gcc
WARNING =
SANITIZE = -g -fsanitize=address
CFLAGS = -std=c11 -pedantic $(WARNING) # -g -fsanitize=address
LFLAGS ?= $(shell pkg-config --cflags --libs check)
INC_CHECK ?= $(shell pkg-config --cflags check)

STACK_O := $(stek.c:%.c=$(BUILD_DIR)/%.o)

all: s21_stack.a test

s21_stack.a: $(STACK_O)
	$(CC) -c $(CFLAGS) stack.c --coverage
	ar rc $@ *.o
	ranlib $@

test: s21_stack.a
	$(CC) tests/s21_calc_tests.c parser.c polish.c $(INC_CHECK) $(CFLAGS) $(LFLAGS) $(SANITIZE) --coverage -lcheck s21_stack.a -o test.out
	./test.out


rebuild: clean all

clean:
	rm -rf *.o *.a test *.html *.css *.out *.gcda *.gcno test.dSYM
	rm -f .clang-format
	rm parser_logs.txt

