/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:57:29 by rteles            #+#    #+#             */
/*   Updated: 2022/05/07 19:07:18 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_so_long.h"

int	put_img(t_all all, void *img, int x, int y)
{
	mlx_put_image_to_window(all.ptr, all.win, img, x, y);
	return (1);
}

int	animation_wall(t_all *all, int x, int y, int count)
{
	if (count == 0)
		put_img(*all, all->b.w0, all->wth * x, all->hgt * y);
	else if (count == 5000)
		put_img(*all, all->b.w1, all->wth * x, all->hgt * y);
	else if (count == 10000)
		put_img(*all, all->b.w2, all->wth * x, all->hgt * y);
	else if (count == 15000)
		put_img(*all, all->b.w3, all->wth * x, all->hgt * y);
	return (0);
}

int	animation_back(t_all *all, int x, int y, int count)
{
	if ((count == 5000) || (count == 15000))
		put_img(*all, all->b.b0, all->wth * x, all->hgt * y);
	else if ((count == 0) || (count == 10000))
		put_img(*all, all->b.b1, all->wth * x, all->hgt * y);
	return (0);
}

int	animation_egg(t_all *all, int x, int y, int count)
{
	if ((count == 5000) || (count == 15000))
		put_img(*all, all->m.eg0, all->wth * x, all->hgt * y);
	else if ((count == 0) || (count == 10000))
		put_img(*all, all->m.eg1, all->wth * x, all->hgt * y);
	return (0);
}

int	animation_portal(t_all *all, int x, int y, int count)
{
	if ((count == 5000) || (count == 15000))
		put_img(*all, all->m.p0, all->wth * x, all->hgt * y);
	else if ((count == 0) || (count == 10000))
		put_img(*all, all->m.p1, all->wth * x, all->hgt * y);
	return (0);
}
