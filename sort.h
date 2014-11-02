#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

int readline(char*,unsigned int);
int ptr_strcmp(const void*,const void*);
void print_list(char**,int);
void parse_args(int,char const*[]);
void print_usage();
long mystrtol(char*,char**);
long r_mystrtol(long,char*,char**);