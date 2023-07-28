#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>


extern char **environ;

int _printer(const char *buff, unsigned int size);
int con_args(char *string, char **args);
int _strcmp(char *string1, char *string2);
int check_path(char **argu);
char *_strdup(char *string);
char *find_path(char *path, char *command);
int exec_cmd(char **args);

int print_numbers(int num);
int _strlen(const char *string);
int not_found(char **arguments, int counter);
char *_getenv(char *buffer);

int _putchar(char c);
int file_exist(char *pathname);
void free_all(char **grid, int heigth);
void freed(char *entry);
int check_blt(char **arguments, int exit_stat);

#endif
