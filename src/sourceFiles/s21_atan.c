#include "s21_math.h"

#define EPS 5000
long double s21_atan(double x) {
    long double result = 0;
    
    if (x != 1 && x != -1) {
        int k = s21_fabs(x) > 1 ? -1:1;
        for (int i = 0; i < EPS; i++) {
            result+= (pow(-1, i)*pow(x,(1*k+2*k*i)))/(1+2*i);
        }
        result = (k == -1) ? (S21_PI*s21_fabs(x)/(2*x) - result):result;
    } else {
        result =  (x == 1) ? S21_PI/4.0:S21_PI/4.0 * (-1);
    }
    
    return result;
    
}