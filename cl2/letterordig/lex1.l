%{
#include<stdio.h>
%}
%%
[a-z A-Z]+  {printf("\n%s= character\n",(char *)yytext);}
[0-9]+ {printf("\n%s= digit..\n",(char *)yytext);}
%%
main()
{
FILE *fp;
fp=fopen("input14.txt","r");
yyin=fp;
yylex();
}
