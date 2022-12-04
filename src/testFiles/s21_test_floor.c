#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(test_s21_math_floor_usual) {
  double testValue1 = -5.7;
  double testValue2 = 5.1;
  double testValue3 = 12.4;
  ck_assert_ldouble_ne_tol(s21_floor(testValue1), floor(testValue1), 0);
  ck_assert_ldouble_ne_tol(s21_floor(testValue2), floor(testValue2), 0);
  ck_assert_ldouble_ne_tol(s21_floor(testValue3), floor(testValue3), 0);
}
END_TEST

START_TEST(test_s21_math_floor_unusual) {
  double testValue1 = -10.45934;
  double testValue2 = 10.1;
  double testValue3 = 0;
  ck_assert_ldouble_ne_tol(s21_floor(testValue1), floor(testValue1), 0);
  ck_assert_ldouble_ne_tol(s21_floor(testValue2), floor(testValue2), 0);
  ck_assert_ldouble_ne_tol(s21_floor(testValue3), floor(testValue3), 0);
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