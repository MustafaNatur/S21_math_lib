#include "s21_math.h"

long double s21_pow(double base, double exp) {
    long double answ = 1;
    
    // if (base > 0) {
    //     answ = s21_exp(exp * s21_log(s21_fabs(base)));
    //     return answ;
    // }
    if (exp != 0) {
        answ = s21_exp(exp * s21_log(s21_fabs(base)));
        if (base < 0 && s21_fmod(exp, 2)) { answ = -answ; }
    }
    return answ;
}
