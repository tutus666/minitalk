#include "includes/minitalk.h"

static int	send_data(int pid, char *s)
{
	int	bit;

	while (*s)
	{
		bit = -1;
		while (++bit < 8)
		{
			if (*s >> bit & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(50);
		}
		s++;
	}
	while (bit--)
	{
		kill(pid, SIGUSR1);
		usleep(10);
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		if (ft_atoi(av[1]) > 0 && kill(ft_atoi(av[1]), 0) == 0)
			send_data(ft_atoi(av[1]), av[2]);
		else
		{
			ft_putstr_fd("Error: invalid PID\n", 1);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		ft_putstr_fd("Error: invalid number of arguments\n", 1);
		exit(EXIT_FAILURE);
	}
	return (0);
}
