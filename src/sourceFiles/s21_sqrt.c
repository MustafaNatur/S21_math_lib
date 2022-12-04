#include "s21_math.h"

long double s21_sqrt(double x) {
  if (x >= 0) {
    long double left = 0;
    long double right = x;
    if (x < 1 && x > 0) {
      right = 1;
    }
    long double mid = (left + right) / 2;

    while (mid - left > S21_EPS) {
      if (mid * mid > x) {
        right = mid;
      } else {
        left = mid;
      }
      mid = (left + right) / 2;
    }
    return mid;
  }
}