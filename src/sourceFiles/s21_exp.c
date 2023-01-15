#include "s21_math.h"

long double s21_exp(double x) {
  long double i = 1;
  long double step = 1;
  long double T_series = 1;
  int flag_max = 0;

  if (isNAN(x)) {
    T_series = S21_NAN;
  } else if (isPOS_INF(x)) {
    T_series = POS_INF;
  } else if (isNEG_INF(x) || x < -14.5) {
    T_series = 0.0;
  } else {
    while (s21_fabs(step) > S21_EPS && flag_max == 0) {
      step *= x / i;
      i++;
      T_series += step;
      if (T_series > S21_MAX) {
        flag_max = 1;
        T_series = POS_INF;
      }
    }
  }

  return T_series;
}
