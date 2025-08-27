#include <unistd.h>

int main(int argc, char **argv)
{
	// if (argc == 1) write /n
	int i = 1;
	while (i < argc)
	{
		int j = 0;
		int in_word = 0;
		while (argv[i][j])
		{
			char c = argv[i][j];
			if (c == ' ' || c == '\t')
			{
				in_word = 0;
				write(1, &c, 1);
			}
			else
			{
				if (!in_word)
				{
					if (c >= 'a' && c <= 'z')
						c -= 32;
					in_word = 1;
				}
				else if (c >= 'A' && c <= 'Z')
					c += 32;
				write(1, &c, 1);
			}
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
