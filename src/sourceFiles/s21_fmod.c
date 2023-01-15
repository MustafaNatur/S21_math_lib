#include "s21_math.h"

long double s21_fmod(double x, double y) {
  int signx = 0;
  if (x < 0) {
    signx = 1;
  }
  if (y == 0) {
    x = S21_NAN;
  } else if (isPOS_INF(x) || isNEG_INF(x)) {
    x = S21_NAN;
  } else if (isNAN(y)) {
    x = S21_NAN;
  } else {
    x = s21_fabs(x);
    y = s21_fabs(y);
    while (x >= y) {
      x -= y;
    }
  }
  if (signx == 1) {
    x = -x;
  }
  return x;
}