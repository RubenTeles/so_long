/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:28:00 by rteles            #+#    #+#             */
/*   Updated: 2022/05/11 23:09:35 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../ft_so_long.h"

int	ft_print_char(char c);
int	ft_printf(const char *str, ...);
int	ft_print_string(char *str);
int	ft_print_int(int n);
int	ft_print_unsigned_decimal(unsigned int un);
int	ft_print_hx(unsigned long long hx, char *base);
int	ft_print_pointer(unsigned long long pointer);

#endif