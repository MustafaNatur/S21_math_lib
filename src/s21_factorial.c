#include "s21_math.h"

long double s21_factorial(int x) {
  long double res = 1;
  if (x < 0) {
    res = 0;
  } else {
    for (int i = 1; i < x + 1; i++) {
      res *= i;
    }
  }
  return res;
}

long double ProdTree(int l, int r) {
  if (l > r) return 1;
  if (l == r) return l;
  if (r - l == 1) return (long double)l * r;
  int m = (l + r) / 2;
  return ProdTree(l, m) * ProdTree(m + 1, r);
}

long double FactTree(int n) {
  if (n < 0) return 0;
  if (n == 0) return 1;
  if (n == 1 || n == 2) return n;
  return ProdTree(2, n);
}