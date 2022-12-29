#include "s21_math.h"

#define OK 1000.0;
int isint ( double d ) {
    return d == (int64_t)d ;
};

double helper(double base, double exp) {
  double res = OK;
  if (base == 0.0) {
    if (exp == S21_NAN) {
      res = S21_NAN;
    } else if (exp == -S21_NAN) {
      res = -S21_NAN;
    } else if (exp == NEG_INF) {
      res = POS_INF;
    } else if (exp == 0.0) {
      res = 1.0;
    } else {
      res = 0.0;
    }
  } else if (base == -1.0) {
    if (exp == POS_INF || exp == NEG_INF) {
      res = 1.0;
    }
  }
  // } else if ()  {

  // }
  return res;
}

long double s21_pow(double base, double exp1) {
  long double ans = 0; 
  if (helper(base, exp1) != 1000.0) {
    ans = helper(base, exp1);
  } else {
    if (base>=0) {
      ans = s21_exp(exp1*s21_log(base));
    } else {
      if (isint(exp1)) {
          base*=-1;
          ans = s21_exp(exp1*s21_log(base));
          if (((int64_t)exp1)%2 != 0.0) {
            ans*=-1;
          } 
      } else {
        ans = -S21_NAN;
      }
    }
  }
  return ans;
}

