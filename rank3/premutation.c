#include <unistd.h>

void	write_string(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

void	swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort_string(char *str, int length)
{
	int i = 0;
	while (i < length - 1)
	{
		int j = i + 1;
		while (j < length)
		{
			if (str[i] > str[j])
				swap(&str[i], &str[j]);
			j++;
		}
		i++;
	}
}

int next_permutation(char *str, int length)
{
	int i = length - 2;
	int j = length - 1;

	// Find pivot (first element from right that's smaller than next)
	while (i > 0 && str[i] > str[i + 1])
		i--;
	
	if (i < 0)
		return (0);

	// Find smallest element in suffix that's greater than pivot
	while (str[j] < str[i])
		j--;

	swap(&str[i], &str[j]);

	// Reverse the suffix (from i+1 to end)
	i++;
	j = length - 1;
	while (i < j)
	{
		swap(&str[i], &str[j]);
		i++;
		j--;
	}

	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(2, "Usage: ./permutations string\n", 29);
		return (1);
	}

	char *input = argv[1];
	int length = 0;
	while (input[length])
		length++;

	sort_string(input, length); // Start sorted
	write_string(input);

	while (next_permutation(input, length))
		write_string(input);

	return (0);
}

