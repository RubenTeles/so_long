/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:57:29 by rteles            #+#    #+#             */
/*   Updated: 2022/05/11 15:17:48 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_so_long.h"

void	animation_player2_w(t_all *all, int x, int y, int count)
{
	if ((count == 5000) || (count == 15000))
		put_img(*all, all->j.w0, all->wth * x, all->hgt * y);
	else if ((count == 0) || (count == 10000))
		put_img(*all, all->j.w1, all->wth * x, all->hgt * y);
}

void	animation_player2_a(t_all *all, int x, int y, int count)
{
	if ((count == 5000) || (count == 15000))
		put_img(*all, all->j.a0, all->wth * x, all->hgt * y);
	else if ((count == 0) || (count == 10000))
		put_img(*all, all->j.a1, all->wth * x, all->hgt * y);
}

void	animation_player2_s(t_all *all, int x, int y, int count)
{
	if ((count == 5000) || (count == 15000))
		put_img(*all, all->j.s0, all->wth * x, all->hgt * y);
	else if ((count == 0) || (count == 10000))
		put_img(*all, all->j.s1, all->wth * x, all->hgt * y);
}

void	animation_player2_d(t_all *all, int x, int y, int count)
{
	if ((count == 5000) || (count == 15000))
		put_img(*all, all->j.d0, all->wth * x, all->hgt * y);
	else if ((count == 0) || (count == 10000))
		put_img(*all, all->j.d1, all->wth * x, all->hgt * y);
}

int	animation_player2(t_all *all, int x, int y, int count)
{
	if (all->status_player == 1)
	{
		animation_player(all, x, y, count);
		return (0);
	}
	if (count == 0)
		put_img(*all, all->b.b0, all->wth * x, all->hgt * y);
	if (all->j.key == 'W')
		animation_player2_w(all, x, y, count);
	else if (all->j.key == 'A')
		animation_player2_a(all, x, y, count);
	else if (all->j.key == 'S')
		animation_player2_s(all, x, y, count);
	else if (all->j.key == 'D')
		animation_player2_d(all, x, y, count);
	else if (all->j.key == 'X')
		put_img(*all, all->j.x, all->wth * x, all->hgt * y);
	return (0);
}
