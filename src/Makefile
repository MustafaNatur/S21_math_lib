FLAGS=-Wall -Wextra -Werror
CC=gcc
FUNC_FILES=s21_abs.c s21_acos.c s21_asin.c s21_atan.c s21_ceil.c s21_cos.c s21_exp.c s21_fabs.c s21_floor.c s21_fmod.c s21_log.c s21_pow.c s21_sin.c s21_sqrt.c s21_tan.c
all: build_object_file build_library

build_object_files:
	$(CC) -c $(FUNC_FILES) -o s21_math.o

build_library: s21_math.o
	ar rcs s21_math.a s21_math.o

build_tests:

build_test_abs_int:
