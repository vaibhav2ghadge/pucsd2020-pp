#include <stdio.h>
#include "../include/header.h"
#include<string.h>
const char *st = "INSERT INTO calculation(expression,answer) VALUES('%s','%f')";
int main(){

    struct expre *ex = allocateMemory();
    fputs("initialization done \n",ex->logger->infoLog->infoLog);
    scanf("%s",ex->expression);
    fputs(ex->expression,ex->logger->infoLog->infoLog);
    float ans = evalute(ex);
    size_t st_len = strlen(st);
    //todo remove hard code 100
    char query[st_len + 2*100+1]; 
    int len = snprintf(query, st_len + 2*100+1, st,ex->expression,ans);
    if (mysql_real_query(ex->con, query, len)){
      dberror(ex);
    }
    snprintf(query,100,"answer = %f\n",ans);
    fputs(query,ex->logger->infoLog->infoLog);
    free(ex);
    return 0; 
} 
