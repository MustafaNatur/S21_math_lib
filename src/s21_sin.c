#include "s21_math.h"

long double s21_sin(double x) {
  long double sin = 0;
  for (int i = 0; i < 100; i++) {
    sin += (s21_pow((-1), i) * s21_pow(x, (1 + 2 * i))) / FactTree(1 + 2 * i);
  }
  return sin;
}