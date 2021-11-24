#include "includes/minitalk.h"

static	int	add_char_to_str(char c, int byte)
{
	static char	*s;

	if (!byte)
	{
		s = malloc(2);
		if (!s)
			return (-1);
		s[byte] = c;
		s[byte + 1] = 0;
	}
	else
	{
		s = ft_strjoin(s, c);
		if (!s)
			return (-1);
	}
	if (!s[byte])
	{
		printf("%s\n", s);
		free(s);
	}
	return (0);
}

static void	signal_handler(int sig)
{
	static int	bit = 0;
	static int	byte = 0;
	char	c;

	if (!bit)
		c = 0;
	if (sig == SIGUSR2)
		c |= 1 << bit;
	if (++bit && bit == 8)
	{
		bit = 0;
		add_char_to_str(c, byte);
		if (!c)
			byte = 0;
		else
			byte++;
	}
}

int		main()
{
	struct sigaction s;

	s.sa_handler = signal_handler;
	sigemptyset(&s.sa_mask);
	s.sa_flags = 0;
	printf("Server's PID : %d\n", getpid());
	sigaction(SIGUSR1, &s, NULL);
	sigaction(SIGUSR2, &s, NULL);
	while (1)
		pause();
	return (0);
}
