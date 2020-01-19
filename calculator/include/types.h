struct stack1{
    float *stack;
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