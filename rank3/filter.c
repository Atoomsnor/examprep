#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void filter_input(const char *pattern, size_t len)
{
	size_t i = 0;
	char c;

	while (read(STDIN_FILENO, &c, 1) > 0)
	{
		if (c == pattern[i])
		{
			i++;
			if (i == len)
			{
				size_t j = 0;
				while (j < len)
				{
					write(STDOUT_FILENO, "*", 1);
					j++;
				}
				i = 0; // reset match index
			}
		}
		else
		{
			// If partial match occurred, write matched characters
			if (i > 0)
			{
				write(STDOUT_FILENO, pattern, i);
				i = 0;
			}
			write(STDOUT_FILENO, &c, 1);
		}
	}
	// Flush any remaining partial match
	if (i > 0)
		write(STDOUT_FILENO, pattern, i);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	char *str = argv[1];
	int	len = 0;
	while (str[len])
		len++;
	filter_input(str, len);
	return 0;
}
