#include "s21_math.h"


int isint ( double d ) {
    return d == (int64_t)d ;
};

long double s21_pow(double base, double exp1) {
    long double ans = 0; 

  if (base>=0) {
    ans = s21_exp(exp1*s21_log(base));
  } else {
    if (isint(exp1)) {
        base*=-1;
        ans = s21_exp(exp1*s21_log(base));
        if ((int64_t)base%2 != 0) {
          ans*=-1;
        } 
    } else {
      ans = -NAN;
    }
  }
  return ans;
}

