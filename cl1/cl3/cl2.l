%{
#include<stdio.h>
%}
%%
int |
char |
float |
if |
else |
switch |
case |
for |
while |
do+ printf("\n %s IS A KEYWORD.",yytext);
[ ] printf("\n");
[{] printf("\n %s IS STARTING OF BLOCK.",yytext);
[}] printf("\n %s IS ENDING OF BLOCK.",yytext);
[(] printf("\n %s IS OPENING PARANTHESIS.",yytext);
[)] printf("\n %s IS CLOSING PARANTHESIS.",yytext);
[a-zA-Z]+[[]+[0-9]+[]] printf("\n %s IS AN ARRAY.",yytext);
[;] printf("\n %s IS AN END OF STATEMENT.",yytext);
printf |
scanf |
strcpy |
atoi |
strstr |
main |
malloc+ printf("\n %s IS AN INBUILD FUNCTION.",yytext);
[a-z]+[.h] printf("\n %s IS A HEADER FILE.",yytext);
[=] printf("\n %s IS AN ASSIGNMENT OPERATOR.",yytext);
[0-9]+ printf("\n %s IS A NUMBER.",yytext);
[/]+[*]+ printf("\n %s IS STARTOF COMMENT.",yytext);
[*]+[/] printf("\n %s IS END OF COMMENT.",yytext);
[/][/][^\n]+ printf("\n %s IS SINGLE LINE COMMENT.",yytext);
[a-zA-Z]+[a-zA-Z0-9]* printf("\n %s IS VALID VARIABLE NAME.",yytext);
[0-9]+[a-zA-Z0-9]+ printf("\n %s IS INVALID VARIABLE NAME.",yytext);
[#][^\n]+ printf(" \n PREPROCESSOR DIRECTIVE.");
[.] printf("\n PREPROCESSOR DIRECTIVE.");
[+] |
[-] |
[*] |
[/]+ printf("\n %s IS AN ARITHMATIC OPERATOR.",yytext);
[>] |
[<] |
[>=]+ printf("\n %s IS A RELATIONAL OPERATOR.",yytext);
%%
main()
{
FILE *fp;
fp=fopen("assignment2.txt","r");
yyin=fp;
yylex();
}

