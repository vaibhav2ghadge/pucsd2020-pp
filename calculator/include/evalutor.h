#include <string.h>
#include<stdlib.h>
struct stack1{
    int *stack;
    int top;
};
struct stack2{
    char *stack;
    int top;
};
struct expre {
    char *expression;
    struct stack1 *intStack;
    struct stack2 *charStack;
    
};
int value(char ch,int a,int b){
    switch(ch){
        case '+':return a+b;
        case '-':return b-a;
        case '*':return a*b;
        case '/':return b/a;
    }
    return 0;
}
int isNumber(char ch){
    if(ch>='0' && ch<='9')
    return 1;
    return 0;
}
int isIntStackEmpty(struct stack1 stack){
    if(stack.top==-1)
        return 0;
    return 1;
}
int isCharStackEmpty(struct stack2 *stack){
    if(stack->top==-1)
        return 0;
    return 1;
}
int precendence(char a,char b)
{
    if(a=='('||a==')')
        return 0;
    //kept this bcz we can understand the logic
    else if((a=='+'||a=='-')&&(b=='*'||b=='/'))
        return 1;
    return 1;
}
int evalute(struct expre *exp){
    int i=0;
    for(i=0;i<strlen(exp->expression);i++){
        
        if(exp->expression[i]>='0' && exp->expression[i]<='9'){
             int number = 0;
            while(isNumber(exp->expression[i])){
                number = number*10 + (exp->expression[i] - '0');
                i++;
            }
            exp->intStack->stack[++exp->intStack->top] = number;
             printf("\nadddidng number to stack %d top %d",exp->intStack->stack[exp->intStack->top],exp->intStack->top);
             i--;
        }
        else if(exp->expression[i]=='(')
        exp->charStack->stack[++exp->charStack->top] = exp->expression[i];
        else if(exp->expression[i]=='+'||
                exp->expression[i]=='-'||
                exp->expression[i]=='*'||
                exp->expression[i]=='/'){
            while (isCharStackEmpty(exp->charStack) && precendence(exp->charStack->stack[exp->charStack->top],exp->expression[i])){
                    int no1 = exp->intStack->stack[exp->intStack->top];
                    --exp->intStack->top;
                    int no2 = exp->intStack->stack[exp->intStack->top];
                    exp->intStack->top--;
                    printf("\n no1 %d no2 %d i %d hcar stack %d",no1,no2,i,exp->charStack->top);
                    exp->intStack->stack[++exp->intStack->top] = value(exp->charStack->stack[exp->charStack->top],no1,no2);
                    --exp->charStack->top;
            }
            exp->charStack->stack[++exp->charStack->top] = exp->expression[i];
            printf("\nafter %d ",exp->intStack->stack[exp->intStack->top]);
           //printf("top of stack %d ",exp->intStack->stack[exp->intStack->top]);
        }
        else if(exp->expression[i]==')'){
            while(!isCharStackEmpty(exp->charStack) && exp->charStack->stack[exp->charStack->top]!='('){
                  int no1 = exp->intStack->stack[exp->intStack->top];
                    --exp->intStack->top;
                    int no2 = exp->intStack->stack[exp->intStack->top];
                    exp->intStack->top--;
                    exp->intStack->stack[++exp->intStack->top] = value(exp->charStack->stack[exp->charStack->top],no1,no2);
                    --exp->charStack->top;
            }
            if(!isCharStackEmpty(exp->charStack))
            --exp->charStack->top;
             printf("after %d ",exp->intStack->stack[exp->intStack->top]);
        }
            
        }
         
        while(isCharStackEmpty(exp->charStack)){
            printf("\n top %d",exp->intStack->top);
            int no = exp->intStack->stack[exp->intStack->top];
            --exp->intStack->top;
            int no2 = exp->intStack->stack[exp->intStack->top];
            --exp->intStack->top;
    
            exp->intStack->stack[++exp->intStack->top] = value(exp->charStack->stack[exp->charStack->top],no,no2);
            --exp->charStack->top;
    

        }
        printf("\nbefore return %d",exp->intStack->stack[exp->intStack->top]);
    return exp->intStack->stack[exp->intStack->top];
    }
    //s int stack
    //st char stack



