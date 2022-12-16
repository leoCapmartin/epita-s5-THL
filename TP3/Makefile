CC=gcc

all:
	bison --graph exo3-1.y -o output.c
	dot -Tpng output.gv > output.png

clean:
	$(RM) *.c *.gv *.png
