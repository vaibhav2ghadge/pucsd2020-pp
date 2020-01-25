#include <stdio.h>
#include "../include/header.h"
#include<string.h>
int main() 
{ /*
      MYSQL *con = mysql_init(NULL);

  if (con == NULL) 
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      exit(1);
  }
  */
     struct expre *ex = allocateMemory();
    fputs("initialization done \n",ex->logger->infoLog->infoLog);
    scanf("%s",ex->expression);
    fputs(ex->expression,ex->logger->infoLog->infoLog);
    float ans = evalute(ex);
    char *st = "INSERT INTO calculation(expression,answer) VALUES('%s','%f')";
    size_t st_len = strlen(st);
    //todo remove hard code 100
    char query[st_len + 2*100+1]; 
    int len = snprintf(query, st_len + 2*100+1, st,ex->expression,ans);
    if (mysql_real_query(ex->con, query, len)){
      fprintf(stderr, "%s\n", mysql_error(ex->con));
      mysql_close(ex->con);
      exit(1);
  }
    printf("\n asda %s",query);
    return 0; 
} 
