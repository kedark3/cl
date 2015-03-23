
%{
#include<stdio.h>
char str[20],str1[20];
FILE *fp,*ft;
%}
%option noyywrap
%%
[a-zA-Z]+ {
	if(strcmp(str,yytext)==0)
	  {
	   fprintf(ft,"%s ",str1);
	   printf("%s ",str1);
	  }
	else
	  {
	   fprintf(ft,"%s",yytext);
	   printf("%s ",yytext);
	  }
	}

%%
void main()
{
fp=fopen("inputfile.txt","r");
ft=fopen("outputfile.txt","w");
yyin=fp;
printf("\nEnter The string to find:\t");
scanf("%s",str);
printf("\nEnter the string to replace:\t");
scanf("%s",str1);
yylex();
}


