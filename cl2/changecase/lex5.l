%{
#include<stdio.h>
int ch; int flag=0; char c;
FILE *f1,*f2;
%}
lower [a-zA-Z]|(\ )|\.
%%
{lower} {switch(ch)
		{	case 1:
				c=toupper(yytext[0]);
				printf("%c",c);
				fprintf(f2,"%c",c);
				break;
			case 2:
				c=tolower(yytext[0]);
				printf("%c",c);
				fprintf(f2,"%c",c);
				break;
			case 3:
				if(yytext[0] >= 'a' && yytext[0] <= 'z')
				{
					c=toupper(yytext[0]);
				}	
				else if(yytext[0] >= 'A' && yytext[0] <= 'Z')
				{
					c=tolower(yytext[0]);
				}
				else
				{
					c=yytext[0];
				}
					printf("%c",c);
					fprintf(f2,"%c",c);
				break;
			case 4:
				if(yytext[0]=='.')
				{
					flag=0;
					c=yytext[0];
					printf("%c",c);
					fprintf(f2,"%c",c);
					break;
				}
				if(flag==0 && yytext[0] != ' ')
				{
					c=toupper(yytext[0]);
					flag=1;
				}
				else
				{
					c=tolower(yytext[0]);
				}
				printf("%c",c);
				fprintf(f2,"%c",c);
				break;
		}
		}
%%
void main()
{
	f1=fopen("A.C","r");
	f2=fopen("B.C","w");
	do
	{	f1=fopen("A.C","r");		
		yyin=f1;
		printf("\n1. TO UPPER\n2. TO LOWER\n3. TOGGLE\n4. SENTENCE");
		printf("\nEnter your choice :: ");
		scanf("%d",&ch);
		yylex();
	}while(ch!=5);
}
