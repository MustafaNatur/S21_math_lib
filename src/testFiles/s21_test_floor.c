#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(test_s21_math_floor_usual) {
  double testValue1 = -5.7;
  double testValue2 = 5.1;
  double testValue3 = 12.4;
  ck_assert_ldouble_eq_tol(s21_floor(testValue1), floor(testValue1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_floor(testValue2), floor(testValue2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_floor(testValue3), floor(testValue3), 1e-6);
  for (double i = -2.01; i <= 1.01; i += 0.01) {
    ck_assert_ldouble_eq_tol(s21_floor(i), floor(i), 1e-6);
  }
}
END_TEST

START_TEST(test_s21_math_floor_unusual) {
  double testValue1 = POS_INF;
  double testValue2 = NEG_INF;
  double testValue3 = S21_NAN;
  ck_assert_double_infinite(s21_floor(testValue1));
  ck_assert_double_infinite(s21_floor(testValue2));
  ck_assert_double_nan(s21_floor(testValue3));
}
END_TEST

Suite *s21_math_floor_suite() {
  Suite *s;
  TCase *tc_floor_usual, *tc_floor_unusual;

  s = suite_create("s21_floor");

  tc_floor_usual = tcase_create("s21_floor_usual");
  tcase_add_test(tc_floor_usual, test_s21_math_floor_usual);
  suite_add_tcase(s, tc_floor_usual);

  tc_floor_unusual = tcase_create("s21_floor_unusual");
  tcase_add_test(tc_floor_unusual, test_s21_math_floor_unusual);
  suite_add_tcase(s, tc_floor_unusual);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = s21_math_floor_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}