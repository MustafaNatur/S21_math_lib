#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"
#include "test_cases.h"

#define sizeArr(x) (sizeof(x) / sizeof((x)[0]))

START_TEST(test_s21_math_pow_usual) {
  int base = -8;
  double exp1 = 1.0 / 4.0;
  double exp2 = 3.0;
  ck_assert_ldouble_eq_tol(s21_pow(8, 3), pow(8, 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-8, 3), pow(-8, 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(8, -3), pow(8, -3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0, 0), pow(0, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(1, -3), pow(1, -3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0, 5), pow(0, 5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(8.234, -3), pow(8.234, -3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(25, 0.5), pow(25, 0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(5, 1.4), pow(5, 1.4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(5, -1.4), pow(5, -1.4), 1e-6);
  ck_assert_double_nan(s21_pow(-4, 1.4));
  for (double i = 0.0; i < 10.0; i += 0.1) {
    for (double j = 0.0; j < 10.0; j += 0.1) {
      ck_assert_ldouble_eq_tol(s21_pow(i, j), pow(i, j), 1e-4);
    }
  }
}
END_TEST

START_TEST(test_s21_math_pow_big) {
  int base = 2989839;
  double exp1 = 0.0004;
  int exp3 = 0;
  int exp4 = 55;
  int exp5 = -2;

  ck_assert_ldouble_eq_tol(s21_pow(base, exp1), pow(base, exp1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(base, exp3), pow(base, exp3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(base, exp5), pow(base, exp5), 1e-6);
}
END_TEST

START_TEST(test_s21_math_pow_small) {
  double base = 0.0083928293832;
  double exp1 = 0.0004;
  int exp2 = 293;
  int exp3 = 0;
  int exp4 = 66;
  int exp5 = -99;

  ck_assert_ldouble_eq_tol(s21_pow(base, exp1), pow(base, exp1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(base, exp2), pow(base, exp2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(base, exp3), pow(base, exp3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(base, exp4), pow(base, exp4), 1e-6);
}
END_TEST

START_TEST(test_s21_math_pow_cases_should_return_nan) {
  for (int i = 0; i < sizeArr(cases_pow_return_nan); i++) {
    double base = cases_pow_return_nan[i][0];
    double exp = cases_pow_return_nan[i][1];
    ck_assert_double_nan(s21_pow(base, exp));
  }
}
END_TEST

START_TEST(test_s21_math_pow_cases_should_return_inf) {
  for (int i = 0; i < sizeArr(cases_pow_return_inf); i++) {
    double base = cases_pow_return_inf[i][0];
    double exp = cases_pow_return_inf[i][1];
    ck_assert_ldouble_infinite(s21_pow(base, exp));
  }
}
END_TEST

START_TEST(test_s21_math_pow_cases_should_return_one) {
  for (int i = 0; i < sizeArr(cases_pow_return_one); i++) {
    double base = cases_pow_return_one[i][0];
    double exp = cases_pow_return_one[i][1];
    ck_assert_double_eq(s21_pow(base, exp), 1.0);
  }
}
END_TEST

Suite *s21_math_pow_suite() {
  Suite *s;
  TCase *tc_pow_big, *tc_pow_small, *tc_pow_usual, *tc_pow_unusual;

  s = suite_create("pow");

  tc_pow_usual = tcase_create("pow_usual");
  tcase_add_test(tc_pow_usual, test_s21_math_pow_usual);
  suite_add_tcase(s, tc_pow_usual);

  tc_pow_big = tcase_create("pow_big");
  tcase_add_test(tc_pow_big, test_s21_math_pow_big);
  suite_add_tcase(s, tc_pow_big);

  tc_pow_small = tcase_create("pow_small");
  tcase_add_test(tc_pow_small, test_s21_math_pow_small);
  suite_add_tcase(s, tc_pow_small);

  tc_pow_unusual = tcase_create("pow_unusual");
  tcase_add_test(tc_pow_unusual, test_s21_math_pow_cases_should_return_nan);
  tcase_add_test(tc_pow_unusual, test_s21_math_pow_cases_should_return_inf);
  tcase_add_test(tc_pow_unusual, test_s21_math_pow_cases_should_return_one);
  suite_add_tcase(s, tc_pow_unusual);

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
