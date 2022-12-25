#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(test_s21_math_pow_big) {
  int base = -2989839;
  int exp1 = 0.0004;
  int exp2 = 100;
  int exp3 = 0;
  int exp4 = 55;
  int exp5 = -77;

  ck_assert_ldouble_ne_tol(s21_pow(base, exp1), pow(base, exp1), 0);
  ck_assert_ldouble_infinite(s21_pow(base, exp2));
  ck_assert_ldouble_ne_tol(s21_pow(base, exp3), pow(base, exp3), 0);
  ck_assert_ldouble_infinite(s21_pow(base, exp4));
  ck_assert_ldouble_ne_tol(s21_pow(base, exp5), pow(base, exp5), 0);
}
END_TEST

START_TEST(test_s21_math_pow_small) {
  int base = 0.0083928293832;
  int exp1 = 0.0004;
  int exp2 = 293;
  int exp3 = 0;
  int exp4 = 66;
  int exp5 = -99;

  ck_assert_ldouble_ne_tol(s21_pow(base, exp1), pow(base, exp1), 0);
  ck_assert_ldouble_ne_tol(s21_pow(base, exp2), pow(base, exp2), 0);
  ck_assert_ldouble_ne_tol(s21_pow(base, exp3), pow(base, exp3), 0);
  ck_assert_ldouble_ne_tol(s21_pow(base, exp4), pow(base, exp4), 0);
  ck_assert_ldouble_infinite(s21_pow(base, exp5));
}
END_TEST

Suite *s21_math_pow_suite() {
  Suite *s;
  TCase *tc_pow_big, *tc_pow_small;

  s = suite_create("pow");

  tc_pow_big = tcase_create("pow_big");
  tcase_add_test(tc_pow_big, test_s21_math_pow_big);
  suite_add_tcase(s, tc_pow_big);

  tc_pow_small = tcase_create("pow_small");
  tcase_add_test(tc_pow_small, test_s21_math_pow_small);
  suite_add_tcase(s, tc_pow_small);

  return s;
}

int main() {
  Suite *s;
  int failed = 0;
  SRunner *runner;

  s = s21_math_pow_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
