#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

int execute(char **tokens, char *argv[], char **env);
int tokens_num(char *buffer, char *delim);
char **parse(char *buffer, char *delim);
char *search(char *command);


#endif

