#include <stdio.h>
#include "../include/header.h"
int main() 
{ 
     struct expre *ex = allocateMemory();
    scanf("%s",ex->expression);
    printf("\n ans %f ",evalute(ex));
    return 0; 
} 
