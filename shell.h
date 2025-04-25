#ifndef shell_h
#define shell_h

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>

extern char **environ;
void display_prompt(void);
char **split_line(char *line);
int run_exec(char *path, char **args);
int execute_command(char **args);
char *my_getenv(const char *name);
char *find_path(char *command);
int handle_builtin(char **args, char *line);
void printenv(void);
extern int last_status;
void handle_cd(char **args);
#endif
