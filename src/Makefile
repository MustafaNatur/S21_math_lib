FLAGS=-Wall -Wextra -Werror
CC=gcc
FUNC_FILES_C=s21_abs.c s21_ceil.c s21_fabs.c s21_floor.c s21_fmod.c
FUNC_FILES_O=s21_abs.o s21_ceil.o s21_fabs.o s21_floor.o s21_fmod.o
CHECKFLAGS=$(shell pkg-config --cflags --libs check)
GCOVFLAGS=-fprofile-arcs -ftest-coverage
LIBNAME=s21_math.a
GLFLAGS=-lgcov --coverage

all: build_object_files build_library clean copy_lib_to_tests

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
