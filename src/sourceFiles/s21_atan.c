#include <stdio.h>
#include <math.h>
#include <string.h>

#define EPS 5000
long double s21_atan(double x);

int main()
{
    int testPass = 0;
    int testAll = 0;
    for (double i = -100.0; i < 100; i+=0.1) {
        char number1[24];
        char number2[24];
        sprintf(number1, "%.6Lf", s21_atan(i));
        sprintf(number2, "%.6f", atan(i));
        if (strcmp (number1, number2) != 0) {
            printf("%f: %s %s\n",i ,number1, number2);
        }
        testPass += strcmp (number1, number2) == 0 ? 1:0;
        testAll++;
    }
    printf("%d/%d",testPass, testAll );
    
    return 0;
}


long double s21_atan(double x) {
    long double result = 0;
    
    if (x != 1 && x != -1) {
        int k = fabs(x) > 1 ? -1:1;
        for (int i = 0; i < EPS; i++) {
            result+= (pow(-1, i)*pow(x,(1*k+2*k*i)))/(1+2*i);
        }
        result = (k == -1) ? (M_PI*fabs(x)/(2*x) - result):result;
    } else {
        result =  (x == 1) ? M_PI/4.0:M_PI/4.0 * (-1);
    }
    
    return result;
}