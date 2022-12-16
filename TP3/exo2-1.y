%precedence ":"
%precedence "?"
%%
E:
    E "?" E ":" E
    | "expression"

%%
