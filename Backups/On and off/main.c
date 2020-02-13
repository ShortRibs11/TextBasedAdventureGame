#include <stdio.h>
#include "parser.h"

static char input[100] = "look around";

static int getInput(void) {
	printf("\n--> ");
	return fgets(input, sizeof(input), stdin) != NULL;
}

int main() {
	printf("Welcome to Little Cave Adventure.\n");
	while (parseAndExecute(input) && getInput());
	printf("Bye!\n");
	return 0;
}
