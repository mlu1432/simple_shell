
#include "main.h"

int display_prompt(void)
{
    size_t buff_count;
    char *path;
    int input;
    char *buffer;
    char **argu;
    buff_count = 0;
    buffer = malloc(sizeof(char) * buff_count);
    buffer = NULL;
    input = 0;

while (-1)
{
printline("shell: ");
input = getline(&buffer, &buff_count, stdin);
if(input == EOF || input == -1){
    printline("\n");
    return -1;
}else{

    argu = con_args(buffer, " \n");
    if(argu[0] == NULL){
        continue;
    }
    if(file_exist(argu[0])){
            exec_cmd(argu);
}else{
    path = get_path(argu[0]);
    argu[0]= strdup(path);
    exec_cmd(argu);

}


}



}

free(buffer);



return (0);
}
