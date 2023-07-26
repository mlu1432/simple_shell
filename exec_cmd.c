#include "main.h"

void exec_cmd(char **filepath){
       int id;
       int status;
       id = fork();
       if(id == 0){
        if(execve(filepath[0], filepath, NULL) == -1)
                     perror("ERROR");
       }else{
              wait(&status);
       }



}
