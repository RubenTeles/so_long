/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:57:29 by rteles            #+#    #+#             */
/*   Updated: 2022/05/10 21:07:19 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_so_long.h"

//---------------------MENU---------------------

void	put_str(t_all *all, int number, int color, int x, int incremento)
{
	char	*str;
	
	str = ft_itoa(number - incremento);
	mlx_string_put(all->ptr, all->win, x,
			all->hgt * (all->max_y + 1.5), 0x00000000, str);
	free(str);
	str = ft_itoa(number);
	mlx_string_put(all->ptr, all->win, x,
			all->hgt * (all->max_y + 1.5), color, str);
	free(str);
}

void	put_menu(t_all *all, char *str)
{
	int	collor;

	collor = 0x00FFFFFF;
	if (all->m.coins == all->m.coins_max)
		collor = 0x0000FF00;
	put_img(*all, all->m.tim, all->wth * 0,	all->hgt * (all->max_y + 1));
	put_img(*all, all->m.dgi, all->wth * 3,	all->hgt * (all->max_y + 1));
	put_str(all, all->m.coins, collor, all->wth *  4.5, 1);
	mlx_string_put(all->ptr, all->win, all->wth *  5,
			all->hgt * (all->max_y + 1.5), collor, "/ ");
	put_str(all, all->m.coins_max, collor, all->wth *  5.5, 1);
	put_img(*all, all->m.pws, all->wth * 7,	all->hgt * (all->max_y + 1));
	put_str(all, all->m.paws, 0x00FFFFFF, all->wth *  8.5, 1);
	
	//put_str(all, all->t.lives, 0x00FFFFFF, all->wth *  8.5, 1);
}

void	animation_time(t_all *all, int count)
{
	if ((count == 0) || (count == 10000))
	{
		if (all->m.time == -1)
			ft_lives(all);
		else if (all->m.time > 10)
		put_str(all, all->m.time, 0x00FFFFFF, all->wth *  1.5, -1);
		else if (all->m.time <= 10)
			put_str(all, all->m.time, 0x00FF0000, all->wth *  1.5, -1);
		all->m.time--;
	}
}

void	animation_live(t_all *all, int live)//Por fazer
{
	if (live == -1)
		end_game(all);
	else if (all->m.time > 10)
	put_str(all, all->m.time, 0x00FFFFFF, all->wth *  1.5, -1);
	else if (all->m.time <= 10)
		put_str(all, all->m.time, 0x00FF0000, all->wth *  1.5, -1);
	all->m.time--;
}
