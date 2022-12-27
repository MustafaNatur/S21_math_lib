#include "s21_math.h"

double cases_pow_zeros[][2] = {{0, 5}, {0, -5}, {0, NAN}, {0, -NAN}, {0, 0}, {0, NEG_INF}, {-1, POS_INF}, {-1, NEG_INF}};
double cases_pow_exp[][2] = {{1, NAN}, {1, POS_INF}, {1, 0}, {1, -5}, {1, 5}, {1, 1.5}, {-1, 3}, {-1, 2}, {-1, 1.5}};
double cases_pow_base[][2] = {{NAN, 0}, {POS_INF, 0}, {5, 0}};
double cases_pow_base_fractional[][2] = {{0.1, POS_INF}, {-0.1, POS_INF}, {0.1, NEG_INF}, {-0.1, NEG_INF}, {5, POS_INF}, {-5, POS_INF}, {5, NEG_INF}, {-5, NEG_INF}};
double cases_pow_INF_exp[][2] = {{POS_INF, 0}, {POS_INF, 5}, {POS_INF, POS_INF}, {POS_INF, NAN}, {NEG_INF, 0}, {NEG_INF, 5}, {NEG_INF, POS_INF}, {NEG_INF, NAN},};
double cases_pow_NAN[][2] = {{NAN, NAN}, {NAN, -NAN}, {-NAN, -NAN}};

