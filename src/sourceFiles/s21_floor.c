#include "s21_math.h"

long double s21_floor(double x) {
  long double floor_res = (long long int)x;
  if (floor_res < 0 && x != floor_res) {
    floor_res -= 1;
  }
  return floor_res;
}