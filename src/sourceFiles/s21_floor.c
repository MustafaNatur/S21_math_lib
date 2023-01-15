#include "s21_math.h"

long double s21_floor(double x) {
  long double floor_res = (long long int)x;
  if (isNAN(x)) {
    floor_res = S21_NAN;
  } else if (isPOS_INF(x)) {
    floor_res = POS_INF;
  } else if (isNEG_INF(x)) {
    floor_res = NEG_INF;
  } else if (x < 0 && x != floor_res) {
    floor_res -= 1;
  }
  return floor_res;
}