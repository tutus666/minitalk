#include "../includes/minitalk.h"

static void	add_char(char c, int byte)
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
		ft_putstr_fd(s, 1);
		ft_putstr_fd("\n", 1);
		free(s);
	}
}

static void	signal_handler(int sig)
{
	static int	bit = 0;
	static int	byte = 0;
	char		c;

	if (!bit)
		c = 0;
	if (sig == SIGUSR2)
		c |= 1 << bit;
	if (++bit && bit == 8)
	{
		bit = 0;
		add_char(c, byte);
		byte++;
		if (!c)
			byte = 0;
	}
}

int	main(void)
{
	struct sigaction	s;

	s.sa_handler = signal_handler;
	sigemptyset(&s.sa_mask);
	s.sa_flags = 0;
	ft_putstr_fd("Server's PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	sigaction(SIGUSR1, &s, NULL);
	sigaction(SIGUSR2, &s, NULL);
	while (1)
		pause();
	return (0);
}
