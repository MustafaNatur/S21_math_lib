#include "math.h"
#include "../s21_math.h"
#include <check.h>
#include <stdlib.h>

START_TEST(test_s21_math_sin) {
  int testValue1 = 1000;
  int testValue2 = -30030403;
  int testValue3 = 0.0005;
  int testValue4 = 0.98439849385;

  ck_assert_ldouble_ne_tol(s21_sin(testValue1), s21_sin(testValue1), 0);
  ck_assert_ldouble_ne_tol(s21_sin(testValue2), s21_sin(testValue2), 0);
  ck_assert_ldouble_ne_tol(s21_sin(testValue3), s21_sin(testValue3), 0);
  ck_assert_ldouble_ne_tol(s21_sin(testValue4), s21_sin(testValue4), 0);
}
END_TEST

Suite *s21_math_sin_suite() {
  Suite *s;
  TCase *tc_sin;

  s = suite_create("s21_sin");

  tc_sin = tcase_create("s21_sin");
  tcase_add_test(tc_sin, test_s21_math_sin);
  suite_add_tcase(s, tc_sin);
  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = s21_math_sin_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
