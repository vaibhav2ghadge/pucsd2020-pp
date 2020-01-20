#include <string.h>
#include<stdlib.h>
#include "calculation.h"
float evalute(struct expre *exp){
    int i=0;
    for(i=0;i<strlen(exp->expression);i++){
        
        if(exp->expression[i]>='0' && exp->expression[i]<='9'){
             int number = 0;
            while(isNumber(exp->expression[i])){
                number = number*10 + (exp->expression[i] - '0');
                i++;
            }
            exp->intStack->stack[++exp->intStack->top] = number;
             i--;
        }
        else if(exp->expression[i]=='(')
        exp->charStack->stack[++exp->charStack->top] = exp->expression[i];
        else if(exp->expression[i]=='+'||
                exp->expression[i]=='-'||
                exp->expression[i]=='*'||
                exp->expression[i]=='/'||
                exp->expression[i]=='%'){
            while (isCharStackEmpty(exp->charStack) && precendence(exp->charStack->stack[exp->charStack->top],exp->expression[i])){
                    float no1 = exp->intStack->stack[exp->intStack->top];
                    --exp->intStack->top;
                    float no2 = exp->intStack->stack[exp->intStack->top];
                    exp->intStack->top--;
                    exp->intStack->stack[++exp->intStack->top] = value(exp->charStack->stack[exp->charStack->top],no1,no2);
                    --exp->charStack->top;
            }
            exp->charStack->stack[++exp->charStack->top] = exp->expression[i];
        
        }
        else if(exp->expression[i]==')'){
            while(isCharStackEmpty(exp->charStack) && exp->charStack->stack[exp->charStack->top]!='('){
                  float no1 = exp->intStack->stack[exp->intStack->top];
                    --exp->intStack->top;
                    float no2 = exp->intStack->stack[exp->intStack->top];
                    exp->intStack->top--;
                    exp->intStack->stack[++exp->intStack->top] = value(exp->charStack->stack[exp->charStack->top],no1,no2);
                    --exp->charStack->top;
            }
            if(isCharStackEmpty(exp->charStack))
            --exp->charStack->top;
        }
            
        }
         
        while(isCharStackEmpty(exp->charStack)){
            float no = exp->intStack->stack[exp->intStack->top];
            --exp->intStack->top;
            float no2 = exp->intStack->stack[exp->intStack->top];
            --exp->intStack->top;
    
            exp->intStack->stack[++exp->intStack->top] = value(exp->charStack->stack[exp->charStack->top],no,no2);
            --exp->charStack->top;
        }
    return exp->intStack->stack[exp->intStack->top];
    }


