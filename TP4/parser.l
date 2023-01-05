%option nounput noinput noyywrap

%{
    #include "grammar.h"
%}

%%
[0-9]+ {return TOK_INTEGER;}
"+" {return TOK_PLUS;}
"-" {return TOK_MINUS;}
"*" {return TOK_MULT;}
"/" {return TOK_DIV;}
"\n" {return TOK_EOL;}
%%
