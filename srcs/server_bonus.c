/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armansuy <armansuy@student.42nice.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:12:13 by armansuy          #+#    #+#             */
/*   Updated: 2021/11/30 16:51:01 by armansuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

static void	add_char(char c, int byte, siginfo_t *siginfo)
{
	static char	*s;

	if (!byte)
	{
		s = malloc(2);
		if (!s)
			exit(EXIT_FAILURE);
		s[byte] = c;
		s[byte + 1] = 0;
	}
	else
	{
		s = ft_strjoin(s, c);
		if (!s)
			exit(EXIT_FAILURE);
	}
	if (!s[byte])
	{
		ft_putstr_fd("Client ", 1);
		ft_putnbr_fd(siginfo->si_pid, 1);
		ft_putstr_fd(" : ", 1);
		ft_putstr_fd(s, 1);
		ft_putstr_fd("\n", 1);
		free(s);
	}
}

static void	signal_handler(int sig, siginfo_t *siginfo, void *context)
{
	static int	bit = 0;
	static int	byte = 0;
	char		c;

	(void)context;
	if (!bit)
		c = 0;
	if (sig == SIGUSR2)
		c |= 1 << bit;
	if (++bit && bit == 8)
	{
		bit = 0;
		add_char(c, byte, siginfo);
		byte++;
		if (!c)
			byte = 0;
	}
	kill(siginfo->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	s;

	s.sa_sigaction = signal_handler;
	s.sa_flags = SA_SIGINFO;
	sigemptyset(&s.sa_mask);
	ft_putstr_fd("Server's PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	if (sigaction(SIGUSR1, &s, NULL) < 0 || sigaction(SIGUSR2, &s, NULL) < 0)
	{
		ft_putstr_fd("Error : sigaction failed", 1);
		exit(EXIT_FAILURE);
	}
	while (1)
		pause();
	return (0);
}
