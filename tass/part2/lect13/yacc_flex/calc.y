%{ 
 #include <stdio.h> 
 void yyerror(char *); 
 #define	YYSTYPE	int
%} 

%token NUMBER
%left '+'
%left '*'

%%
whole:
|whole expr {printf("%d\n", $2);}
;

expr: 
NUMBER { $$ = $1;}
| expr '+' expr {$$ = $1 + $3;}
| expr '*' expr {$$ = $1 * $3;}
;

%%

void yyerror(char *s) { 
 fprintf(stderr, "%s\n", s); 
} 
 
int main(void) { 
 yyparse(); 
 return 0; 
}


