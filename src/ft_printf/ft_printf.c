/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:21:21 by rteles            #+#    #+#             */
/*   Updated: 2023/04/10 17:34:20 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	return write(1, &c, 1);
}

int	ft_makestring(const char type, va_list args)
{
	int	len;

	len = 0;
	if (type == 'c')
		len = ft_print_char(va_arg(args, int));
	else if (type == 'p')
		len = ft_print_pointer(va_arg(args, unsigned long long));
	else if (type == 's')
		len = ft_print_string(va_arg(args, char *));
	else if (type == 'd' || type == 'i')
		len = ft_print_int(va_arg(args, int));
	else if (type == 'u')
		len = ft_print_unsigned_decimal(va_arg(args, unsigned int));
	else if (type == 'x')
		len = ft_print_hx(va_arg(args, unsigned int), "0123456789abcdef");
	else if (type == 'X')
		len = ft_print_hx(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (type == '%')
		len = ft_print_char('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	if (!str)
		return (0);
	va_start(args, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_makestring(str[i + 1], args);
			i++;
		}
		else
			len += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

/*%c print a single character.
• %s print a string of characters.
• %p The void * pointer argument is printed in hexadecimal.
• %d print a decimal (base 10) number.
• %i print an integer in base 10.
• %u print an unsigned decimal (base 10) number.
• %x print a number in hexadecimal (base 16), with lowercase.
• %X print a number in hexadecimal (base 16), with uppercase.
• %% print a percent sign.*/