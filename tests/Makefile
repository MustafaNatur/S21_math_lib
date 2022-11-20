FLAGS=-Wall -Wextra -Werror
CC=gcc
FUNC_FILES_C=s21_abs.c s21_ceil.c s21_fabs.c s21_floor.c s21_fmod.c
FUNC_FILES_O=s21_abs.o s21_ceil.o s21_fabs.o s21_floor.o s21_fmod.o
CHECKFLAGS=$(shell pkg-config --cflags --libs check)

all: build_all_tests

build_all_tests:
	$(CC) $(FLAGS) $(CHECKFLAGS) s21_test_abs.c
	
clean:
	rm -rf *.o