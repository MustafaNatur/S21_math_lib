#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(test_s21_math_log_usual) {
  double testValue1 = S21_EXP;
  double testValue2 = 10;
  double testValue3 = 3;
  ck_assert_ldouble_eq_tol(s21_log(testValue1), log(testValue1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(testValue2), log(testValue2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(testValue3), log(testValue3), 1e-6);
  for (double i = 0.1; i < 100.0; i += 0.1) {
    ck_assert_ldouble_eq_tol(s21_log(i), log(i), 1e-6);
  }
}
END_TEST

START_TEST(test_s21_math_log_unusual) {
  double testValue1 = -1;
  double testValue2 = 0;
  double testValue3 = 0.00001;
  double base = 0.0083928293832;
  ck_assert_double_nan(s21_log(testValue1));
  ck_assert_ldouble_infinite(s21_log(testValue2));
  ck_assert_ldouble_eq_tol(s21_log(testValue3), log(testValue3), 0.00001);
  ck_assert_double_nan(s21_log(NAN));
  ck_assert_double_nan(s21_log(S21_NAN));
  ck_assert_double_nan(s21_log(-S21_NAN));
  ck_assert_ldouble_infinite(s21_log(POS_INF));
  ck_assert_ldouble_nan(s21_log(NEG_INF));
}
END_TEST

Suite *s21_math_log_suite() {
  Suite *s;
  TCase *tc_log_usual, *tc_log_unusual;

  s = suite_create("s21_log");

  tc_log_usual = tcase_create("s21_log_usual");
  tcase_add_test(tc_log_usual, test_s21_math_log_usual);
  suite_add_tcase(s, tc_log_usual);

  tc_log_unusual = tcase_create("s21_log_unusual");
  tcase_add_test(tc_log_unusual, test_s21_math_log_unusual);
  suite_add_tcase(s, tc_log_unusual);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = s21_math_log_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}