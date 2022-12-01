#include "math.h"
#include "../s21_math.h"
#include <check.h>
#include <stdlib.h>

START_TEST(test_s21_math_cos_usual) {
  int testValue1 = -5;
  int testValue2 = 5;
  int testValue3 = 0;
  ck_assert_int_eq(s21_cos(testValue1), s21_cos(testValue1));
  ck_assert_int_eq(s21_cos(testValue2), s21_cos(testValue2));
  ck_assert_int_eq(s21_cos(testValue3), s21_cos(testValue3));
}
END_TEST

START_TEST(test_s21_math_cos_unusual) {
  int testValue1 = -10;
  int testValue2 = 10;
  int testValue3 = 0;
  ck_assert_int_eq(s21_cos(testValue1), cos(testValue1));
  ck_assert_int_eq(s21_cos(testValue2), cos(testValue2));
  ck_assert_int_eq(s21_cos(testValue3), cos(testValue3));
}
END_TEST

Suite *s21_math_cos_suite() {
  Suite *s;
  TCase *tc_cos_usual, *tc_cos_unusual;

  s = suite_create("s21_cos");

  tc_cos_usual = tcase_create("s21_cos_usual");
  tcase_add_test(tc_cos_usual, test_s21_math_cos_usual);
  suite_add_tcase(s, tc_cos_usual);

  tc_cos_unusual = tcase_create("s21_cos_unusual");
  tcase_add_test(tc_cos_unusual, test_s21_math_cos_unusual);
  suite_add_tcase(s, tc_cos_unusual);

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
