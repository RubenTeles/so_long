/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_decimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:45:36 by rteles            #+#    #+#             */
/*   Updated: 2022/01/09 00:36:14 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_power2(unsigned int n)
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

char	*ft_unsignedmkitoax(unsigned int n, int i, int h)
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

char	*ft_itoa_unsigned(unsigned int n)
{
	return (ft_unsignedmkitoax(n, ft_power2(n), 0));
}

int	ft_print_unsigned_decimal(unsigned int un)
{
	int				i;
	unsigned int	n;
	char			*str;

	n = (unsigned int)un;
	str = NULL;
	str = ft_itoa_unsigned(n);
	i = ft_print_string(str);
	free(str);
	return (i);
}
