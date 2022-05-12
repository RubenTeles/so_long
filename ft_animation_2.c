/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:57:29 by rteles            #+#    #+#             */
/*   Updated: 2022/05/12 16:49:02 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	animation_player_w(t_all *all, int x, int y, int count)
{
	if ((count == 5000) || (count == 15000))
		put_img(*all, all->t.w0, all->wth * x, all->hgt * y);
	else if ((count == 0) || (count == 10000))
		put_img(*all, all->t.w1, all->wth * x, all->hgt * y);
}

void	animation_player_a(t_all *all, int x, int y, int count)
{
	if ((count == 5000) || (count == 15000))
		put_img(*all, all->t.a0, all->wth * x, all->hgt * y);
	else if ((count == 0) || (count == 10000))
		put_img(*all, all->t.a1, all->wth * x, all->hgt * y);
}

void	animation_player_s(t_all *all, int x, int y, int count)
{
	if ((count == 5000) || (count == 15000))
		put_img(*all, all->t.s0, all->wth * x, all->hgt * y);
	else if ((count == 0) || (count == 10000))
		put_img(*all, all->t.s1, all->wth * x, all->hgt * y);
}

void	animation_player_d(t_all *all, int x, int y, int count)
{
	if ((count == 5000) || (count == 15000))
		put_img(*all, all->t.d0, all->wth * x, all->hgt * y);
	else if ((count == 0) || (count == 10000))
		put_img(*all, all->t.d1, all->wth * x, all->hgt * y);
}

int	animation_player(t_all *all, int x, int y, int count)
{
	if (count == 0)
		put_img(*all, all->b.b0, all->wth * x, all->hgt * y);
	if (all->t.key == 'W')
		animation_player_w(all, x, y, count);
	else if (all->t.key == 'A')
		animation_player_a(all, x, y, count);
	else if (all->t.key == 'S')
		animation_player_s(all, x, y, count);
	else if (all->t.key == 'D')
		animation_player_d(all, x, y, count);
	else if (all->t.key == 'X')
		put_img(*all, all->t.x, all->wth * x, all->hgt * y);
	return (0);
}
