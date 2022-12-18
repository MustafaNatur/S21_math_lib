#include "s21_math.h"

long double s21_fmod(double x, double y) {
  if (y > 0) {
    while (x >= y) {
      x -= y;
    }
  } else if (y < 0) {
    x = 0;
  } else if (y == 0) {
    x = NAN;
  }
  return x;
}