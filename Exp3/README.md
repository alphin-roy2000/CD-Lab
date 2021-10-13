# Experiment 3
Construct a recursive descent parser for an expression according to the grammar below.
E → TE’
E’ → +TE’/- TE’/ε
T → FT’
T’ → *FT’/ /FT’/ ε
F → (E) / id




# Input-Output

Enter the arithmetic expression : a+b*c
a+b*c
ACCEPTED :)

Enter the arithmetic expression : a+(b*
a+(b*
ACCEPTED :)

