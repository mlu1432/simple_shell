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

int _printer(const char *prompt, unsigned int size);
int con_args(char *entry, char **arguments);
int _strcmp(char *str1, char *str2);
int verify_path(char **arguments);
char *_strdup(char *str);
char *find_path(char *dir_path, char *command);
int exec_cmd(char **arguments);

int print_numbers(int n);
int _strlen(const char *string);
int not_found(char **arguments, int counter);
char *_getenv(char *global_var);

int _putchar(char c);
int file_exist(char *pathname);
void free_all(char **grid, int heigth);
void freed(char *entry);
int verify_blt(char **arguments, int exit_stat);

#endif
