#include <unistd.h>

void ft_putstr(char *str, int len)
{
	write(1, str, len);
	write(1, "\n", 1);
}

int is_palindrome(char *str, int start, int end)
{
	while (start < end)
	{
		if (str[start] != str[end])
			return (0);
		start++;
		end--;
	}
	return (1);
}

int main(int argc, char **argv)
{
	char	*str = argv[1];
	int	start = 0; int end = 0;
	int	len = 0; int biggest_pal = 0;
	int from = 0; int new_pal = 0;
	// if (ac != 3) write/return 0
	while (start < len)
	{
		end = start;
		while (end < len)
		{
			if (is_palindrome(str, start, end))
			{
				new_pal = end - start + 1;
				if (new_pal >= biggest_pal)
				{
					biggest_pal = new_pal;
					from = start;
				}
			}
			end++;
		}
		start++;
	}
	if (biggest_pal > 0)
		ft_putstr(str + from, biggest_pal);
	return (0);
}
