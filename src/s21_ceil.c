#include "s21_math.h"

long double s21_ceil(double x) {
  long double ceil_res = (long long int)x;
  if (ceil_res > 0 && x != ceil_res) {
    ceil_res += 1;
  }
  return ceil_res;
}