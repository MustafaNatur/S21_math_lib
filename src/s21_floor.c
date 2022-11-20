#include "s21_math.h"

long double s21_floor(double x) {
  if ((int)x != x) {
    x = (int)x - 1;
  }
  return x;
}