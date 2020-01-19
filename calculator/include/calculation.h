#include "types.h"
float value(char ch,float a,float b){
    switch(ch){
        case '+':return a+b;
        case '-':return b-a;
        case '*':return a*b;
        case '/':return b/a;
        case '%':return a*b/100;
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
        return 0;
    return 1;
}