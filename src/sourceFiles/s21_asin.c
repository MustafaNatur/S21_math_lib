#include "s21_math.h"

long double s21_asin(double x) {
  double ans = 0;
  if (x == 1.0 || x == -1.0) {
    ans = 1.57079633 * x;
  } else {
    ans = s21_atan(x / s21_sqrt(1 - x * x));
  }
  return ans;
}