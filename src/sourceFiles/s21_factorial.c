#include "s21_math.h"

long double s21_factorial(int x) {
  long double res = 0;
  if (x < 0) {
    res = 0;
  } else if (x == 0) {
    res = 1;
  } else {
    res = x * s21_factorial(x - 1);
  }
  return res;
}