FLAGS=-Wall -Wextra -Werror
CC=gcc
FUNC_FILES_C=s21_abs.c s21_ceil.c s21_fabs.c s21_floor.c s21_fmod.c
FUNC_FILES_O=s21_abs.o s21_ceil.o s21_fabs.o s21_floor.o s21_fmod.o

all: build_object_files build_library clean

build_object_files:
	$(CC) $(FLAGS) -c $(FUNC_FILES_C)

build_library:
	ar rcs s21_math.a $(FUNC_FILES_O)

build_tests:

build_test_abs_int:

clean:
	rm -rf *.o