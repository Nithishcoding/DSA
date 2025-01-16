/*Develop a menu driven program to convert infix expression to postfix expression using stack and evaluate
the postfix expression. (Test for nested parenthesized expressions) Note: Define Stack structure and
implement the operations. Use different stacks for conversion and evaluation. */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#define MAX_SIZE 20

typedef struct stack
{
    int top;
    char S[MAX_SIZE];
}STACK;

void create(STACK *st)
{
    st->top=-1;
}

int isEmpty(STACK *st)
{
    return st->top==-1 ? 1 : 0;
}

int isfull(STACK *st)
{
    return st->top==MAX_SIZE-1 ? 1 : 0;
}

void push(STACK *st,char ch)
{
    if(isfull(st))
    {
        printf("STACK IS FULL ..reallocating the memory\n");
        int size=(st->top+1)*2;
        STACK *newst=(STACK *)realloc(st,size*sizeof(STACK));
        if(newst==NULL)
        {
            printf("Memory reallocation failed. Cannot push element.\n");
            return;
        }
        st=newst;
    }
    st->S[++st->top]=ch;
}

char pop(STACK *st)
{
    if(isEmpty(st))
    {
        printf("STACK IS UNDERFLOW\n");
        return 0;
    }
    return st->S[st->top--];
}

int chech(char ch)
{
    if(isalnum(ch))
      return 1;
    else if(ch=='(')
      return 2;
    else if(ch==')')
      return 3;
    else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%'||ch=='^'||ch=='$')
      return 4;
    else
      return 5;
}

int pre(char op)
{
    if(op=='+'||op=='-')
      return 1;
    else if(op=='*'||op=='/'||op=='%')
       return 2;
    else if(op=='^'||op=='$')
       return 3;
}

int balancedparenthesis(char inf[])
{
    char ch;
    STACK st3;
    create(&st3);
    for(int i=0;inf[i]!='\0';i++)
    {
        ch=inf[i];
        if(ch=='(')
          push(&st3,ch);
        else if(ch==')')
        {
            if(isEmpty(&st3))
             return 0;//unbalanced
            else
             pop(&st3);
        }
    }
    if(isEmpty(&st3))
      return 1;//balanced
    else
      return 0;//unbalanced
}

void convert(char inf[],char pst[])
{
    char x,ch,operand;
    STACK st1;
    create(&st1);
    int test,j=0,f=1;
    for(int i=0;inf[i]!='\0';i++)
    {
        ch=inf[i];
        test=chech(ch);
        switch (test)
        {
        case 1:
            pst[j++]=ch;
            break;
        case 2:
            push(&st1,ch);
            break;
        case 3:
            while ((x=pop(&st1))!='(')
            {
                pst[j++]=x;
            }
            break;
        case 4:
            do
            {
             if(isEmpty(&st1))
              f=1;
             else if(st1.S[st1.top]=='(')
              f=1;
             else if(pre(ch) > pre(st1.S[st1.top]) || ch=='^' || ch=='$')
              f=1;
             else
             {
              f=0;
              pst[j++]=pop(&st1);
             }
            }while(f==0);
            push(&st1,ch);
            break;
        }
    }
    while(!isEmpty(&st1))
      pst[j++]=pop(&st1);
      pst[j]='\0';
}

int cal(char a,char b,char op)
{
    int res;
    switch (op)
    {
    case '+':
        res=a+b;
        //return res;
        break;
    case '-':
        res=a-b;
        //return res;
        break;
    case '*':
        res=a*b;
        //return res;
        break;
    case '/':
        res=a/b;
       // return res;
        break;
    case '%':
        res=a%b;
       // return res;
        break;
    case '^':
        res=pow(a,b);
       // return res;
        break;
    }
     return res;
}

int evaluate(char pst[])
{
    STACK st2;
    create(&st2);
    int i,op1,op2,res,operand,val;
    for(i=0;pst[i]!='\0';i++)
    {
        if(isalpha(pst[i]))
        {
           printf("Enter the value for %c\n",pst[i]);
            scanf("%d",&val);
           push(&st2,val);
        }
        else if(isdigit(pst[i]))
        {
            operand=0;
            while (isdigit(pst[i]))
            {
               operand*=10+(pst[i]-'0');
               i++;
            }
            i--;
            push(&st2,operand);
        }
        else if (pst[i]=='+' || pst[i]=='-' || pst[i]=='*' || pst[i]=='/' || pst[i]=='%' ||pst[i]=='^' || pst[i]=='$')
        {
            op2=pop(&st2);
            op1=pop(&st2);
            res=cal(op1,op2,pst[i]);
            push(&st2,res);
        }
    }
    return pop(&st2);
}


void main()
{
    char inf[30],pst[30];
    int choice,res;

    for(;;)
    {
        printf("\nINFIX TO POSTFIX CONVERSION AND EVALUATION\n");
        printf("===========================================\n");
        printf("1.ENTER INFIX EXPRESSION\n2.CONVERT INFIX TO POSTFIX EXPRESSION\n3.EVALUATION OF POSTFIX EXPRESSION\n");
        printf("Enter your choice\n");
          scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the infix expression\n");
              scanf("%s",inf);
            break;
        case 2:
            if(!balancedparenthesis(inf))
            {
                printf("parenthesis is not balanced\n");
                break;
            }
            convert(inf,pst);
            printf("POSTFIX EXP IS:%s\n",pst);
            break;
        case 3:
             res=evaluate(pst);
             printf("Result=%d",res);
             break;
        case 4:
             printf("Exiting from the program\n");
             exit(0);
        default:
             printf("Invalid choice\n");
            break;
        }
    }
}
