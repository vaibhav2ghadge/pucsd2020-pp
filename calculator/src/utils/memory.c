#include "../../include/header.h"
#include<stdlib.h>
#include <mysql/mysql.h>


struct expre* allocateMemory(){
    struct expre *ex = (struct expre*) malloc(sizeof(struct expre));
    ex->expression = (char*)malloc(sizeof(char)*100);
    ex->charStack = (struct stack2*) malloc(sizeof(struct stack2));
    ex->charStack->stack = (char *)malloc(sizeof(char)*100);
    ex->intStack = (struct stack1*) malloc(sizeof(struct stack1));
    ex->intStack->stack = ( float*)malloc(sizeof(int)*100);
    ex->charStack->top = -1;
    ex->intStack->top = -1;
    ex->logger = (struct log*)malloc(sizeof(struct log));
    ex->logger->errorLog = (struct errorLogger*)malloc(sizeof(struct errorLogger));
    ex->logger->infoLog = (struct infoLogger*)malloc(sizeof(struct infoLogger));
    ex->logger->errorLog->errorLog = fopen("./log/errorlog","a+");
    ex->logger->infoLog->infoLog = fopen("./log/infolog","a+");
    ex->con = mysql_init(NULL);
     if (ex->con == NULL) {
      fprintf(stderr, "%s\n", mysql_error(ex->con));
      exit(1);
    }
    fputs("\nMemory allocation done for stack \n",ex->logger->infoLog->infoLog);
    //connecting to db
    if (mysql_real_connect(ex->con, "localhost", "root", "as2d2p", NULL, 0, NULL, 0) == NULL) {
      fputs(mysql_error(ex->con),ex->logger->infoLog->infoLog);
      mysql_close(ex->con);
      exit(1);
    }
    //creating db for calculation
    if (mysql_query(ex->con, "CREATE DATABASE IF NOT EXISTS CALCULATOR")){
      fprintf(stderr, "%s\n", mysql_error(ex->con));
      mysql_close(ex->con);
      exit(1);
    }
    mysql_close(ex->con);  //closing db bcz we want to change db to calculator
    ex->con = mysql_init(NULL);
    if (mysql_real_connect(ex->con, "localhost", "root", "as2d2p", "CALCULATOR", 0, NULL, 0) == NULL) {
      fprintf(stderr, "%s\n", mysql_error(ex->con));
      mysql_close(ex->con);
      exit(1);
    }
    // create table
    if (mysql_query(ex->con, "CREATE TABLE IF NOT EXISTS calculation(expression TEXT, answer FLOAT)")) {      
      fprintf(stderr, "%s\n", mysql_error(ex->con));
      mysql_close(ex->con);
      exit(1);
    }
    return ex;
}