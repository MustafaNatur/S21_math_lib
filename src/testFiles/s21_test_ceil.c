#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(test_s21_math_ceil_usual) {
  double testValue1 = -5.7;
  double testValue2 = 5.1;
  double testValue3 = 12.4;
  ck_assert_ldouble_eq_tol(s21_ceil(testValue1), ceil(testValue1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(testValue2), ceil(testValue2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(testValue3), ceil(testValue3), 1e-6);
}
END_TEST

START_TEST(test_s21_math_ceil_unusual) {
  double testValue1 = -10.45934;
  double testValue2 = 10.1;
  double testValue3 = 0.0;
  ck_assert_ldouble_eq_tol(s21_ceil(testValue1), ceil(testValue1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(testValue2), ceil(testValue2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(testValue3), ceil(testValue3), 1e-6);
}
END_TEST

Suite *s21_math_ceil_suite() {
  Suite *s;
  TCase *tc_ceil_usual, *tc_ceil_unusual;

  s = suite_create("s21_ceil");

  tc_ceil_usual = tcase_create("s21_ceil_usual");
  tcase_add_test(tc_ceil_usual, test_s21_math_ceil_usual);
  suite_add_tcase(s, tc_ceil_usual);

  tc_ceil_unusual = tcase_create("s21_ceil_unusual");
  tcase_add_test(tc_ceil_unusual, test_s21_math_ceil_unusual);
  suite_add_tcase(s, tc_ceil_unusual);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = s21_math_ceil_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}