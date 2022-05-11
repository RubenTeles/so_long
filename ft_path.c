/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:32:56 by rteles            #+#    #+#             */
/*   Updated: 2022/05/11 21:06:16 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_so_long.h"

void	path_player2(t_all *a)
{
	a->j.w0 = mlx_xpm_file_to_image(a->ptr, "./F/J/W0.xpm", &a->wth, &a->hgt);
	a->j.w1 = mlx_xpm_file_to_image(a->ptr, "./F/J/W1.xpm", &a->wth, &a->hgt);
	a->j.w2 = mlx_xpm_file_to_image(a->ptr, "./F/J/W2.xpm", &a->wth, &a->hgt);
	a->j.w3 = mlx_xpm_file_to_image(a->ptr, "./F/J/W3.xpm", &a->wth, &a->hgt);
	a->j.a0 = mlx_xpm_file_to_image(a->ptr, "./F/J/A0.xpm", &a->wth, &a->hgt);
	a->j.a1 = mlx_xpm_file_to_image(a->ptr, "./F/J/A1.xpm", &a->wth, &a->hgt);
	a->j.a2 = mlx_xpm_file_to_image(a->ptr, "./F/J/A2.xpm", &a->wth, &a->hgt);
	a->j.a3 = mlx_xpm_file_to_image(a->ptr, "./F/J/A3.xpm", &a->wth, &a->hgt);
	a->j.s0 = mlx_xpm_file_to_image(a->ptr, "./F/J/S0.xpm", &a->wth, &a->hgt);
	a->j.s1 = mlx_xpm_file_to_image(a->ptr, "./F/J/S1.xpm", &a->wth, &a->hgt);
	a->j.s2 = mlx_xpm_file_to_image(a->ptr, "./F/J/S2.xpm", &a->wth, &a->hgt);
	a->j.s3 = mlx_xpm_file_to_image(a->ptr, "./F/J/S3.xpm", &a->wth, &a->hgt);
	a->j.d0 = mlx_xpm_file_to_image(a->ptr, "./F/J/D0.xpm", &a->wth, &a->hgt);
	a->j.d1 = mlx_xpm_file_to_image(a->ptr, "./F/J/D1.xpm", &a->wth, &a->hgt);
	a->j.d2 = mlx_xpm_file_to_image(a->ptr, "./F/J/D2.xpm", &a->wth, &a->hgt);
	a->j.d3 = mlx_xpm_file_to_image(a->ptr, "./F/J/D3.xpm", &a->wth, &a->hgt);
	a->j.x = mlx_xpm_file_to_image(a->ptr, "./F/J/X.xpm", &a->wth, &a->hgt);
	a->j.key = 'S';
	a->j.player = 0;
}

void	path_player(t_all *a)
{
	a->t.w0 = mlx_xpm_file_to_image(a->ptr, "./F/T/W0.xpm", &a->wth, &a->hgt);
	a->t.w1 = mlx_xpm_file_to_image(a->ptr, "./F/T/W1.xpm", &a->wth, &a->hgt);
	a->t.w2 = mlx_xpm_file_to_image(a->ptr, "./F/T/W2.xpm", &a->wth, &a->hgt);
	a->t.w3 = mlx_xpm_file_to_image(a->ptr, "./F/T/W3.xpm", &a->wth, &a->hgt);
	a->t.a0 = mlx_xpm_file_to_image(a->ptr, "./F/T/A0.xpm", &a->wth, &a->hgt);
	a->t.a1 = mlx_xpm_file_to_image(a->ptr, "./F/T/A1.xpm", &a->wth, &a->hgt);
	a->t.a2 = mlx_xpm_file_to_image(a->ptr, "./F/T/A2.xpm", &a->wth, &a->hgt);
	a->t.a3 = mlx_xpm_file_to_image(a->ptr, "./F/T/A3.xpm", &a->wth, &a->hgt);
	a->t.s0 = mlx_xpm_file_to_image(a->ptr, "./F/T/S0.xpm", &a->wth, &a->hgt);
	a->t.s1 = mlx_xpm_file_to_image(a->ptr, "./F/T/S1.xpm", &a->wth, &a->hgt);
	a->t.s2 = mlx_xpm_file_to_image(a->ptr, "./F/T/S2.xpm", &a->wth, &a->hgt);
	a->t.s3 = mlx_xpm_file_to_image(a->ptr, "./F/T/S3.xpm", &a->wth, &a->hgt);
	a->t.d0 = mlx_xpm_file_to_image(a->ptr, "./F/T/D0.xpm", &a->wth, &a->hgt);
	a->t.d1 = mlx_xpm_file_to_image(a->ptr, "./F/T/D1.xpm", &a->wth, &a->hgt);
	a->t.d2 = mlx_xpm_file_to_image(a->ptr, "./F/T/D2.xpm", &a->wth, &a->hgt);
	a->t.d3 = mlx_xpm_file_to_image(a->ptr, "./F/T/D3.xpm", &a->wth, &a->hgt);
	a->t.x = mlx_xpm_file_to_image(a->ptr, "./F/T/X.xpm", &a->wth, &a->hgt);
	a->t.key = 'S';
	a->t.player = 0;
	a->status_player = 1;
	path_player2(a);
}

void	path_images(t_all *a)
{
	path_player(a);
	a->f.i0 = mlx_xpm_file_to_image(a->ptr, "./F/E/0.xpm", &a->wth, &a->hgt);
	a->f.i1 = mlx_xpm_file_to_image(a->ptr, "./F/E/1.xpm", &a->wth, &a->hgt);
	a->f.i2 = mlx_xpm_file_to_image(a->ptr, "./F/E/2.xpm", &a->wth, &a->hgt);
	a->f.i3 = mlx_xpm_file_to_image(a->ptr, "./F/E/3.xpm", &a->wth, &a->hgt);
	a->f.k = mlx_xpm_file_to_image(a->ptr, "./F/E/k.xpm", &a->wth, &a->hgt);
	a->m.dgi = mlx_xpm_file_to_image(a->ptr, "./F/M/dgi.xpm", &a->wth, &a->hgt);
	a->m.pws = mlx_xpm_file_to_image(a->ptr, "./F/M/pws.xpm", &a->wth, &a->hgt);
	a->m.tim = mlx_xpm_file_to_image(a->ptr, "./F/M/tim.xpm", &a->wth, &a->hgt);
	a->m.eg0 = mlx_xpm_file_to_image(a->ptr, "./F/M/eg0.xpm", &a->wth, &a->hgt);
	a->m.eg1 = mlx_xpm_file_to_image(a->ptr, "./F/M/eg1.xpm", &a->wth, &a->hgt);
	a->m.eg2 = mlx_xpm_file_to_image(a->ptr, "./F/M/eg2.xpm", &a->wth, &a->hgt);
	a->m.p0 = mlx_xpm_file_to_image(a->ptr, "./F/M/p0.xpm", &a->wth, &a->hgt);
	a->m.p1 = mlx_xpm_file_to_image(a->ptr, "./F/M/p1.xpm", &a->wth, &a->hgt);
	a->b.w0 = mlx_xpm_file_to_image(a->ptr, "./F/B/w0.xpm", &a->wth, &a->hgt);
	a->b.w1 = mlx_xpm_file_to_image(a->ptr, "./F/B/w1.xpm", &a->wth, &a->hgt);
	a->b.w2 = mlx_xpm_file_to_image(a->ptr, "./F/B/w2.xpm", &a->wth, &a->hgt);
	a->b.w3 = mlx_xpm_file_to_image(a->ptr, "./F/B/w3.xpm", &a->wth, &a->hgt);
	a->b.b0 = mlx_xpm_file_to_image(a->ptr, "./F/B/b0.xpm", &a->wth, &a->hgt);
	a->b.b1 = mlx_xpm_file_to_image(a->ptr, "./F/B/b1.xpm", &a->wth, &a->hgt);
	a->m.paws = 0;
	a->m.coins = 0;
	a->m.coins_max = 0;
	a->m.portal = 0;
	a->m.lives = 3;
}
