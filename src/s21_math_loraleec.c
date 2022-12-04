#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

int main() {
  // printf("%Lf %lf\n", s21_pow(2.0, 3.0), pow(2.0, 3.0));
  // printf("%Lf %lf\n", s21_pow(2.2, 10.0), pow(2.2, 10.0));
  // printf("%Lf %lf\n", s21_pow(6.5, -2.43), pow(6.5, -2.43));
  // printf("%Lf %lf\n", s21_pow(-6.5, 2.43), pow(-6.5, 2.43));
  // printf("%Lf %lf\n", s21_pow(-6.5, -2.43), pow(-6.5, -2.43));

  printf("%Lf %lf\n", s21_sin(2), sin(2));
  printf("%Lf %lf\n", s21_sin(-2), sin(-2));

  return 0;
}