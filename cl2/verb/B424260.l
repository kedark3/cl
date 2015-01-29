%{
  #include<stdio.h>
%}
%%
(am|is|are|was|were|will|shall) {printf("\n%s= verb..\n",(char *)yytext);};
(Aparna|Priya|Gauri|MITCOE|Pune|Kothrud|girl) {printf("\n%s=Noun..",(char *)yytext);};
(good|bad|sad|happy) {printf("\n%s=Adjectives..",(char *)yytext);};
%%
main()
{
FILE *fp=fopen("i.txt","r");
yyin=fp;
yylex();
}
