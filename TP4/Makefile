CC=gcc

all:
	bison --graph grammar.y -o grammar.c
	flex -o parser.c parser.l
	gcc -o calc parser.c grammar.c
clean:
	$(RM) *.c *.gv *.png *.h
