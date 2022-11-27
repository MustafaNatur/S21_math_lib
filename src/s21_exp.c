#include "s21_math.h"

/*  F(x) = 1 + x + x^2/2 + x^3/6 + ...  */

long double s21_exp(double x) {
  long double i = 1;
  long double step = 1;
  long double T_series = 1;
  int flag_max = 0;

  while (s21_fabs(step) > S21_EPS && flag_max == 0) {
    step *= x / i;
    i++;
    T_series += step;
    if (T_series > S21_MAX) {
      flag_max = 1;
      T_series /= 0.0;
    }
  }
  return T_series;
}