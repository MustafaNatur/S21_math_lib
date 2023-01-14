#include "s21_math.h"

#define EPS 500
long double s21_atan(double x) {
  long double result = 0;
  if (x == 0.0) {
    result = 0.0;
  } else if (x == 1.0 || x == -1.0) {
    result = (x == 1.0) ? S21_PI / 4.0 : S21_PI / 4.0 * (-1);
  } else {
    int k = s21_fabs(x) > 1 ? -1 : 1;
    for (int i = 0; i < EPS; i++) {
      result +=
          (s21_pow(-1, i) * s21_pow(x, (1 * k + 2 * k * i))) / (1 + 2 * i);
    }
    result = (k == -1.0) ? (S21_PI * s21_fabs(x) / (2 * x) - result) : result;
  }

  return result;
}