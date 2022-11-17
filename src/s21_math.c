#include "s21_math.h"
#include <stdlib.h>
#include <math.h>

int main() {
    int num1 = -5;
    int num2 = 4;

    double f_num1 = 4.2;
    double f_num2 = -6.4;

    printf("%d %d\n", s21_abs(num1) == abs(num1), s21_abs(num2) == abs(num2));
    printf("%d %d\n", s21_fabs(f_num1) == fabs(f_num1), s21_fabs(f_num2) == fabs(f_num2));
    

    return 0;
}