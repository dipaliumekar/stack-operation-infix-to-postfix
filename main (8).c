/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
struct stack
{
    char ele;
    struct stack*next;
   
};
void push(int);
int pop();
int precedence(char);
struct stack*top=NULL;
int main()
{
    char infix[20],postfix[20];
    int i=0,j=0;
    printf("enter infix expression :");
    scanf(" %s",infix);
    while(infix[i]!='\0')
    {
        if(isalnum(infix[i]))
        postfix[j++]=infix[i];
        else
        {
            if(top==NULL)
            push(infix[i]);
            else
            {
                while(top!=NULL && (precedence(top->ele)>=precedence(infix[i])))
                postfix[j++]=pop();
                push(infix[i]);
               
            }
        }
       
        ++i;
   
    }
    while (top!=NULL)
    postfix[j++]=pop();
    postfix[j]='\0';
    printf(" %s",postfix);
    return 0;
}
int precedence(char x)
{
    switch(x)
    {
        case '^': return 4;
        case '*':
        case '/': return 3;
        case '+':
        case '-': return 2;
        default : return 0;
       
       
    }
}
void push (int x)
{
    int item;
    struct stack*temp;
    temp=(struct stack*)malloc(sizeof(struct stack));
    temp->ele=x;
    if(top==NULL)
    {
        top=temp;
    }
    else
    {
        temp->next=top;
        top=temp;
    }
   

}

int pop ()
{
    struct stack*temp;
    char item;
    if(top==NULL)
    printf("EMPTY STACK");
    else if(top->next==NULL)
    {
        temp=top;
        item=top->ele;
        top=NULL;
        free(temp);
       
    }
    else
    {
        temp=top;
        item=top->ele;
        top=top->next;
        free(temp);
       
    }
    return item;
}

