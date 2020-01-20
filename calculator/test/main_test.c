#include<stdio.h>
#include "assert.h"
#include "../include/header.h"
int main(){
     struct expre *ex = allocateMemory();
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