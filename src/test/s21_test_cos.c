#include "math.h"
#include "../s21_math.h"
#include <check.h>
#include <stdlib.h>

START_TEST(test_s21_math_cos) {
  int testValue1 = 1000;
  int testValue2 = -30030403;
  int testValue3 = 0.0005;
  int testValue4 = 0.98439849385;

  ck_assert_ldouble_ne_tol(s21_cos(testValue1), cos(testValue1), 0);
  ck_assert_ldouble_ne_tol(s21_cos(testValue2), cos(testValue2), 0);
  ck_assert_ldouble_ne_tol(s21_cos(testValue3), cos(testValue3), 0);
  ck_assert_ldouble_ne_tol(s21_cos(testValue4), cos(testValue4), 0);
}
END_TEST

Suite *s21_math_cos_suite() {
  Suite *s;
  TCase *tc_cos;

  s = suite_create("s21_cos");

  tc_cos = tcase_create("s21_cos");
  tcase_add_test(tc_cos, test_s21_math_cos);
  suite_add_tcase(s, tc_cos);
  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = s21_math_cos_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
