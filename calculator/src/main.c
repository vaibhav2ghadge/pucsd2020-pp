
#include <stdio.h>
#include "../include/evalutor.h"
int main() 
{ 
    char expression[100];
    int no;
    struct expre *ex = (struct expre*) malloc(sizeof(struct expre));
    ex->expression = (char*)malloc(sizeof(char)*100);
    ex->charStack = (struct stack2*) malloc(sizeof(struct stack2));
    ex->charStack->stack = (char *)malloc(sizeof(char)*100);
    ex->intStack = (struct stack1*) malloc(sizeof(struct stack1));
    ex->intStack->stack = ( int*)malloc(sizeof(int)*100);
    ex->charStack->top = -1;
    ex->intStack->top = -1;
    //scanf("%s",ex->expression);
    //printf("%s ",ex->expression);
    ex->expression="1+10*2";
    printf("\n ans %d ",evalute(ex));
    return 0; 
} 
