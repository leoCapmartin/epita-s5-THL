#include <err.h>
#include <stdio.h>
#include <stdlib.h>

#include "parsing.h"

/* A LL(1) parser for the grammar:

Z -> S '$'
S -> '(' S ')'
    | '{' S '}'
    | 'n'

The simplest context-free grammar there is. */

void Z(char ** stream_pointer);
void S(char ** stream_pointer);


void Z(char ** stream_pointer) {
    if ((**stream_pointer == '(') || (**stream_pointer == 'n')
        || (**stream_pointer == '{')) {
        S(stream_pointer);
        eat(stream_pointer, '\0');
        printf("Parsing successful.\n");
    }
    else
        wrong_look_ahead(stream_pointer, 'Z');
}

void S(char ** stream_pointer) {
    switch (**stream_pointer) {
        case '(':
            eat(stream_pointer, '(');
            S(stream_pointer);
            eat(stream_pointer, ')');
            break;
        case '{':
            eat(stream_pointer, '{');
            S(stream_pointer);
            eat(stream_pointer, '}');
            break;
        case 'n':
            eat(stream_pointer, 'n');
            break;
        default:
            wrong_look_ahead(stream_pointer, 'S');
    }
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
