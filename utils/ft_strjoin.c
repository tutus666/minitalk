#include "../includes/minitalk.h"

char	*ft_strjoin(char const *s, char const c)
{
	size_t	n;
	char	*str;

	if (!s)
		return (0);
	str = malloc(ft_strlen(s) + 2);
	if (!str)
		return (0);
	n = -1;
	while (s[++n])
		str[n] = s[n];
	str[n] = c;
	str[n + 1] = 0;
	free((void *)s);
	return (str);
}
