#include "s21_math.h"


long double s21_asin(double x) {
    return s21_atan(1/s21_sqrt(1 - s21_pow(x, 2)));
}