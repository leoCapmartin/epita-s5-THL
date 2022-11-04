%option nounput noinput noyywrap

%{
    #include <stdio.h>
%}

%%

%{
    printf("Please enter a sentence.\n");
    int c = 0;
%}

[a-zA-Z]+ {c++;}

"\n" {printf("%d\n", c); c = 0;}

. {printf("");}

%%

int main()
{
    while (yylex());
    return 0;
}
