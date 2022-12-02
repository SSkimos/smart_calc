#include <check.h>
#include "../calc.h"

START_TEST(simple_stack_test) {
  char *str = "123";
  struct s21_stack stack = make_stack();
  push(&stack, str);
  char *str2 = "123124214124";
  push(&stack, str2);
  ck_assert_int_eq(0, strcmp(str2, pop(&stack)));
  ck_assert_int_eq(0, strcmp(str, pop(&stack)));
} END_TEST

START_TEST(stack_with_one_number) {
  char *str1 = "22";
  struct s21_stack stack1 = make_stack();
  struct s21_stack *final_stack1;

  final_stack1 = parser(&stack1, str1);
  ck_assert_int_eq(0, strcmp(str1, pop(final_stack1)));

  char *str2 = "2 2";
  char *str = "2";
  struct s21_stack stack2 = make_stack();
  struct s21_stack *final_stack2;

  final_stack2 = parser(&stack2, str2);
  ck_assert_int_eq(0, strcmp(str, pop(final_stack2)));
  ck_assert_int_eq(0, strcmp(str, pop(final_stack2)));
} END_TEST

START_TEST(simple_parser_test) {
  char *str = "2 + 2";
  char *str1 = "2";
  char *str2 = "+";
  struct s21_stack stack1 = make_stack();
  parser(&stack1, str);
  ck_assert_int_eq(0, strcmp(str2, pop(&stack1)));
} END_TEST

START_TEST(medium_parser_test) {
  char *str = "3+4*2";
  char *str1 = "+";
  char *str2 = "*";
  char *str3 = "2";
  char *str4 = "4";
  char *str5 = "3";
  struct s21_stack stack1 = make_stack();
  parser(&stack1, str);
  ck_assert_int_eq(0, strcmp(str1, pop(&stack1)));
  ck_assert_int_eq(0, strcmp(str2, pop(&stack1)));
  ck_assert_int_eq(0, strcmp(str3, pop(&stack1)));
  ck_assert_int_eq(0, strcmp(str4, pop(&stack1)));
  ck_assert_int_eq(0, strcmp(str5, pop(&stack1)));
} END_TEST

//START_TEST(medium_well_parser_test) {
//  char *str = "3+4*2/(1-5)^2";
//  char *new_str;
//  new_str = parser(str);
//  ck_assert_str_eq("342*15-2^/+", new_str);
//} END_TEST

Suite *s21_calc_suite(void) {
  Suite *suite;

  suite = suite_create("s21_calc");
  TCase *tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, simple_stack_test);
  tcase_add_test(tcase_core, stack_with_one_number);
  tcase_add_test(tcase_core, simple_parser_test);
  tcase_add_test(tcase_core, medium_parser_test);
//  tcase_add_test(tcase_core, medium_well_parser_test);

  suite_add_tcase(suite, tcase_core);

  return suite;
}

int main(void) {
  Suite *suite = s21_calc_suite();
  SRunner *suite_runner = srunner_create(suite);
  //  srunner_set_fork_status(suite_runner, CK_NOFORK);
  srunner_run_all(suite_runner, CK_VERBOSE);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
