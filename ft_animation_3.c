/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:57:29 by rteles            #+#    #+#             */
/*   Updated: 2022/05/07 19:28:55 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_so_long.h"

void	animation_player_walk_w(t_all *all, int x, int y, int count)
{
	put_img(*all, all->b.b0, all->wth * x, all->hgt * (y - 0.33));
	put_img(*all, all->t.w2, all->wth * x, all->hgt * (y - 0.33));
	put_img(*all, all->b.b0, all->wth * x, all->hgt * (y - 0.66));
	put_img(*all, all->t.w3, all->wth * x, all->hgt * (y - 0.66));
	animation_player_w(all, x, y - 1, 0);
}

void	animation_player_walk_a(t_all *all, int x, int y, int count)
{
	put_img(*all, all->b.b0, all->wth * (x - 0.33), all->hgt * y);
	put_img(*all, all->t.a2, all->wth * (x - 0.33), all->hgt * y);
	put_img(*all, all->b.b0, all->wth * (x - 0.66), all->hgt * y);
	put_img(*all, all->t.a3, all->wth * (x - 0.66), all->hgt * y);
	animation_player_a(all, x - 1, y, 0);
}

void	animation_player_walk_s(t_all *all, int x, int y, int count)
{
	put_img(*all, all->b.b0, all->wth * x, all->hgt * (y + 0.33));
	put_img(*all, all->t.s2, all->wth * x, all->hgt * (y + 0.33));
	put_img(*all, all->b.b0, all->wth * x, all->hgt * (y + 0.66));
	put_img(*all, all->t.s3, all->wth * x, all->hgt * (y + 0.66));
	animation_player_s(all, x, y + 1, 0);
}

void	animation_player_walk_d(t_all *all, int x, int y, int count)
{
	put_img(*all, all->b.b0, all->wth * (x + 0.33), all->hgt * y);
	put_img(*all, all->t.d2, all->wth * (x + 0.33), all->hgt * y);
	put_img(*all, all->b.b0, all->wth * (x + 0.66), all->hgt * y);
	put_img(*all, all->t.d3, all->wth * (x + 0.66), all->hgt * y);
	animation_player_d(all, x + 1, y, 0);
}

void	animation_enemy(t_all *all, int x, int y, int count)
{
	put_img(*all, all->b.b0, all->wth * x, all->hgt * y);
	if (count == 0)
		put_img(*all, all->f.i0, all->wth * x, all->hgt * y);
	else if (count == 5000)
		put_img(*all, all->f.i1, all->wth * x, all->hgt * y);
	else if (count == 10000)
		put_img(*all, all->f.i2, all->wth * x, all->hgt * y);
	else if (count == 15000)
		put_img(*all, all->f.i3, all->wth * x, all->hgt * y);
}
