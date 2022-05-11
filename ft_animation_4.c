/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:57:29 by rteles            #+#    #+#             */
/*   Updated: 2022/05/12 00:01:40 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

//---------------------MENU---------------------

void	put_str(t_all *all, int number, int color, int x)
{
	char	*str;

	str = ft_itoa(number);
	mlx_string_put(all->ptr, all->win, x,
		all->hgt * (all->max_y + 1), color, str);
	free(str);
}

void	put_str_plus(t_all *all, int number, int color, int x)
{
	char	*str;

	str = ft_itoa(number + 1);
	mlx_string_put(all->ptr, all->win, x,
		all->hgt * (all->max_y + 1), 0x00000000, str);
	free(str);
	put_str(all, number, color, x);
}

void	put_str_less(t_all *all, int number, int color, int x)
{
	char	*str;

	str = ft_itoa(number - 1);
	mlx_string_put(all->ptr, all->win, x,
		all->hgt * (all->max_y + 1), 0x00000000, str);
	free(str);
	put_str(all, number, color, x);
}

void	put_menu(t_all *all)
{
	static int	i = 0;
	int			collor;

	collor = 0x00FFFFFF;
	if (all->m.time == ((all->m.coins_max + all->m.portal + all->t.player) * 3)
		&& i == 0)
	{
		i = 1;
		put_str_plus(all, all->m.time, 0x00FFFFFF, all->wth * 1.5);
	}
	if (all->m.coins == all->m.coins_max)
		collor = 0x0000FF00;
	put_img(*all, all->m.tim, all->wth * 0, all->hgt * (all->max_y + 1));
	put_img(*all, all->m.dgi, all->wth * 3, all->hgt * (all->max_y + 1));
	put_str_less(all, all->m.coins, collor, all->wth * 4.5);
	mlx_string_put(all->ptr, all->win, all->wth * 5,
		all->hgt * (all->max_y + 1), collor, "/ ");
	put_str_less(all, all->m.coins_max, collor, all->wth * 5.5);
	put_img(*all, all->m.pws, all->wth * 7, all->hgt * (all->max_y + 1));
	put_str_less(all, all->m.paws, 0x00FFFFFF, all->wth * 8.5);
	put_img(*all, all->m.liv, all->wth * 9.5, all->hgt * (all->max_y + 1));
	put_str_less(all, all->t.lives, 0x00FFFFFF, all->wth * 10.5);
}

void	animation_time(t_all *all, int count)
{
	if ((count == 0) || (count == 10000))
	{
		if (all->m.time == -1)
			ft_lives(all);
		else if (all->m.time > 10)
		{
			put_str_plus(all, all->m.time, 0x00000000, all->wth * 1.5);
			put_str_plus(all, all->m.time, 0x00FFFFFF, all->wth * 1.5);
		}
		else if (all->m.time <= 10)
		{
			put_str_plus(all, all->m.time, 0x00000000, all->wth * 1.5);
			put_str_plus(all, all->m.time, 0x00FF0000, all->wth * 1.5);
		}
		all->m.time--;
	}
}
