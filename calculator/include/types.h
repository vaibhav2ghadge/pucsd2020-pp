#include<stdio.h>
#include <mysql/mysql.h>
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
    struct log *logger;
    MYSQL *con;
};
struct log{
    struct errorLogger *errorLog;
    struct infoLogger *infoLog;
};
struct errorLogger{
    FILE *errorLog;
};
struct infoLogger{
    FILE *infoLog;
};