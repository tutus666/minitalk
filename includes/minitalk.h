#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>

void	ft_putnbr(int n);
int		ft_atoi(const char *str);
char	*ft_strjoin(const char *s, const char c);
size_t	ft_strlen(const char *str);
#endif
