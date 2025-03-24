#include <unistd.h>

int seen_before(char *str, int max, char c)
{
	int i = 0;
	while (i < max)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int i = 0;
		int j = 0;
		char	*str1 = argv[1];
		char	*str2 = argv[2];

		while (str1[i])
		{
			if (!seen_before(str1, i, str1[i]))
				write(1, &str1[i], 1);
			i++;
		}
		while (str2[j])
		{
			if (!seen_before(str1, i, str2[j]) && !seen_before(str2, j, str2[j]))
				write(1, &str2[j], 1);
			j++;
		}
	}
	write(1, "\n", 1);
}
