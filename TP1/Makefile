CC = gcc

all: test word_count calc

test: clean output.c
	gcc -o test output.c
	./test

output.c:
	flex -o output.c input.l

word_count: clean wc.c
	gcc -o wc wc.c
	./wc

wc.c:
	flex -o wc.c word_count.l

calc: clean calc.c
	gcc -o calc calc.c
	./calc

calc.c:
	flex -o calc.c calc.l


clean:
	${RM} *.c test wc calc
