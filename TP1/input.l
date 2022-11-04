%option nounput noinput noyywrap

%{
    #include <stdio.h>
%}

BLANK [ \t]

%%

%{
    printf("Looking for a pattern...\n");
%}

"42" {printf("quarante-deux\n");}
"2" {printf("deux\n");}
"4" {printf("quatre\n");}
[0-9]+ {printf("here is your number : %s\n", yytext);}

"+" {printf("PLUS\n");}
"-" {printf("MINUS\n");}

"q" return 0;

. {printf("");}

%%

int main()
{
    while (yylex());
    return 0;
}
