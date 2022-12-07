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
  ck_assert_float_eq(log(10), ans);

  char *str11 = "ln(10)";
  ans = polish(str11, NULL);
  ck_assert_float_eq(log10(10), ans);
}

START_TEST(float_tests) {
  char *str1 = "1.5*2";
  double ans = polish(str1, NULL);
  ck_assert_float_eq(3, ans);
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
  char *str1 = "1000)";
  double ans = polish(str1, NULL);
  ck_assert_float_eq(0, ans);

  char *str2 = "1000+900";
  ans = polish(str2, NULL);
  ck_assert_float_eq(1900, ans);
}

START_TEST(one_arg) {
  char *str2 = "200";
  double ans = polish(str2, NULL);
  ck_assert_float_eq(200, ans);
}

START_TEST(log1) {
  char *str1 = "log(1)";
  double ans = polish(str1, NULL);
  ck_assert_float_eq(fabs(ans) - 1 < 1e-7, 0);
}

START_TEST(lg1) {
  char *str1 = "log(1)";
  double ans = polish(str1, NULL);
  ck_assert_float_eq(fabs(ans) - 1 < 1e-7, 0);
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
  char *str1 = "sin(x)";
  double num = 3;
  double ans = polish(str1, &num);
  ck_assert_double_eq_tol(sin(3), ans, 1e-7);
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
  tcase_add_test(tcase_core, lg1);
  tcase_add_test(tcase_core, log1);
  tcase_add_test(tcase_core, one_arg);

  tcase_add_test(tcase_core, credit);
//  tcase_add_test(tcase_core, uniq_case);

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
