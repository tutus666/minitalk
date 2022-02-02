/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armansuy <armansuy@student.42nice.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:12:26 by armansuy          #+#    #+#             */
/*   Updated: 2021/11/30 16:48:47 by armansuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

int	g_wait = 0;

static void	send_data_end(int pid, int bit)
{
	while (bit--)
	{
		g_wait = 1;
		kill(pid, SIGUSR1);
		while (g_wait)
			;
	}
	ft_putstr_fd("Data to server ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd(" has been sent !\n", 1);
}

static void	send_data(int pid, char *s)
{
	int	bit;

	while (*s)
	{
		bit = -1;
		while (++bit < 8)
		{
			g_wait = 1;
			usleep(50);
			if (*s >> bit & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			while (g_wait)
				;
		}
		s++;
	}
	send_data_end(pid, bit);
}

static void	signal_handler(int sig)
{
	if (sig == SIGUSR2)
		g_wait = 0;
}

static void	check_args(char **av)
{
	if (ft_str_is_digit(av[1]) && ft_atoi(av[1]) > 0 \
				&& kill(ft_atoi(av[1]), 0) == 0)
		send_data(ft_atoi(av[1]), av[2]);
	else
	{
		ft_putstr_fd("Error: invalid PID\n", 1);
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	struct sigaction	s;

	s.sa_handler = signal_handler;
	sigemptyset(&s.sa_mask);
	if (sigaction(SIGUSR2, &s, NULL) < 0)
	{
		ft_putstr_fd("Error : sigaction failed\n", 1);
		exit(EXIT_FAILURE);
	}
	if (ac == 3)
		check_args(av);
	else
	{
		ft_putstr_fd("Error: invalid number of arguments\n", 1);
		exit(EXIT_FAILURE);
	}
	return (0);
}
