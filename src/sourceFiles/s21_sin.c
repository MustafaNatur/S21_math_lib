#include "s21_math.h"


long double s21_sin(double x) {
  long double sin = 0;
  for (int i = 0; i < 500; i++) {
    sin += (pow((-1), i) * pow(x, (1 + 2 * i))) / s21_factorial(1 + 2 * i);
  }
  return sin;
}