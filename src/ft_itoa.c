/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:18:40 by rteles            #+#    #+#             */
/*   Updated: 2022/05/06 08:56:42 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_power(int n)
{
	int	p;

	p = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		p++;
	}
	return (p);
}

char	*ft_mkitoa(int n, int i, int h)
{
	char	*str;

	str = (char *)malloc((i + 1) * sizeof(char));
	if (str == 0)
		return (0);
	str[i] = '\0';
	i--;
	if (h == 2)
	{
		str[i] = '8';
		h--;
		i--;
	}
	while (0 + h <= i)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	if (h == 1)
		str[i] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	if (n < 0)
	{
		n *= -1;
		if (n == -2147483648)
			return (ft_mkitoa(214748364, 11, 2));
		return (ft_mkitoa(n, ft_power(n) + 1, 1));
	}
	else
		return (ft_mkitoa(n, ft_power(n), 0));
}
