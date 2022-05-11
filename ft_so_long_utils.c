/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:57:29 by rteles            #+#    #+#             */
/*   Updated: 2022/05/12 00:15:09 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	put_images_2(t_all *all, int x, int y, int count)
{
	while (x <= all->max_x && all->game[y][x])
	{
		if (all->game[y][x] == '1')
			animation_wall(all, x, y, count);
		else
		{
			animation_back(all, x, y, count);
			if (all->game[y][x] == 'P')
			{
				all->t.pos_x = x;
				all->t.pos_y = y;
				all->frst_pos_x = x;
				all->frst_pos_y = y;
				all->game[y][x] = '0';
			}
			else if (all->game[y][x] == 'C')
				animation_egg(all, x, y, count);
			else if (all->game[y][x] == 'E' &&
				(all->m.coins == all->m.coins_max))
				animation_portal(all, x, y, count);
			else if (all->game[y][x] == 'I')
				animation_enemy(all, x, y, count);
		}
		x++;
	}
}

int	put_images(t_all *all)
{
	static int	count = 0;
	int			y;

	y = 0;
	if (count == 0 || count == 5000 || count == 10000 || count == 15000)
	{
		while ((y <= all->max_y))
		{
			put_images_2(all, 0, y, count);
			y++;
		}
		animation_player(all, all->t.pos_x, all->t.pos_y, count);
	}
	count++;
	animation_time(all, count);
	if (count == 19999)
		count = 0;
	return (0);
}
