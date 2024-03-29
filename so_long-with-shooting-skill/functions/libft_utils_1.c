/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:03:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len += 1;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		rem;
	int		len;
	char	*str;
	int		sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	len = ft_numlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (--len >= 0)
	{
		rem = n % 10;
		n = n / 10;
		if (rem < 0)
			rem = -rem;
		str[len] = rem + '0';
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

void	ft_putnmb(int n)
{
	unsigned int	x;
	char			c;

	x = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		x = -n;
	}
	else
		x = n;
	if (x > 9)
	{
		ft_putnmb(x / 10);
		ft_putnmb(x % 10);
	}
	else
	{
		c = x + '0';
		write(1, &c, 1);
	}
}
