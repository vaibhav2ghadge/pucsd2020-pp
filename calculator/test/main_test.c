#include<stdio.h>
#include "assert.h"
#include "../include/evalutor.h"
int main(){
    struct expre *ex = (struct expre*) malloc(sizeof(struct expre));
    ex->expression = (char*)malloc(sizeof(char)*100);
    ex->charStack = (struct stack2*) malloc(sizeof(struct stack2));
    ex->charStack->stack = (char *)malloc(sizeof(char)*100);
    ex->intStack = (struct stack1*) malloc(sizeof(struct stack1));
    ex->intStack->stack = ( float*)malloc(sizeof(int)*100);
    ex->charStack->top = -1;
    ex->intStack->top = -1;
    ex->expression = "1+2+3";
    assert((int) evalute(ex)==6);
    ex->expression = "1+2-3";
    assert((int) evalute(ex)==0);
    ex->expression = "1+2/2";
    assert((int) evalute(ex)==2);
    ex->expression = "1+2+2*22";
    assert((int) evalute(ex)==47);
    ex->expression = "22+(22+3)";
    assert((int) evalute(ex)==47);
    printf("\n Congo Passed All Test cases\n\n");
}