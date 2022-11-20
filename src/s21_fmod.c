#include "s21_math.h"

long double s21_fmod(double x, double y) {
  while (x > y) {
    x -= y;
  }
  return x;
}