#ifndef main_h
#define main_h

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>


void display_prompt(void);
char **split_line(char *line);

#endif
