#include "s21_math.h"

/*   Yn+1 = Yn + 2 * (X - exp(Yn)) / (X + exp(Yn))   */

long double s21_log(double x) {
  int exp_pow = 0;
  long double step = 0;
  long double res = 0;
  long double result = res + exp_pow;
  if (isNAN(x)) {
    result = S21_NAN;
  } else if (isPOS_INF(x)) {
    result = POS_INF;
  } else if (isNEG_INF(x)) {
    result = -S21_NAN;
  } else {
    if (x > 0) {
      while (x >= S21_EXP) {
        x /= S21_EXP;
        exp_pow++;
      }
      for (int i = 0; i < 150; i++) {
        step = res;
        res = step + 2 * (x - s21_exp(step)) / (x + s21_exp(step));
      }
      result = res + exp_pow;
    } else if (x == 0) {
      result = NEG_INF;
    } else if (x < 0) {
      result = S21_NAN;
    }
  }
  return result;
}
