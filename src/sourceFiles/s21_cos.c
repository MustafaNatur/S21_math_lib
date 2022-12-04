#include "s21_math.h"

long double s21_cos(double x) {
  long double cos = 0;
  for (int i = 0; i < 100; i++) {
    cos += (pow((-1), i) * pow(x, 2 * i)) / s21_factorial(2 * i);
  }
  return cos;
}