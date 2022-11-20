FLAG = -Wall -Wextra -Werror

rebuild: 
	make clean
	make s21_math

s21_math: s21_math_loraleec.c s21_abs.c s21_fabs.c s21_ceil.c s21_factorial.c s21_floor.c s21_fmod.c s21_sqrt.c
	gcc s21_math_loraleec.c s21_abs.c s21_fabs.c s21_ceil.c s21_factorial.c s21_floor.c s21_fmod.c s21_sqrt.c -o s21_math

clean:
	rm -f s21_math

