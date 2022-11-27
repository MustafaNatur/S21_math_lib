FLAGS=-Wall -Wextra -Werror
CC=gcc
FUNC_FILES_C=sourceFiles/*.c
FUNC_FILES_O=*.o
CHECKFLAGS=$(shell pkg-config --cflags --libs check)
GCOVFLAGS=-fprofile-arcs -ftest-coverage
LIBNAME=s21_math.a
GLFLAGS=-lgcov --coverage
GCOVFLAGS=-fprofile-arcs -ftest-coverage


all: build_object_files build_library build_all_tests clean

build_object_files:
	$(CC) $(FLAGS) $(GCOVFLAGS) $(GLFLAGS) -c $(FUNC_FILES_C)

build_library:
	ar rcs $(LIBNAME) $(FUNC_FILES_O)

build_all_tests:
	$(CC)  $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) testFiles/s21_test_abs.c -L. s21_math.a  -o s21_test_abs
	./s21_test_abs
	gcov s21_test_abs.c
	lcov -o tests.info -c -d .  
	genhtml -o report tests.info

clean:
	rm -rf *.o
	rm -rf *.gcno
	rm -rf *.gcov
	rm -rf *.gcda
	rm -rf *.a

