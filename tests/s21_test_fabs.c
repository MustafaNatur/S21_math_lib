#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(test_s21_math_fabs_usual) {
  double testValue1 = -5.503;
  double testValue2 = 5.0;
  double testValue3 = 0;
  ck_assert_ldouble_eq(s21_fabs(testValue1), fabs(testValue1));
  ck_assert_ldouble_eq(s21_fabs(testValue2), fabs(testValue2));
  ck_assert_ldouble_eq(s21_fabs(testValue3), fabs(testValue3));
}
END_TEST

START_TEST(test_s21_math_fabs_unusual) {
  double testValue1 = -10.45934;
  double testValue2 = 10.1;
  double testValue3 = 0.0;
  ck_assert_ldouble_eq(s21_fabs(testValue1), fabs(testValue1));
  ck_assert_ldouble_eq(s21_fabs(testValue2), fabs(testValue2));
  ck_assert_ldouble_eq(s21_fabs(testValue3), fabs(testValue3));
}
END_TEST

Suite *s21_math_fabs_suite() {
  Suite *s;
  TCase *tc_fabs_usual, *tc_fabs_unusual;

  s = suite_create("s21_fabs");

  tc_fabs_usual = tcase_create("s21_fabs_usual");
  tcase_add_test(tc_fabs_usual, test_s21_math_fabs_usual);
  suite_add_tcase(s, tc_fabs_usual);

  tc_fabs_unusual = tcase_create("s21_fabs_unusual");
  tcase_add_test(tc_fabs_unusual, test_s21_math_fabs_unusual);
  suite_add_tcase(s, tc_fabs_unusual);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = s21_math_fabs_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}