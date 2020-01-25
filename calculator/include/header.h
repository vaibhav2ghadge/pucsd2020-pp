#include "types.h"
int isNumber(char ch);
float add(float a,float b);
float sub(float a,float b);
float mul(float a,float b);
float div1(float a,float b);
float per(float a,float b);
struct expre* allocateMemory();
void dberror(struct expre *exp);
int precendence(char a,char b);
float evalute(struct expre *exp);
float value(char ch,float a,float b);
int isCharStackEmpty(struct stack2 *stack);