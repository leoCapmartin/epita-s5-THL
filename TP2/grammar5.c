#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "parsing.h"

/* A LL(1) parser for the grammar:

Z -> S '$'    (1)
S -> P U      (2)
U -> '+' P U  (3)
    | '-' P U (4)
    | EPS     (5)
P -> I V      (6)
V -> '*' I V  (7)
    | EPS     (8)
I -> int      (9)

The simplest context-free grammar there is. */

int Z(char ** stream_pointer);
int S(char ** stream_pointer);
int U(char ** stream_pointer, int num);
int P(char ** stream_pointer);
int V(char ** stream_pointer, int num);
int I(char ** stream_pointer);

int Z(char ** stream_pointer) {
    int num = 0;
    char c = **stream_pointer;
    if ('0' <= c && c <= '9')
    {
        num = S(stream_pointer);
        eat(stream_pointer, '\0');
        printf("Parsing successful.\n");
    }
    else
        wrong_look_ahead(stream_pointer, 'Z');
    return num;
}

int S(char ** stream_pointer) {
    int num = 0;
    char c = **stream_pointer;
    if ('0' <= c && c <= '9')
    {
        num = P(stream_pointer);
        num = U(stream_pointer, num);
    }
    else
    {
        wrong_look_ahead(stream_pointer, 'S');
    }
    return num;
}

int U(char ** stream_pointer, int num)
{
    switch (**stream_pointer) {
        case '+':
            eat(stream_pointer, '+');
            num += P(stream_pointer);
            num = U(stream_pointer, num);
            break;
        case '-':
            eat(stream_pointer, '-');
            num -= P(stream_pointer);
            num = U(stream_pointer, num);
            break;
        case '\0':
            break;
        default:
            wrong_look_ahead(stream_pointer, 'U');
    }

    return num;
}

int P(char ** stream_pointer)
{
    int num = 0;
    char c = **stream_pointer;
    if ('0' <= c && c <= '9')
    {
        num = I(stream_pointer);
        num = V(stream_pointer, num);
    }
    else
    {
        wrong_look_ahead(stream_pointer, 'P');
    }
    return num;
}
int V(char ** stream_pointer, int num)
{
    switch (**stream_pointer) {
        case '*':
            eat(stream_pointer, '*');
            num *= I(stream_pointer);
            num = V(stream_pointer, num);
            break;
        case '+':
            break;
        case '-':
            break;
        case '\0':
            break;
        default:
            wrong_look_ahead(stream_pointer, 'V');
    }

    return num;
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
    int num = Z(input_stream);
    printf("res = %d\n", num);
    return EXIT_SUCCESS;
}
