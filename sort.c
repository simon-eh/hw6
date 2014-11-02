#include "sort.h"

#define MAX_LENGTH 1024

int reverse = 0;
int ignore_case = 0;
int numeric = 0;

int main(int argc, char const *argv[]) {

	parse_args(argc,argv);

	char** all_lines = malloc(MAX_LENGTH * MAX_LENGTH * sizeof(char*));
	int index = 0;
	int cont = 1;
	while(cont && index < MAX_LENGTH*MAX_LENGTH) {
		*(all_lines + index) = malloc(MAX_LENGTH);
		if(!readline(*(all_lines + index++), MAX_LENGTH)) {
			cont = 0;
		}
	}
	printf("Read in %d lines.\n", index);
	qsort(all_lines, index, sizeof(char*), ptr_strcmp);
	print_list(all_lines, index);
	for(int i=0; i<index; i++) {
		free(*(all_lines + i));
	}
	free(all_lines);
	return 0;
}

long mystrtol(char* start, char** rest) {
	long result = 0;
	int i = 0;
	int multiplier = 1;
	*rest = start;
	while(isspace(*(start + i))) {
		i++;
	}
	if(*(start + i) == '-') {
		multiplier = -1;
	}
	else if(*(start + i) == '+') {
		i++;
	}
	while(*(start + i) <= '9' && *(start + i) >= '0') {
		result = 10*result + *(start + i) - '0';
		*rest = start + i + 1;
		i++;
	}
	
	return result;
}

void parse_args(int argc, char const *argv[]) {
	for(int i=1; i<argc; i++) {
		const char* arg = argv[i];
		if(*arg == '-') {
			switch(*(arg + 1)) {
				case 'f':
					ignore_case = 1;
					break;
				case 'n':
					numeric = 1;
					break;
				case 'r':
					reverse = 1;
					break;
				default:
					print_usage();
					break;
			}
		}
		else {
			print_usage();
		}
	}
}

void print_usage() {
	printf("Correct usage:\n");
	printf("sort [-f -n -r]\n");
	printf("\t-f - Ignore case.\n");
	printf("\t-n - Sort numerically.\n");
	printf("\t-r - Reverse sort order.\n");
	exit(1);
}

void print_list(char** list, int size) {
	for(int i=0; i<size; i++) {
		printf("%s\n", *(list + i));
	}
}

int ptr_strcmp(const void *s1, const void *s2) {
	char const *p1 = *(char* const*)s1;
	char const *p2 = *(char* const*)s2;
	if(numeric) {
		char *a;
		char *b;
		mystrtol(*(char* const*)s1, &a);
		mystrtol(*(char* const*)s2, &b);
		p1 = a;
		p2 = b;
	}
	while(isspace(*p1)) { p1++; }
	while(isspace(*p2)) { p2++; }
	if(reverse) {
		if(ignore_case) {
			return strcasecmp(p2, p1);
		}
		else {
			return strcmp(p2, p1);
		}
	}
	else {
		if(ignore_case) {
			return strcasecmp(p1, p2);
		}
		else {
			return strcmp(p1, p2);
		}
	}
	
}

/* Reads a line from stdin into output. Returns 0 if at EOF */
int readline(char* output, unsigned int max_len) {
	char c;
	int i=0;
	while(sizeof(char)*i < max_len - 1 && (c = getchar()) != '\n' && c != EOF) {
		*(output + i++) = c;
	}
	while(c != '\n' && c != EOF){
		c = getchar();
	}
	*(output + i) = '\0';
	return c!=EOF;
}
