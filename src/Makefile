#!/bin/bash
FLAGS=-Wall -Wextra -Werror
CC=gcc
FUNC_FILES_C=sourceFiles/*.c
FUNC_FILES_O=*.o
CHECKFLAGS=$(shell pkg-config --cflags --libs check)
GCOVFLAGS=-fprofile-arcs -ftest-coverage
LIBNAME=s21_math.a
GLFLAGS=--coverage
GCOVFLAGS=-fprofile-arcs -ftest-coverage
filesArray=("s21_test_abs" "21_test_acos" "s21_test_asin" "s21_test_atan" "s21_test_ceil" "s21_test_cos" "s21_test_exp" "s21_test_fabs" "s21_test_floor" "s21_test_fmod" "s21_test_log" "s21_test_pow" "s21_test_sin" "s21_test_sqrt" "s21_test_tan")
sourceFilesArray=$(ls sourceFiles)

all: s21_math.a

peer: gcov_report

build_object_files:
	$(CC) $(FLAGS) $(GCOVFLAGS) $(GLFLAGS) -c $(FUNC_FILES_C)

build_library:
	ar rcs $(LIBNAME) $(FUNC_FILES_O)

s21_math.a:
	$(CC) $(FLAGS) -c $(FUNC_FILES_C)
	cp testFiles/s21_math.h s21_math.h
	make build_library
	rm -rf *.o

test: s21_math.a
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_test_abs.c -L. s21_math.a  -o s21_test_abs
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_test_acos.c -L. s21_math.a  -o s21_test_acos
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_test_asin.c -L. s21_math.a  -o s21_test_asin
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_test_atan.c -L. s21_math.a  -o s21_test_atan
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_test_ceil.c -L. s21_math.a  -o s21_test_ceil
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_test_cos.c -L. s21_math.a  -o s21_test_cos
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_test_exp.c -L. s21_math.a  -o s21_test_exp
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_test_fabs.c -L. s21_math.a  -o s21_test_fabs
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_test_floor.c -L. s21_math.a  -o s21_test_floor
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_test_fmod.c -L. s21_math.a  -o s21_test_fmod
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_test_log.c -L. s21_math.a  -o s21_test_log
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_test_pow.c -L. s21_math.a  -o s21_test_pow
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_test_sin.c -L. s21_math.a  -o s21_test_sin
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_test_sqrt.c -L. s21_math.a  -o s21_test_sqrt
	$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_test_tan.c -L. s21_math.a  -o s21_test_tan
	make start_tests
	
start_tests:
	./s21_test_acos
	./s21_test_asin
	./s21_test_cos
	./s21_test_log
	./s21_test_exp
	./s21_test_abs
	./s21_test_pow
	./s21_test_ceil
	./s21_test_atan
	./s21_test_fabs
	./s21_test_floor
	./s21_test_fmod
	./s21_test_sin
	./s21_test_sqrt
	./s21_test_tan

gcov_report: clean build_object_files build_library test
	lcov -o tests.info -c -d .  
	genhtml -o report tests.info
	open report/index.html
	make clean

gen_html: start_tests gcov_report
	
clean:
	rm -rf *.o
	rm -rf *.gcno
	rm -rf *.gcov
	rm -rf *.gcda
	rm -rf *.a
	rm -rf *.info
	rm -rf s21*

rebuild:
	make clean
	make