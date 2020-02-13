#include <stdio.h>
#include "parser.h"

static char input[100] = "look around";

static int getInput(const char *filename) {
	static FILE *fp = NULL;
	int ok;
	if (fp == NULL) {
		if (filename != NULL) fp = fopen(FILENAME, "rt");
		if (fp == NULL) fp = stdin;
	} else if (fp == stdin) {
		FILE *out = fopen(filename, "at");
		if (out != NULL) {
			fprintf(out, "%s", input);
			fclose(out);
		}
	}
	printf("\n--> ");
	ok = fgets(input, sizeof(input), fp) !=NULL;
	if (fp != stdin) {
		if (ok) {
			printf("%s", input);
		} else {
			fclose(fp);
			ok = fgets(input, sizeof(input), fp = stdin) != NULL;
		}
	}

	return ok;
}

int main(int argc, char argv[]) {
	(void)argc;
	printf("Welcome to Little Cave Adventure.\n");
	while (parseAndExecute(input) && getInput(argv[1]));
	printf("Bye!\n");
	return 0;
}
