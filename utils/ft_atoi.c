int	ft_atoi(const char *str)
{
	int	sign;
	int	nb;

	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	nb = 0;
	while (*str >= '0' && *str <= '9')
		nb = nb * 10 - 48 + *str++;
	return (nb * sign);
}
