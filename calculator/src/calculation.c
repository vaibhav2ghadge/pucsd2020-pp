#include "../include/header.h"
float value(char ch,float a,float b){
    switch(ch){
        case '+':return add(a,b);
        case '-':return sub(a,b);
        case '*':return mul(a,b);
        case '/':return div1(a,b);
        case '%':return per(a,b);
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
    else if((a=='+'||a=='-')&&(b=='*'||b=='/' ||b=='%'))
        return 0;
    return 1;
}