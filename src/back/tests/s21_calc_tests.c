#include <check.h>
#include "../calc.h"

START_TEST(primitive_operations) {
  char *str1 = "2+2";
  double ans = polish(str1, NULL);
  ck_assert_float_eq(4, ans);

  char *str2 = "4-2";
  ans = polish(str2, NULL);
  ck_assert_float_eq(2, ans);

  char *str3 = "2*200";
  ans = polish(str3, NULL);
  ck_assert_float_eq(400, ans);

  char *str4 = "1000/2";
  ans = polish(str4, NULL);
  ck_assert_float_eq(500, ans);

  char *str5 = "800/2*16+888";
  ans = polish(str5, NULL);
  ck_assert_float_eq(7288, ans);

  char *str6 = "200%2";
  ans = polish(str6, NULL);
  ck_assert_float_eq(0, ans);

  char *str7 = "201%2";
  ans = polish(str7, NULL);
  ck_assert_float_eq(1, ans);

  char *str8 = "2^2";
  ans = polish(str8, NULL);
  ck_assert_float_eq(4, ans);

  char *str9 = "sqrt(4)";
  ans = polish(str9, NULL);
  ck_assert_float_eq(2, ans);

  char *str10 = "log(10)";
  ans = polish(str10, NULL);
  ck_assert_float_eq(log10(10), ans);

  char *str11 = "ln(10)";
  ans = polish(str11, NULL);
  ck_assert_float_eq(log(10), ans);

  char *str12 = "x+x";
  double x = 3;
  ans = polish(str12, &x);
  ck_assert_double_eq_tol(6, ans, 1e-7);

  char *str13 = "2-2-2";
  ans = polish(str13, NULL);
  ck_assert_double_eq_tol(-2, ans, 1e-7);

  char *str14 = "2+2+2+2";
  ans = polish(str14, NULL);
  ck_assert_double_eq_tol(8, ans, 1e-7);
}

START_TEST(float_tests) {
  char *str1 = "1.5*2";
  double ans = polish(str1, NULL);
  ck_assert_double_eq_tol(3, ans, 1e-7);

  char *str12 = "22+0.3";
  ans = polish(str12, NULL);
  ck_assert_double_eq_tol(22.3, ans, 1e-7);
}

START_TEST(u_minus) {
  char *str1 = "-2";
  double ans = polish(str1, NULL);
  ck_assert_float_eq(-2, ans);
}

START_TEST(primitive_trigonometry_tests) {
  char *str1 = "cos(1)";
  double ans = polish(str1, NULL);
  ck_assert_double_eq_tol(cos(1), ans, 1e-7);

  char *str2 = "sin(1)";
  ans = polish(str2, NULL);
  ck_assert_double_eq_tol(sin(1), ans, 1e-7);

  char *str3 = "sin(x)";
  double num = 1;
  ans = polish(str3, &num);
  ck_assert_double_eq_tol(sin(1), ans, 1e-7);

  char *str4 = "tan(1)";
  ans = polish(str4, NULL);
  ck_assert_double_eq_tol(tan(1), ans, 1e-7);

  char *str5 = "acos(1)";
  ans = polish(str5, NULL);
  ck_assert_double_eq_tol(acos(1), ans, 1e-7);

  char *str6 = "asin(1)";
  ans = polish(str6, NULL);
  ck_assert_double_eq_tol(asin(1), ans, 1e-7);

  char *str7 = "atan(1)";
  ans = polish(str7, NULL);
  ck_assert_double_eq_tol(atan(1), ans, 1e-7);
}

START_TEST(x_val) {
  char *str1 = "2+x";
  double x = 3;
  double ans = polish(str1, &x);
  ck_assert_float_eq(5, ans);
}

START_TEST(exceptions_test) {
  char *str2 = "1000+900";
  double ans = polish(str2, NULL);
  ck_assert_float_eq(1900, ans);
}

START_TEST(one_arg) {
  char *str2 = "200";
  double ans = polish(str2, NULL);
  ck_assert_float_eq(200, ans);
}

START_TEST(sqrt_case) {
  char *str1 = "sqrt(25)";
  double ans = polish(str1, NULL);
  ck_assert_double_eq_tol(5, ans, 1e-7);

  char *str2 = "sqrt(x)";
  double x = 25;
  ans = polish(str2, &x);
  ck_assert_double_eq_tol(5, ans, 1e-7);
}

START_TEST(brackets) {
  char *str1 = "sin(1)";
  int ans = check_brackets(str1);
  ck_assert_double_eq_tol(0, ans, 1e-7);
}

START_TEST(number) {
  char *str1 = "10";
  int ans = is_number(str1);
  ck_assert_double_eq_tol(1, ans, 1e-7);
}

START_TEST(iks) {
  char *str1 = "x";
  int ans = check_x(str1);
  ck_assert_double_eq_tol(1, ans, 1e-7);
}

START_TEST(credit) {
  struct s21_credit_input input = {0};
  input.sum = 20000.0;
  input.term = 36.0;
  input.percent = 12.0;
  input.type = 1;
  struct s21_credit_out output = {0};
  credit_calc(&input, &output);
  ck_assert_double_eq_tol(output.monthly_payment, 664.29, 1e-7);
}

START_TEST(uniq_case) {
  char *str1 = "ln(10)";
  double ans = polish(str1, NULL);
  ck_assert_double_eq_tol(log(10), ans, 1e-7);
}

START_TEST(invalid_cases) {
  char *str1 = "sqrt(25) + 5";
  double ans = polish(str1, NULL);
  ck_assert_double_eq_tol(10, ans, 1e-7);

  char *str2 = "sqrt(x) + 5";
  double a = 25;
  ans = polish(str2, &a);
  ck_assert_double_eq_tol(10, ans, 1e-7);

  char *str3 = "800/2*16+888";
  a = 25;
  ans = polish(str3, &a);
  ck_assert_double_eq_tol(7288, ans, 1e-7);

  char *str4 = "sqrt(20 + 5)";
  ans = polish(str4, NULL);
  ck_assert_double_eq_tol(5, ans, 1e-7);

  char *str5 = "sqrt(x + 5)";
  a = 20;
  ans = polish(str5, &a);
  ck_assert_double_eq_tol(5, ans, 1e-7);

  char *str6 = "ln(25 + 25 - 29)";
  a = 20;
  ans = polish(str6, &a);
  ck_assert_double_eq_tol(log(21), ans, 1e-7);

  char *str7 = "125 + 600 + 45 + (5 * 5)";
  ans = polish(str7, NULL);
  ck_assert_double_eq_tol(770, ans, 1e-7);

  char *str8 = "ln(-x)/(-5)";
  a = -0.1;
  ans = polish(str8, &a);
  ck_assert_double_eq_tol(log(0.1)/(-5), ans, 1e-7);

  char *str9 = "sqrt(-10-2+15)";
  ans = polish(str9, NULL);
  ck_assert_double_eq_tol(sqrt(-10 - 2 + 15), ans, 1e-7);

  char *str10 = "sqrt(x-1+1)";
  a = 12.3;
  ans = polish(str10, &a);
  ck_assert_double_eq_tol(sqrt(a-1+1), ans, 1e-7);

  char *str11 = "10 mod 2";
  ans = polish(str11, NULL);
  ck_assert_double_eq_tol(10 % 2, ans, 1e-7);

  char *str12 = "atan(x)";
  a = 0.5;
  ans = polish(str12, &a);
  ck_assert_double_eq_tol(atan(a), ans, 1e-7);
}

Suite *s21_calc_suite(void) {
  Suite *suite;

  suite = suite_create("s21_calc");
  TCase *tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, primitive_operations);
  tcase_add_test(tcase_core, float_tests);
  tcase_add_test(tcase_core, u_minus);

  tcase_add_test(tcase_core, primitive_trigonometry_tests);

  tcase_add_test(tcase_core, x_val);

  tcase_add_test(tcase_core, exceptions_test);
  tcase_add_test(tcase_core, sqrt_case);
  tcase_add_test(tcase_core, one_arg);

  tcase_add_test(tcase_core, credit);
  tcase_add_test(tcase_core, uniq_case);

  tcase_add_test(tcase_core, brackets);
  tcase_add_test(tcase_core, number);
  tcase_add_test(tcase_core, iks);

  tcase_add_test(tcase_core, invalid_cases);

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
