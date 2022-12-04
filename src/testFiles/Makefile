FLAGS=-Wall -Wextra -Werror
CC=gcc
FUNC_FILES_C=s21_abs.c s21_ceil.c s21_fabs.c s21_floor.c s21_fmod.c
FUNC_FILES_O=s21_abs.o s21_ceil.o s21_fabs.o s21_floor.o s21_fmod.o
GCOVFLAGS=-fprofile-arcs -ftest-coverage
CHECKFLAGS=$(shell pkg-config --cflags --libs check)
GLFLAGS=-lgcov --coverage

all: build_abs_tests build_fabs_tests build_sqrt_tests build_ceil_tests build_floor_tests build_exp_tests build_log_tests

build_abs_tests:
	$(CC) $(FLAGS) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) s21_test_abs.c s21_math.a -L. -o s21_test_abs
	./s21_test_abs
	gcov s21_test_abs.c

build_fabs_tests:
	$(CC) $(FLAGS) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) s21_test_fabs.c s21_math.a -L. -o s21_test_fabs
	./s21_test_fabs
	gcov s21_test_fabs.c

build_sqrt_tests:
	$(CC) $(FLAGS) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) s21_test_sqrt.c s21_math.a -L. -o s21_test_sqrt
	./s21_test_sqrt
	gcov s21_test_sqrt.c

build_ceil_tests:
	$(CC) $(FLAGS) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) s21_test_ceil.c s21_math.a -L. -o s21_test_ceil
	./s21_test_ceil
	gcov s21_test_ceil.c

build_floor_tests:
	$(CC) $(FLAGS) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) s21_test_floor.c s21_math.a -L. -o s21_test_floor
	./s21_test_floor
	gcov s21_test_floor.c

build_exp_tests:
	$(CC) $(FLAGS) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) s21_test_exp.c s21_math.a -L. -o s21_test_exp
	./s21_test_exp
	gcov s21_test_exp.c

build_log_tests:
	$(CC) $(FLAGS) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) s21_test_log.c s21_math.a -L. -o s21_test_log
	./s21_test_log
	gcov s21_test_log.c

clean:
	rm -rf *.o
	rm -rf *.gcno
	rm -rf *.gcov
	rm -rf *.gcda
	rm -rf s21_test_abs
	rm -rf s21_test_fabs
	rm -rf s21_test_sqrt
	rm -rf s21_test_ceil
	rm -rf s21_test_floor
	rm -rf s21_test_exp
