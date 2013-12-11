%{ 
#include <stdlib.h> 
void yyerror(char *); 
#include "y.tab.h" 
%}

%%
[0-9]+  {yylval =  atoi(yytext); return NUMBER;}
"+"  {return *yytext;}
"*"  {return *yytext;}
%%

int yywrap(void) { 
 return 1; 
}

