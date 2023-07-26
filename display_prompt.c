
#include "main.h"

int display_prompt(void)
{
    size_t buff_count;
    char *path;
    char *buffer;
    char **argu;
    int getline_result;
    int pid;
    buff_count = 0;
    buffer = malloc(sizeof(char) * buff_count);
    buffer = NULL;

    pid = getpid();


//printline("shell()$: ");

while (1)
{
printf("shell: " );
getline_result = getline(&buffer, &buff_count, stdin);
argu = con_args(buffer, " \n");

if(file_exist(argu[0])){
    exec_cmd(argu);
}else{
    path = get_path(argu[0]);
    argu[0]= strdup(path);
    exec_cmd(argu);

}

}

free(buffer);



return (0);
}
