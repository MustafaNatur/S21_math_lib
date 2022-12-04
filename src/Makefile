FLAGS=-Wall -Wextra -Werror
CC=gcc
FUNC_FILES_C=sourceFiles/*.c
FUNC_FILES_O=*.o
CHECKFLAGS=$(shell pkg-config --cflags --libs check)
GCOVFLAGS=-fprofile-arcs -ftest-coverage
LIBNAME=s21_math.a
GLFLAGS=-lgcov --coverage
GCOVFLAGS=-fprofile-arcs -ftest-coverage


all: build_object_files build_library build_all_tests gen_html clean

build_object_files:
	$(CC) $(FLAGS) $(GCOVFLAGS) $(GLFLAGS) -c $(FUNC_FILES_C)

build_library:
	ar rcs $(LIBNAME) $(FUNC_FILES_O)

build_all_tests:
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_test_abs.c -L. s21_math.a  -o s21_test_abs
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_test_ceil.c -L. s21_math.a  -o s21_test_ceil
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_test_exp.c -L. s21_math.a  -o s21_test_exp
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_test_fabs.c -L. s21_math.a  -o s21_test_fabs
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_test_floor.c -L. s21_math.a  -o s21_test_floor
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_test_log.c -L. s21_math.a  -o s21_test_log
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_test_sqrt.c -L. s21_math.a  -o s21_test_sqrt
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_test_fmod.c -L. s21_math.a  -o s21_test_fmod





gen_html:
	./s21_test_abs
	./s21_test_ceil
	./s21_test_exp
	./s21_test_fabs
	./s21_test_floor
	./s21_test_log
	./s21_test_sqrt
	./s21_test_fmod
	lcov -o tests.info -c -d .  
	genhtml -o report tests.info


clean:
	rm -rf *.o
	rm -rf *.gcno
	rm -rf *.gcov
	rm -rf *.gcda
	rm -rf *.a
	rm -rf *.info
	rm -rf s21*

