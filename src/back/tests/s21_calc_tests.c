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
  clear_stack(&stack);
} END_TEST

START_TEST(stack_with_one_number) {
  char *str1 = "22";
  struct s21_stack stack1 = make_stack();
  struct s21_stack *final_stack1;

  final_stack1 = parser(&stack1, str1);
  ck_assert_int_eq(0, strcmp(str1, pop(final_stack1)));
  clear_stack(&stack1);

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

START_TEST(medium_well_parser_test) {
  char *str = "3+4*2/(123+200)";
  char *str1 = "+";
  char *str2 = "/";
  char *str3 = "+";
  char *str4 = "200";
  char *str5 = "123";
  char *str6 = "*";
  char *str7 = "2";
  char *str8 = "4";
  char *str9 = "3";
  struct s21_stack stack1 = make_stack();
  parser(&stack1, str);
  ck_assert_int_eq(0, strcmp(str1, pop(&stack1)));
  ck_assert_int_eq(0, strcmp(str2, pop(&stack1)));
  ck_assert_int_eq(0, strcmp(str3, pop(&stack1)));
  ck_assert_int_eq(0, strcmp(str4, pop(&stack1)));
  ck_assert_int_eq(0, strcmp(str5, pop(&stack1)));
  ck_assert_int_eq(0, strcmp(str6, pop(&stack1)));
  ck_assert_int_eq(0, strcmp(str7, pop(&stack1)));
  ck_assert_int_eq(0, strcmp(str8, pop(&stack1)));
  ck_assert_int_eq(0, strcmp(str9, pop(&stack1)));
} END_TEST

START_TEST(hard_parse_test) {
  char *str = "(sin(2)+cos(3))^(400-1000/200)";
  char *str1 = "^";
  char *str2 = "-";
  char *str3 = "/";
  char *str4 = "200";
  char *str5 = "1000";
  char *str6 = "400";
  char *str7 = "+";
  char *str8 = "c";
  char *str9 = "3";
  char *str10 = "s";
  char *str11 = "2";
  struct s21_stack stack1 = make_stack();
  parser(&stack1, str);
  ck_assert_int_eq(0, strcmp(str1, pop(&stack1)));
  ck_assert_int_eq(0, strcmp(str2, pop(&stack1)));
  ck_assert_int_eq(0, strcmp(str3, pop(&stack1)));
  ck_assert_int_eq(0, strcmp(str4, pop(&stack1)));
  ck_assert_int_eq(0, strcmp(str5, pop(&stack1)));
  ck_assert_int_eq(0, strcmp(str6, pop(&stack1)));
  ck_assert_int_eq(0, strcmp(str7, pop(&stack1)));
  ck_assert_int_eq(0, strcmp(str8, pop(&stack1)));
  ck_assert_int_eq(0, strcmp(str9, pop(&stack1)));
  ck_assert_int_eq(0, strcmp(str10, pop(&stack1)));
  ck_assert_int_eq(0, strcmp(str11, pop(&stack1)));
} END_TEST

START_TEST(first_full_back) {
  char *str1 = "2+2";
  long double ans = polish(str1);
  ck_assert_float_eq(4, ans);

  char *str2 = "4-2";
  ans = polish(str2);
  ck_assert_float_eq(2, ans);

  char *str3 = "2*200";
  ans = polish(str3);
  ck_assert_float_eq(400, ans);

  char *str4 = "1000/2";
  ans = polish(str4);
  ck_assert_float_eq(500, ans);
}

START_TEST(advanced_tests) {
  char *str1 = "800/2*16+888";
  long double ans = polish(str1);
  ck_assert_float_eq(7288, ans);

  char *str2 = "200%2";
  ans = polish(str2);
  ck_assert_float_eq(0, ans);

  char *str3 = "201%2";
  ans = polish(str3);
  ck_assert_float_eq(1, ans);

//  char *str4 = "2^2";
//  ans = polish(str4);
//  ck_assert_float_eq(4, ans);

  char *str5 = "sqrt(4)";
  ans = polish(str5);
  ck_assert_float_eq(2, ans);

  char *str6 = "log(10)";
  ans = polish(str6);
  ck_assert_float_eq(log(10), ans);

  char *str7 = "ln(10)";
  ans = polish(str7);
  ck_assert_float_eq(log10(10), ans);
}

START_TEST(float_tests) {
  char *str1 = "1.5*2";
  long double ans = polish(str1);
  ck_assert_float_eq(3, ans);
}

START_TEST(u_minus) {
  char *str1 = "-2";
  long double ans = polish(str1);
  ck_assert_float_eq(-2, ans);
}

START_TEST(easy_trigonometry_tests) {
  char *str1 = "cos(1)";
  long double ans = polish(str1);
  ck_assert_double_eq_tol(cos(1), ans, 1e-7);

  char *str2 = "sin(1)";
  ans = polish(str2);
  ck_assert_double_eq_tol(sin(1), ans, 1e-7);

  char *str3 = "tan(1)";
  ans = polish(str3);
  ck_assert_double_eq_tol(tan(1), ans, 1e-7);

  char *str4 = "acos(1)";
  ans = polish(str4);
  ck_assert_double_eq_tol(acos(1), ans, 1e-7);

  char *str5 = "asin(1)";
  ans = polish(str5);
  ck_assert_double_eq_tol(asin(1), ans, 1e-7);

  char *str6 = "atan(1)";
  ans = polish(str6);
  ck_assert_double_eq_tol(atan(1), ans, 1e-7);
}

Suite *s21_calc_suite(void) {
  Suite *suite;

  suite = suite_create("s21_calc");
  TCase *tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, simple_stack_test);
  tcase_add_test(tcase_core, stack_with_one_number);
  tcase_add_test(tcase_core, simple_parser_test);
  tcase_add_test(tcase_core, medium_parser_test);
  tcase_add_test(tcase_core, medium_well_parser_test);
  tcase_add_test(tcase_core, hard_parse_test);
  tcase_add_test(tcase_core, first_full_back);
  tcase_add_test(tcase_core, advanced_tests);
  tcase_add_test(tcase_core, float_tests);
  tcase_add_test(tcase_core, u_minus);

  tcase_add_test(tcase_core, easy_trigonometry_tests);

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
