
%{
#include<stdio.h>
int l=0,s=0;
%}
%%
[\n]+ l++;
[' '\n\t]+ s++; 
%%
void main()
{
FILE *fp=fopen("input4.txt","r");
yyin=fp;	
yylex();
{ printf("\nNo of lines= %d",l); } 
{ printf("\nNo of space= %d",s); } 
{ printf("\nNo of Words= %d",s+l);}
}

