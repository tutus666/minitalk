#include "../includes/minitalk.h"

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = -1;
	while (str[++n])
		;
	return (n);
}
