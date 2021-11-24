#include "includes/minitalk.h"
#include <stdio.h>

int	send_data(int pid, char *s)
{
	int	bytepos;

	while (*s)
	{
		bytepos = -1;
		while (++bytepos < 8)
		{
			if (*s >> bytepos & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(50);
		}
		s++;
	}
	while (bytepos--)
	{
		kill(pid, SIGUSR1);
		usleep(10);
	}
	return (0);
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		printf("pid = %d s = %s\n", ft_atoi(av[1]), av[2]);
		send_data(ft_atoi(av[1]), av[2]);
	}
	return (0);
}
