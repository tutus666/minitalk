/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armansuy <armansuy@student.42nice.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:37:41 by armansuy          #+#    #+#             */
/*   Updated: 2021/11/29 14:37:42 by armansuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
