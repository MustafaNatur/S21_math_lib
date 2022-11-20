#include <math.h>
#include <stdio.h>

#include "s21_math.h"

int main() {
  printf("%Lf\n%lf", s21_log(1e200), log(1e200));
  return 0;
}