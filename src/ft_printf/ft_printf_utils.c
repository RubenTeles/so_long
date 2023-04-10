/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:42:59 by rteles            #+#    #+#             */
/*   Updated: 2023/04/10 17:35:31 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *str)
{
	int	i;
	int	len;

	len = 0;
	if (!str)
	{
		len = write(1, "(null)", 6);
		return (len);
	}
	i = ft_strlen(str);
	len = write(1, str, i);
	return (len);
}

int	ft_print_int(int n)
{
	int		i;
	char	*str;

	str = ft_itoa(n);
	i = ft_print_string(str);
	free(str);
	return (i);
}

int	ft_hexadecimal(unsigned long long hx, char *base, int lap)
{
	int		v;
	int		r;

	v = 0;
	r = 0;
	while (lap > v)
	{
		r = hx % 16;
		hx /= 16;
		v++;
	}
	ft_print_char(base[r]);
	return (1);
}

int	ft_print_hx(unsigned long long hx, char *base)
{
	int					i;
	int					lap;
	int					r;
	unsigned long long	n;

	lap = 0;
	n = hx;
	r = -1;
	i = 0;
	while (n >= 16)
	{
		r = n % 16;
		n /= 16;
		lap++;
	}
	i += ft_print_char(base[n]);
	if (r >= 0)
		i += ft_print_char(base[r]);
	while (--lap > 0)
		i += ft_hexadecimal(hx, base, lap);
	return (i);
}

int	ft_print_pointer(unsigned long long pointer)
{
	int	i;

	i = 0;
	if (!pointer)
		return (ft_print_string("0x0"));
	else
		i = ft_print_string("0x");
	i += ft_print_hx(pointer, "0123456789abcdef");
	return (i);
}
