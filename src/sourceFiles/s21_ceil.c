#include "s21_math.h"

long double s21_ceil(double x) {
  long double ceil_res = (long long int)x;
  if (isNAN(x)) {
    ceil_res = S21_NAN;
  } else if (isPOS_INF(x)) {
    ceil_res = POS_INF;
  } else if (isNEG_INF(x)) {
    ceil_res = NEG_INF;
  } else if (x > 0 && x != ceil_res) {
    ceil_res += 1;
  }

  return ceil_res;
}