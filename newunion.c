#include <unistd.h>

int main(int ac, char **argv)
{
	char *str1;
	char *str2;
	int i, j;
	int printed[127] = {0};

	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}

	str1 = argv[1];
	str2 = argv[2];

	i = 0;
	while (str1[i])
	{
		if (!printed[str1[i]])
		{
			write(1, &str1[i], 1);
			printed[str1[i]] = 1;
		}
		i++;
	}
	j = 0;
	while (str2[j])
	{
		if (!printed[str2[j]])
		{
			write(1, &str2[j], 1); 
			printed[str2[j]] = 1;
		}
		j++;
	}

	write(1, "\n", 1);

	return (0);
}
