%{ 
#include<string.h> 
#include<stdio.h> 
struct icode 
{ 
	char op1; 
	char op2; 
	char op; 
	char res; 
}code[10]; 

int index1=0; 

char addtotable(char op1,char op,char op2); 
void display();  
void quadruple(); 
void triple(); 
%} 

%union 
{ 
	char p; 
} 

%token<p> LETTER DIGIT EQUAL PLUS MINUS MULT DIV 
%type<p> expr stat 

%left PLUS MINUS 
%left MULT DIV 
%right EQUAL 

%% 

stat:LETTER EQUAL expr {addtotable((char)$1,'=',(char)$3);} 
     |expr 
     ; 

expr:expr PLUS expr {$$=addtotable((char)$1,'+',(char)$3);} 
    |expr MINUS expr {$$=addtotable((char)$1,'-',(char)$3);} 
    |expr MULT expr {$$=addtotable((char)$1,'*',(char)$3);} 
    |expr DIV expr {$$=addtotable((char)$1,'/',(char)$3);} 
    |LETTER {$$=(char)$1;} 
    |DIGIT {$$=(char)$1;} 
    ; 

%% 

char temp='@'; //ASCII before A
char addtotable(char op1,char op,char op2) 
{ 
	temp++;	 
	code[index1].op1=op1; 
	code[index1].op2=op2; 
	code[index1].op=op; 
	code[index1].res=temp; 
	 
	index1++; 
	return temp; 

} 

void display() 
{ 
	int cnt=0; 
	char temp='@'; 
	 
	printf("\nThree Address code :\n"); 
	for(cnt=0;cnt<index1;cnt++) 
	{ 
		 
		if(code[cnt].op=='=') 					// ? last case
		{ 
			printf("\n%c %c %c",code[cnt].op1,code[cnt].op,code[cnt].op2); 
		}		 
		else 
		{ 
			temp++;		 
			printf("\n%c = %c %c %c",temp,code[cnt].op1,code[cnt].op,code[cnt].op2); 
		}		 
	}	 
} 


void quadruple() 
{ 
	char temp='@'; 
	int i; 

	printf("\n\nQUADRUPLES"); 
	printf("\n\nOp1      OP      OP2       Result\n"); 
	for(i=0;i<index1;i++) 
	{ 
		if(code[i].op=='=') 
		{ 
			printf("%c        %c       --         %c\n",code[i].op2,code[i].op,code[i].op1);  // result nahi
		} 															//operand1 last la coz result store last
		else 
		{ 
			temp++; 
			printf("%c        %c       %c         %c \n",code[i].op1,code[i].op,code[i].op2,temp);	 
		}			 
	} 

} 



void triple() 
{ 
 	int cnt=0,j; 
 	printf("\n\nTRIPLES\n"); 
 	printf("\nArg1  Arg2      Op\n"); 
 	while(cnt<index1) 
 	{ 
  
 		if(isupper(code[cnt].op1))
 		{ 
 			for(j=0;j<index1;j++) 
 			{ 
  				if(code[j].res==code[cnt].op1) 
  				break; 
 			} 
 			printf("%d\t",j); // for ends
 		} 
  		else 
 			printf("%c\t",code[cnt].op1); 

  
   		if(isupper(code[cnt].op2)) 
  		{ 
 			for(j=0;j<index1;j++) 
 			{ 
  				if(code[j].res==code[cnt].op2) 
  				break; 
 			} 
 			printf("%d\t",j); 		// printing index
 		} 

 	 	else 
 			printf("%c\t",code[cnt].op2); 
 
		printf("%c\t",code[cnt].op);   // last la operator takto
		printf("\n"); 
 		cnt++; 
	}    // while ends

}  



main() 
{ 
	printf("\nEnter the expression: "); 
	yyparse(); 
	display(); 
	quadruple(); 
	triple(); 
} 

yyerror(char *s) 
{ 
	printf("\n%s",s); 
} 

yywrap() 
{ 
	return 1; 
}
