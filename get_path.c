#include "main.h"

char *get_path(char *filename)
{
    int i;
    char *path1;
    char *path2;
    char **each_path;
    char *real_path;
    int path_length;
    int file_length;
    int length;
    path1 = getenv("PATH");
    path2 = strdup(path1);
    each_path = con_args(path2, " :");
    file_length = strlen(filename);

    for(i = 0; each_path[i] != NULL; i++)
    {
        path_length = strlen(each_path[i]);
        length = path_length + file_length + 2;
        real_path = malloc(sizeof(char *) * length);
        real_path = strdup(each_path[i]);
        strcat(real_path,"/");
        strcat(real_path,filename);
        if(file_exist(real_path)){
              return real_path;
        }
        free(real_path);
    }

return filename;
}
