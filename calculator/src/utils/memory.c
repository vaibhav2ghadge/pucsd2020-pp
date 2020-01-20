#include "../../include/header.h"
#include<stdlib.h>


struct expre* allocateMemory(){
    struct expre *ex = (struct expre*) malloc(sizeof(struct expre));
    ex->expression = (char*)malloc(sizeof(char)*100);
    ex->charStack = (struct stack2*) malloc(sizeof(struct stack2));
    ex->charStack->stack = (char *)malloc(sizeof(char)*100);
    ex->intStack = (struct stack1*) malloc(sizeof(struct stack1));
    ex->intStack->stack = ( float*)malloc(sizeof(int)*100);
    ex->charStack->top = -1;
    ex->intStack->top = -1;
    return ex;
}