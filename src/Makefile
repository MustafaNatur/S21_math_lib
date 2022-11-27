FLAGS=-Wall -Wextra -Werror
CC=gcc
FUNC_FILES_C=s21_abs.c s21_acos.c s21_asin.c s21_atan.c s21_ceil.c s21_exp.c s21_fabs.c s21_factorial.c s21_floor.c s21_fmod.c s21_log.c s21_sqrt.c
FUNC_FILES_O=s21_abs.o s21_acos.o s21_asin.o s21_atan.o s21_ceil.o s21_exp.o s21_fabs.o s21_factorial.o s21_floor.o s21_fmod.o s21_log.o s21_sqrt.o
CHECKFLAGS=$(shell pkg-config --cflags --libs check)
GCOVFLAGS=-fprofile-arcs -ftest-coverage
LIBNAME=s21_math.a
GLFLAGS=-lgcov --coverage

all: build_object_files build_library copy_lib_to_tests

build_object_files:
	$(CC) $(FLAGS) $(GCOVFLAGS) -c $(FUNC_FILES_C)

build_library:
	ar rcs $(LIBNAME) $(FUNC_FILES_O)

copy_lib_to_tests:
	cp $(LIBNAME) ../tests

clean:
	rm -rf *.o
	rm -rf *.gcno
	rm -rf *.gcov
	rm -rf *.gcda
	rm -rf *.a 
