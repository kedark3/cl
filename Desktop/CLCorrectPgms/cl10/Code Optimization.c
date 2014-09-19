

#include<stdio.h>
#include<string.h>
#include<ctype.h>

void input();
void output();
void change(int p,int q,char *res);
void csub();
void ceval();

struct expr
{

  char op[2],op1[5],op2[5],res[5];
  int flag;

}arr[10];
 
 int n;

int main()
{
  int ch=0;
  while(ch!=3)
  {
    
    printf("\nEnter the method you want to employ : ");
    printf("\n1. Common expression elimination");
    printf("\n2. Constant expression evaluation");
    printf("\n3. Exit :\t");
    scanf("%d",&ch);
    switch(ch)
    
 {
      case 1:
        input();
        csub();
        output();
        break;
        
      case 2:
        input();
        ceval();
        output();
        break;

      default:
        break;
     }
   }
 }

void input()
{
  int i;
  char eq[2];
  printf("\n\nEnter the maximum number of  expressions : ");
  scanf("%d",&n);
  printf("\nEnter the input : \n");
  for(i=0;i<n;i++)
  {
    scanf("%s",arr[i].res);
    scanf("%s",eq);
    scanf("%s",arr[i].op1);
    scanf("%s",arr[i].op);
    scanf("%s",arr[i].op2);
    arr[i].flag=0;
   }
 }


void csub()
{
  int i,j;
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(strcmp(arr[i].op,arr[j].op)==0)   //check if operators are same
      {
        if(strcmp(arr[i].op,"+")==0||strcmp(arr[i].op,"*")==0)    //check if they are + or * order of operands doesn't matter
        {
          if(strcmp(arr[i].op1,arr[j].op1)==0&&strcmp(arr[i].op2,arr[j].op2)==0 || strcmp(arr[i].op1,arr[j].op2)==0&&strcmp(arr[i].op2,arr[j].op1)==0)  
          {
            arr[j].flag=1;       //if flag=1, won't print
            change(i,j,NULL);    //change any operand below that uses result of this expression
           }
         }
        else                   
        {
          if(strcmp(arr[i].op1,arr[j].op1)==0&&strcmp(arr[i].op2,arr[j].op2)==0)
          {
            arr[j].flag=1;
            change(i,j,NULL);
           }
         }
       }
     }
   }
 }


void output()
{ 
  int i=0;
  printf("\nOptimized code is : ");
  for(i=0;i<n;i++)
  {
    if(arr[i].flag==0)
    {
      printf("\n%s = %s %s %s",arr[i].res,arr[i].op1,arr[i].op,arr[i].op2);
     }
   }
 }


void change(int p,int q,char *res)
{
  int i;
  for(i=q+1;i<n;i++)
  {
    if(strcmp(arr[q].res,arr[i].op1)==0)
      if(res == NULL)                         //for csub
        strcpy(arr[i].op1,arr[p].res);
      else                                    //for ceval
        strcpy(arr[i].op1,res);                  
    else if(strcmp(arr[q].res,arr[i].op2)==0)
      if(res == NULL)                         //for csub
        strcpy(arr[i].op2,arr[p].res);
      else                                    //for ceval
        strcpy(arr[i].op2,res);
   }
 }


void ceval()
{
  int i;
  int op1,op2,res;
  char op,res1[5];
  for(i=0;i<n;i++)
  {
    if(isdigit(arr[i].op1[0]) && isdigit(arr[i].op2[0]))            //if both digits, store them in variables
    {
      op1=atoi(arr[i].op1);
      op2=atoi(arr[i].op2);
      op=arr[i].op[0];
      switch(op)
      {
        case '+':
          res=op1+op2;
          break;

        case '-':
          res=op1-op2;
          break;

        case '*':
          res=op1*op2;
          break;

        case '/':
          res=op1/op2;
          break;
       }
      sprintf(res1,"%d",res);                              
      arr[i].flag=1;                                     //eliminate expr and replace any operand below that uses result of this expr
      change(i,i,res1);
     }
   }
 }

 
 
 
/*Output
comp154@comp154:~$ c ico.c
comp154@comp154:~$ ./a.out

Enter the method you want to employ : 
1. Common expression elimination
2. Constant expression evaluation
3. Exit :	1


Enter the maximum number of  expressions : 4

Enter the input : 
t1 = a + b
t2 = c * t1
t3 = a + b
t4 = t3 / d

Optimized code is : 
t1 = a + b
t2 = c * t1
t4 = t1 / d

Enter the method you want to employ : 
1. Common expression elimination
2. Constant expression evaluation
3. Exit :	2


Enter the maximum number of  expressions : 3

Enter the input : 
t1 = 3 + 2
t2 = c * t1
t3 = t1 / d

Optimized code is : 
t2 = c * 5
t3 = 5 / d

Enter the method you want to employ : 
1. Common expression elimination
2. Constant expression evaluation
3. Exit :	3
comp154@comp154:~$ 

*/
