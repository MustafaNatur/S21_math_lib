#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(test_s21_math_asin_usual) {
  double step=0.1;
  for (double i = -1; i <= 1; i+=step) {
    ck_assert_ldouble_ne_tol(s21_asin(i), asin(i), 0);
  }
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