%define api.token.prefix {TOK_}
%defines
%define api.pure full
%token INTEGER "n"
%token PLUS "+"
%token MULT "*"
%token DIV "/"
%token MINUS "-"
%token EOL "\n"

%code top {
    #include <stdio.h>
}

%code provides {
    #define YY_DECL enum yytokentype yylex()
    YY_DECL;
    int yyerror(const char * s);
}

%left "+" "-"
%left "*" "/"

%%
Lines:
 Lines L
 | %empty
;

L: E "\n";

E:
 E "+" E {printf("add ");}
 | E "*" E {printf("mult ");}
 | E "-" E {printf("min ");}
 | E "/" E {printf("div ");}
 | "n" {printf("n ");}
;

%%

int yyerror(const char * s)
{
    printf("%s\n", s);
    return 0;
}

int main(void)
{
    yyparse();
    return 0;
}
