#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "parsing.h"

/* A LL(1) parser for the grammar:

Z -> S '$'    (1)
S -> I U      (2)
U -> '+' I U  (3)
    | EPS     (4)
I -> int      (5)

The simplest context-free grammar there is. */

void Z(char ** stream_pointer);
void S(char ** stream_pointer);
void U(char ** stream_pointer);
int I(char ** stream_pointer);

void Z(char ** stream_pointer) {
    char c = **stream_pointer;
    if ('0' <= c && c <= '9')
    {
        S(stream_pointer);
        eat(stream_pointer, '\0');
        printf("Parsing successful.\n");
    }
    else
        wrong_look_ahead(stream_pointer, 'Z');
}

void S(char ** stream_pointer) {
    char c = **stream_pointer;
    if ('0' <= c && c <= '9')
    {
        int num = I(stream_pointer);
        printf("%d\n", num);
        U(stream_pointer);
    }
    else
    {
        wrong_look_ahead(stream_pointer, 'S');
    }
}

void U(char ** stream_pointer)
{
    switch (**stream_pointer) {
        case '+':
            eat(stream_pointer, '+');
            int num = I(stream_pointer);
            printf("%d\n", num);
            U(stream_pointer);
            break;
        case '\0':
            break;
        default:
            wrong_look_ahead(stream_pointer, 'U');
    }
}

int I(char ** stream_pointer)
{
    char c = **stream_pointer;
    int res = 0;
    while(isdigit(**stream_pointer))
    {
        eat(stream_pointer, c);
        res *= 10;
        res += c - '0';
        c = **stream_pointer;
    }
    return res;
}

int main(int argc, char * argv[]) {
    if (argc != 2) {
        printf("This program takes exactly one argument.\n");
        return  EXIT_FAILURE;
    }
    char ** input_stream = &argv[1];
    Z(input_stream);
    return EXIT_SUCCESS;
}
