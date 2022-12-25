#include "s21_math.h"

long double s21_pow(double base, double exp) {
  // фукнция обработки краевых случаев
  // ans  = e^(exp*log(base))
  long double ans = 0; 
  if (base > 0) {
      ans = s21_exp(exp*s21_log(base));
  } else {
    ans = s21_exp(exp*s21_log(s21_abs(base)));
    if (s21_fmod(exp, 2) !=0) {
      ans*=-1;
    }
  }
  return ans;
}
