#include <unistd.h>

// int is_palindrome(char *s, int start, int end)
// {
// 	while (start < end)
// 	{
// 		if (s[start] != s[end])  
// 			return 0;            
// 		start++;                 
// 		end--;                   
// 	}
// 	return 1;                    
// }

// void write_str(char *s, int len)
// {
// 	write(1, s, len);
// 	write(1, "\n", 1);
// }

// int main(int argc, char **argv)
// {
// 	if (argc != 2)
// 		return 1;

// 	char *str = argv[1];
// 	int len = 0; 
// 	int max_len = 0;
// 	int	pal_len = 0;
// 	int last_start = 0;
// 	int	i = 0;
// 	int	j = 0;

// 	while (str[len])
// 		len++;

// 	while (i < len)  
// 	{
// 		j = i + max_len;
// 		while (j < len)  
// 		{
// 			if (is_palindrome(str, i, j))  
// 			{
// 				pal_len = j - i + 1; 
// 				if (pal_len > max_len)  
// 				{
// 					max_len = pal_len;
// 					last_start = i;
// 				}
// 			}
// 			j++;
// 		}
// 		i++;
// 	}

// 	if (max_len > 0)  
// 		write_str(str + last_start, max_len);

// 	return 0;
// }



// void	putstr(char *str, int len)
// {
// 	write(1, str, len);
// 	write(1, "\n", 1);
// }

// int	is_palindrome(char *str, int i, int j)
// {
// 	while (i < j)
// 	{
// 		if (str[i] != str[j])
// 			return (0);
// 		i++;
// 		j--;
// 	}
// 	return (1);
// }

// int	main(int argc, char **argv)
// {
// 	if (argc != 2)
// 		return (0);
	
// 	char	*str = argv[1];
// 	int		len = 0;
// 	int		pal_len = 0;
// 	int		biggest_len = 0;
// 	int		start_point = 0;
	
// 	while (str[len])
// 		len++;
	
// 	int	i = 0;
// 	while (i < len)
// 	{
// 		int	j = i;
// 		while(j < len)
// 		{
// 			if (is_palindrome(str, i, j))
// 			{
// 				pal_len = j - i + 1;
// 				if (pal_len >= biggest_len)
// 				{
// 					biggest_len = pal_len;
// 					start_point = i;
// 				}
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (biggest_len > 0)
// 		putstr(str + start_point, biggest_len);
// 	return (0);
// }



void	ft_putstr(char *str, int len)
{
	write(1, str, len);
	write(1, "\n", 1);
}

int	is_palindrome(char *str, int start, int end)
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

int	main(int argc, char **argv)
{
	char	*str = argv[1];
	int		start;
	int		end;
	int		strlen = 0;
	int		biggest_pal = 0;
	int		from = 0;
	int		new_pal = 0;

	if (argc != 2)
		return (0);
	while (str[strlen])
		strlen++;
	start = 0;
	while (start < strlen)
	{
		end = start;
		while (end < strlen)
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





