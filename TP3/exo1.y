%right "*" "+"
%%
E:
    E "+" E
    | E "*" E
    | "expression"

%%
