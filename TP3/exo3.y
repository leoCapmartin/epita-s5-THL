%define lr.type canonical-lr
%%
S:
    "proc" A "."
    | "proc" P ";"
    | "macro" A ";"
    | "macro" P "."
;
A: "id";
P: "id";
%%
