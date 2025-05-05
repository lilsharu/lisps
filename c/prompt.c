#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32

#include <string.h>
static char buffer[2048];

char* readline(char* prompt) {
	fputs(prompt, stdout);
	fgets(buffer, sizeof(buffer), stdin);
	char* heap_copy = strdup(buffer);
	if (!heap_copy) {
		puts("Out of Memory :(");
		exit(1);
	}
	size_t len = strlen(heap_copy);
	if (heap_copy[len - 1] == '\n') {
		heap_copy[len - 1] = '\0';
	}
	return heap_copy;
}

// Fake "add_history" function
void add_history(char* input) {}

#else

#include <editline/readline.h>

#endif

int main() {
	puts("Lispy Version 0.0.0.0.1");
	puts("Press Ctrl+c to Exit\n");

	while (1) {
		char* input = readline("lispy > ");
		add_history(input);
		printf("No, you're a %s\n", input);
		free(input);
	}

	return 0;
}
