#include<stdio.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top== -1) return -1;
    else return stack[top--];
}

int priority(char x)
{
    if(x == '(' ) return 0;
    if(x== '+' || x== '-') return 1;
    if(x=='*' || x=='/') return 2;

}
