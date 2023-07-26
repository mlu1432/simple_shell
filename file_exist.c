#include "main.h"

int file_exist(char *filepath)
{

    struct stat buffer;
    if(stat(filepath, &buffer)){
        return 0;
    }
    return 1;
}










