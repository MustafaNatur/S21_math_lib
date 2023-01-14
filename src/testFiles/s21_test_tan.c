#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(test_s21_math_tan) {
  int testValue1 = 1000;
  int testValue2 = -3003;
  double testValue3 = 0.0005;
  double testValue4 = 0.98439849385;
  double testValue5 = S21_PI;

  ck_assert_ldouble_eq_tol(s21_tan(testValue1), tan(testValue1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(testValue2), tan(testValue2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(testValue3), tan(testValue3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(testValue4), tan(testValue4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(testValue5), tan(testValue5), 1e-6);
}
END_TEST

Suite *s21_math_tan_suite() {
  Suite *s;
  TCase *tc_tan;

  s = suite_create("s21_tan");

  tc_tan = tcase_create("s21_tan");
  tcase_add_test(tc_tan, test_s21_math_tan);
  suite_add_tcase(s, tc_tan);
  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = s21_math_tan_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
