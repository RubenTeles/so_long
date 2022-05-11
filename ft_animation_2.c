/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:57:29 by rteles            #+#    #+#             */
/*   Updated: 2022/05/10 22:24:55 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
		//img->relative_path = "./Frames/Veemon/V_A0.xpm";
		//img->img = mlx_xpm_file_to_image(vars->ptr, img->relative_path, &img->img_width, &img->img_height);
		//mlx_put_image_to_window(vars->ptr, vars->win, img->img, 0, 0);
/*	int w;
	int y;*/
//	img = mlx_xpm_file_to_image;
//	mlx_put_image_to_window;

//	mlx_hook(mlx.win, 2, 1L << 5, close, &mlx);
	//printf("Inseriste a Tecla %i \n", keycode);*/

/*	img.img = mlx_new_image(mlx.ptr, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	my_mlx_pixel_put(&img, 300, 300, 0x00FF0000);*/