#include "math.h"
#include "s21_math.h"
#include <check.h>
#include <stdlib.h>

START_TEST(test_s21_math_pow_big) {
  int exp1 = -2989839;
  int testValue1 = 0.0004;
  int testValue2 = 100;
  int testValue3 = 0;
  int testValue4 = 55;
  int testValue5 = -77;


  ck_assert_ldouble_ne_tol(s21_pow(exp1, testValue1), pow(exp1, testValue1), 0);
  ck_assert_ldouble_ne_tol(s21_pow(exp1, testValue2), pow(exp1, testValue2), 0);
  ck_assert_ldouble_ne_tol(s21_pow(exp1, testValue3), pow(exp1, testValue3), 0);
  ck_assert_ldouble_ne_tol(s21_pow(exp1, testValue4), pow(exp1, testValue4), 0);
  ck_assert_ldouble_ne_tol(s21_pow(exp1, testValue5), pow(exp1, testValue5), 0);


}
END_TEST

START_TEST(test_s21_math_pow_small) {
  int exp2 = 0.0083928293832;
  int testValue1 = 0.0004;
  int testValue2 = 293;
  int testValue3 = 0;
  int testValue4 = 66;
  int testValue5 = -99;

  ck_assert_ldouble_ne_tol(s21_pow(exp2, testValue1), pow(exp2, testValue1), 0);
  ck_assert_ldouble_ne_tol(s21_pow(exp2, testValue2), pow(exp2, testValue2), 0);
  ck_assert_ldouble_ne_tol(s21_pow(exp2, testValue3), pow(exp2, testValue3), 0);
  ck_assert_ldouble_ne_tol(s21_pow(exp2, testValue4), pow(exp2, testValue4), 0);
  ck_assert_ldouble_ne_tol(s21_pow(exp2, testValue5), pow(exp2, testValue5), 0);

}
END_TEST

Suite *s21_math_pow_suite() {
  Suite *s;
  TCase *tc_pow_big, *tc_pow_small;

  s = suite_create("s21_pow");

  tc_pow_big = tcase_create("s21_pow_big");
  tcase_add_test(tc_pow_big, test_s21_math_pow_big);
  suite_add_tcase(s, tc_pow_big);

  tc_pow_small = tcase_create("s21_pow_small");
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
