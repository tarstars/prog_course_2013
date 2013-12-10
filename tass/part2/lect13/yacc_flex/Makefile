tokenizer: lex.yy.c y.tab.c
	gcc -o tokenizer lex.yy.c -lfl y.tab.c

lex.yy.c: tokens.y
	flex tokens.y

y.tab.c: calc.y
	yacc calc.y -d

