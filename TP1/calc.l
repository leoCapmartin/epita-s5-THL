%option nounput noinput noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>
%}

%%

%{
    printf("Please enter a simple arithmetic expression.\n");
    enum operande
    {
        PLUS,
        MINUS,
        NUM,
        NONE,
    };
    int res = 0;
    enum operande op = NONE;

%}

[0-9]+ {
    int num = atoi(yytext);
    if (op == NONE)
        res = num;
    else if (op == PLUS)
        res += num;
    else if (op == MINUS)
        res -= num;
    else
        return 0;
    op = NUM;
}

"+" {
    if (op == NUM)
        op = PLUS;
    else
        return 0;
}
"-" {
    if (op == NUM)
        op = MINUS;
    else
        return 0;
}

"\n" {
    if (op == NUM)
        printf("%d\n", res);
    else
        return 0;
    res = 0;
    op = NONE;
}

. {
    return 0;
}

%%

int main()
{
    while (yylex());
    return 0;
}
