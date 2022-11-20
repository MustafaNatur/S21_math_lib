#include <stdio.h>

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

long double s21_ceil(double x) {
  if ((int)x != x) {
    x = (int)x + 1;
  }
  return x;
}

long double s21_floor(double x) {
  if ((int)x != x) {
    x = (int)x - 1;
  }
  return x;
}

long double s21_fmod(double x, double y) {
  while (x > y) {
    x -= y;
  }
  return x;
}

int s21_abs(int x) { return (int)s21_fabs(x); }

long double s21_fabs(double x) {
  if (x < 0) {
    x *= -1;
  }
  return x;
}