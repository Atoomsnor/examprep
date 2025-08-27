#include <stdio.h>
#include <string.h>

int main(int agrc, char **argv)
{
	char *str1 = argv[1];
	char *str2 = argv[2];
	int c1[256] = {0};
	int c2[256] = {0};

	int i = 0;
	while (str1[i])
	{
		c1[str1[i]]++;
		i++;
	}
	i = 0;
	while (str2[i])
	{
		c2[str2[i]]++;
		i++;
	}
	i = 0;
	while (i < 256)
	{
		if (c1[i] != c2[i])
			return 0;
		i++;
	}
	return 1;
}
