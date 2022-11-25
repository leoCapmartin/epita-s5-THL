#include <err.h>
#include <stdio.h>
#include <stdlib.h>


void eat(char ** stream_pointer, char token) {
    if (**stream_pointer == token)
        *stream_pointer += sizeof(char);
    else {
        fprintf(stderr, "Read token '%c', expected token '%c' instead.\n",
            **stream_pointer, token);
        exit(EXIT_FAILURE);  
    }
}

void wrong_look_ahead(char ** stream_pointer, char symbol) {
    fprintf(stderr,
        "No rule matched to non-terminal '%c' can generate look-ahead '%c'.\n",
        symbol, **stream_pointer);
    exit(EXIT_FAILURE);  
}
