#include "s21_math.h"

#define OK 1000.0;
int isInt(double d) { return d == (int64_t)d; };

double helper(double base, double exp) {
  double res = OK;
  if (base == 0.0) {
    if (isNAN(exp)) {
      res = S21_NAN;
    } else if (exp == -S21_NAN) {
      res = -S21_NAN;
    } else if (isNEG_INF(exp)) {
      res = POS_INF;
    } else if (exp == 0.0) {
      res = 1.0;
    } else if (exp < 0) {
      res = POS_INF;
    }
  } else if (base == 1.0) {
    res = 1.0;
  } else if (base == -1.0) {
    if (isPOS_INF(exp) || isNEG_INF(exp)) {
      res = 1.0;
    }
  } else if (!isInt(base) && !isPOS_INF(base) && !isNEG_INF(base)) {
    if (isPOS_INF(exp)) {
      res = 0.0;
    } else if (isNEG_INF(exp)) {
      res = POS_INF;
    }
  } else if (isInt(base)) {
    if (isPOS_INF(exp) || isNEG_INF(exp)) {
      res = POS_INF;
    }
  } else if (isPOS_INF(base)) {
    if (exp == 0.0) {
      res = 1.0;
    } else if (exp > 0 && isInt(exp)) {
      res = POS_INF;
    } else if (isPOS_INF(exp)) {
      res = POS_INF;
    } else if (isNAN(exp)) {
      res = S21_NAN;
    }
  } else if (isNEG_INF(base)) {
    if (exp == 0.0) {
      res = 1.0;
    } else if (exp > 0 && isInt(exp)) {
      res = NEG_INF;
    } else if (isPOS_INF(exp)) {
      res = POS_INF;
    } else if (isNAN(exp)) {
      res = S21_NAN;
    }
  }
  return res;
}

long double fast_pow(double base, long long int exp) {
  long double ans = 1.0;
  long long copy = s21_fabs(exp);
  while (copy) {
    ans *= base;
    copy--;
  }
  return (exp < 0) ? 1.0 / ans : ans;
}

long double s21_pow(double base, double exp) {
  long double ans = 1.0;
  if (helper(base, exp) == 1000.0) {
    if (isInt(exp)) {
      ans = fast_pow(base, exp);
    } else {  // exp in not int
      if (base < 0) {
        ans = S21_NAN;
      } else {
        ans = s21_exp(exp * s21_log(base));
      }
    }
  } else {
    ans = helper(base, exp);
  }
  return ans;
}
