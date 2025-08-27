
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		write(STDERR_FILENO, "Usage: filter <string_to_replace>\n", 33);
		return 1;
	}

	char *pattern = argv[1];
	size_t pattern_len = strlen(pattern);
	if (pattern_len == 0) {
		write(STDERR_FILENO, "Error: pattern cannot be empty\n", 31);
		return 1;
	}

	char *buffer = malloc(pattern_len);
	if (!buffer) {
		write(STDERR_FILENO, "Error: memory allocation failed\n", 32);
		return 1;
	}

	size_t idx = 0;
	char c;

	while (read(STDIN_FILENO, &c, 1) > 0) {
		if (c == pattern[idx]) {
			buffer[idx++] = c;
			if (idx == pattern_len) {
				write(STDOUT_FILENO, "******", pattern_len);
				idx = 0;
			}
		} else {
			if (idx > 0) {
				write(STDOUT_FILENO, buffer, idx);
				idx = 0;
			}
			write(STDOUT_FILENO, &c, 1);
		}
	}

	if (idx > 0) {
		write(STDOUT_FILENO, buffer, idx);
	}
	free(buffer);
	return 0;
}

// #!/bin/bash
// [ "$1" ] || exit
// sed "s/$1/$(printf '%*s' ${#1} '' | tr ' ' '*')/g"