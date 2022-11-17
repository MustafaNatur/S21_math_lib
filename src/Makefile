FLAG = -Wall -Wextra -Werror

s21_math: s21_math.c 
	gcc $(FLAG) s21_math.c -o s21_math
clean:
	rm -f *.o 

rebuild: 
	make clean
	make s21_math
	make clean
