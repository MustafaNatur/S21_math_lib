#include "s21_math.h"

long double s21_acos(double x) {
  long double result = 0;
  if (x > 0 && x < 1) {
    result = s21_atan(s21_sqrt(1 - s21_pow(x, 2)) / x);
  } else if (x > -1 && x < 0) {
    result = S21_PI + s21_atan(s21_sqrt(1 - s21_pow(x, 2)) / x);
  } else {
    if (x == 1.0) {
      result = 0;
    } else if (x == -1.0) {
      result = S21_PI;
    } else {
      result = S21_PI / 2.0;
    }
  }
  return result;
}