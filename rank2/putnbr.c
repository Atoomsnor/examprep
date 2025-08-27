#include <unistd.h>

void	putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}