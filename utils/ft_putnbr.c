#include "../includes/minitalk.h"

void	ft_putnbr(int n)
{
	char			c;
	unsigned int	nb;

	nb = n;
	if (n < 0)
	{
		write(1, "-", 1);
		nb = -n;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
}
