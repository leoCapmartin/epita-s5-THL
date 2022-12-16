%define lr.type canonical-lr
%%
E:
    T "[" E "]" "of" E
    | L
;

L:
    "id"
    | L "[" E "]"
;

T: "id";
%%
