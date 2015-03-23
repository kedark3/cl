%{ 
#include<string.h> 
#include "y.tab.h"	 
%} 

%% 
[a-z]+ {yylval.p=(char)yytext[0];return LETTER;} 
[0-9]+ {yylval.p=(char)yytext[0];return DIGIT;} 
[+] {return PLUS;} 
[=] {return EQUAL;} 
[-] {return MINUS;} 
[*] {return MULT;} 
[/] {return DIV;} 
\n {return 0;} 
%%
