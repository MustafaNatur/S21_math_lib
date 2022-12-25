#include "s21_math.h"

long double s21_cos(double x) {
  long double result = 0;
  int sign = 1;
  double xx = x * x;
  double pw = 1;
  double factorial = 1.0;
  for (int i = 0; i < 25; i += 2) {
    if (i != 0) {
      factorial /= i;
    }
    result += sign * pw * factorial;
    factorial /= (i + 1);
    sign = -sign;
    pw *= xx;
  }
  return result;
}