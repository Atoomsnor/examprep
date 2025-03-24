#include <unistd.h>
#include <stdio.h>

// int ft_atoi(const char *str)
// {
// 	int res = 0;
// 	int s = 1;
	
// 	while ((*str >= 9 && *str <= 13) || *str == 32) // Skip whitespace
// 		str++;

// 	if (*str == '-') // Handle sign
// 	{
// 		s = -1;
// 		str++;
// 	}
// 	else if (*str == '+')
// 		str++;

// 	while (*str >= '0' && *str <= '9') // Convert digits
// 	{
// 		res = res * 10 + (*str - '0');
// 		str++;
// 	}

// 	return (res * s);
// }

// int	main(int argc, char **argv)
// {
// 	char	*str;

// 	str = argv[1];
// 	if (argc == 2)
// 	{
// 		printf("%i\n", ft_atoi(str));
// 	}
// 	return (0);
// }






// int	ft_atoi(const char *str)
// {
// 	int res = 0;
// 	int s = 1;

// 	while ((*str >= 9 && *str <= 13) || *str == 32)
// 		str++;
// 	if (*str == '-')
// 	{
// 		s = -1;
// 		str++;
// 	}
// 	else if (*str == '+')
// 		str++;
// 	while (*str >= '0' && *str <= '9')
// 	{
// 		res = res * 10;
// 		res = res + (*str - '0');
// 		str++;
// 	}
// 	return (res * s);
// }

// int	main(int argc, char **argv)
// {
// 	char	*str = argv[1];

// 	if (argc == 2)
// 	{
// 		printf("%i\n", ft_atoi(str));
// 	}
// 	return (0);
// }



// int	ft_atoi(const char *str)
// {
// 	int	res = 0;
// 	int	s = 1;

	// while ((*str >= 9 && *str <= 13) || *str == 32)
	// 	str++;
	// if (*str == '-')
	// {
	// 	s = -1;
	// 	str++;
	// }
	// else if (*str == '+')
	// 	str++;
// 	while (*str >= '0' && *str <= '9')
// 	{
// 		res = res * 10 +(*str - '0');
// 		str++;
// 	}
// 	return (res * s);
// }

int	ft_atoi(const char *str)
{
	int	res = 0;
	
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}


int	ft_atoi_base(const char *str, int base)
{
	int	res = 0;
	int	s = 1;
	int	val;

	while ((*str >= 9 && *str <= 13) || *str ==  32)
		str++;
	if (*str == '-')
	{
		s = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			val = *str - '0';
		else if (*str >= 'a' && *str <= 'f')
			val = *str - 'a' + 10;
		else if (*str >= 'A' && *str <= 'F')
			val = *str - 'A' + 10;
		else
			break;
		if (val >= base)
			break;
		res = res * base + val;
		str++;
	}
	return (res * s);
}

int	main(int argc, char **argv)
{
	int base = ft_atoi(argv[2]);
	if (base < 2 || base > 16) // Ensure valid base
		return (1);
	if (argc == 3)
		printf("%i\n", ft_atoi_base(argv[1], ft_atoi(argv[2])));
	return (0);
}




int	ft_atoi_base(const char *str, int base)
{
	int res = 0;
	int val = 0;

	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			val = *str - '0';
		else if (*str >= 'a' && *str <= 'f')
			val = *str - 'a' + 10;
		else if (*str >= 'A' && *str < 'F')
			val = *str - 'A' + 10;
		res = res * base + val;
	}
}
