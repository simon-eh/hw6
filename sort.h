#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readline(char*,unsigned int);
int ptr_strcmp(const void*,const void*);
void print_list(char**,int);
void parse_args(int,char const*[]);
void print_usage();