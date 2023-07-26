#include "main.h"

void exec_cmd(char **filepath){
       int id;
       int status;
        status = 0;
       id = fork();
       if(id == 0){
        if(execve(filepath[0], filepath, environ) == -1){

                     perror("ERROR");
                     exit(1);
        }
       }else{
              wait(&status);
       }



}
