#include "s21_math.h"

long double s21_sin(double x) {
  while (s21_fabs(x) - 2 * S21_PI > 0) {
    x += 2 * S21_PI * x / s21_fabs(x) * -1;
  }
  long double result = 0;
  int sign = 1;
  double xx = x * x;
  double pw = x;
  double factorial = 1.0;
  for (int i = 1; i < 200; i += 2) {
    factorial *= i;
    result += sign * pw / factorial;
    factorial *= (i + 1);
    sign = -sign;
    pw *= xx;
  }
  return result;
}
