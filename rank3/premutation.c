#include <unistd.h>
#include <stdlib.h>

void write_string(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void generate_permutations(char *str, int start, int length)
{
	if (start == length - 1)
	{
		write_string(str);
		return;
	}
	
	int i = start;
	while (i < length)
	{
		swap(&str[start], &str[i]);
		generate_permutations(str, start + 1, length);
		swap(&str[start], &str[i]);
		
		i++;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(2, "Usage: ./permutations string\n", 29);
		return 1;
	}
	
	char *input = argv[1];
	int length = 0;
	while (input[length])
		length++;

	generate_permutations(input, 0, length);
	
	return 0;
}