tokenizer: lex.yy.o y.tab.o
	gcc -o calc lex.yy.o  y.tab.o -lfl

lex.yy.c: tokens.y y.tab.h
	flex tokens.y

y.tab.c y.tab.h: calc.y
	yacc calc.y -d

clean:
	rm y.tab.c y.tab.h lex.yy.c calc
