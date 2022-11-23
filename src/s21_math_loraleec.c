#include <math.h>
#include <stdio.h>

#include "s21_math.h"

int main() {
    printf("%d\n", s21_pow(2, 3) == pow(2, 3));
    printf("%d\n", s21_pow(2.2, 10) == pow(2.2, 10));
    printf("%d\n", s21_pow(6.5, 2.43) == pow(6.5, 2.43));
    printf("%d\n", s21_pow(-6.5, 2.43) == pow(-6.5, 2.43));
    printf("%d\n", s21_pow(-6.5, -2.43) == pow(-6.5, -2.43));  
    return 0;
}