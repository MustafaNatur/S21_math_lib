#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(test_s21_math_asin_usual) {
  ck_assert_ldouble_eq_tol(s21_asin(1.0), asin(1.0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_asin(-1.0), asin(-1.0), 0.000001);
  ck_assert_ldouble_eq_tol(s21_asin(0.0343), asin(0.0343), 0.000001);
  ck_assert_ldouble_eq_tol(s21_asin(-0.0232), asin(-0.0232), 0.000001);
  ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), 0.000001);
}
END_TEST

Suite *s21_math_asin_suite() {
  Suite *s;
  TCase *tc_asin_usual;

  s = suite_create("s21_asin");

  tc_asin_usual = tcase_create("s21_asin_usual");
  tcase_add_test(tc_asin_usual, test_s21_math_asin_usual);

  suite_add_tcase(s, tc_asin_usual);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = s21_math_asin_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}