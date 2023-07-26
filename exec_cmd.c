#include "main.h"

void exec_cmd(char **filepath){
       int id;
       int status;
       id = fork();
       if(id == 0){
        execve(filepath[0], filepath, NULL);
       }else{
              wait(&status);
       }



}
