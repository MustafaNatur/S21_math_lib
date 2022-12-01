#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(test_s21_math_exp_usual) {
  double testValue1 = -5;
  double testValue2 = 5;
  double testValue3 = 0.1;
  ck_assert_ldouble_eq(s21_exp(testValue1), exp(testValue1));
  ck_assert_ldouble_eq(s21_exp(testValue2), exp(testValue2));
  ck_assert_ldouble_eq(s21_exp(testValue3), exp(testValue3));
}
END_TEST

START_TEST(test_s21_math_exp_unusual) {
  double testValue1 = 100.4353425;
  double testValue2 = -100.4353425;
  double testValue3 = 0.0;
  ck_assert_ldouble_eq(s21_exp(testValue1), exp(testValue1));
  ck_assert_ldouble_eq(s21_exp(testValue2), exp(testValue2));
  ck_assert_ldouble_eq(s21_exp(testValue3), exp(testValue3));
}
END_TEST

Suite *s21_math_exp_suite() {
  Suite *s;
  TCase *tc_exp_usual, *tc_exp_unusual;

  s = suite_create("s21_exp");

  tc_exp_usual = tcase_create("s21_exp_usual");
  tcase_add_test(tc_exp_usual, test_s21_math_exp_usual);
  suite_add_tcase(s, tc_exp_usual);

  tc_exp_unusual = tcase_create("s21_exp_unusual");
  tcase_add_test(tc_exp_unusual, test_s21_math_exp_unusual);
  suite_add_tcase(s, tc_exp_unusual);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = s21_math_exp_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}