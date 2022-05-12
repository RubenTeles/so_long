/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_method.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:57:29 by rteles            #+#    #+#             */
/*   Updated: 2022/05/12 17:50:38 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	end_game(t_all *all)
{
	int	y;

	mlx_clear_window(all->ptr, all->win);
	mlx_destroy_window(all->ptr, all->win);
	y = -1;
	while (all->game[++y])
		free(all->game[y]);
	free(all->game);
	all->argc_corrent += 1;
	if (all->t.lives > 0 && (all->argc_corrent <= all->argc_max))
	{
		ft_loop_game(all, all->argc_corrent, all->argv);
		return (0);
	}
	exit(0);
	return (0);
}

void	ft_lives(t_all *all)
{
	all->t.lives -= 1;
	if (all->t.lives > 0)
	{
		all->t.pos_x = all->frst_pos_x;
		all->t.pos_y = all->frst_pos_y;
		all->t.key = 'S';
		mlx_clear_window(all->ptr, all->win);
		all->m.time = (all->m.coins_max + all->m.portal + all->t.player) * 3;
		put_str_plus(all, all->t.lives, 0x00FFFFFF, all->wth * 10.5);
		put_str_plus(all, all->m.time, 0x00FFFFFF, all->wth * 1.5);
		if (all->count > 15000)
			all->count = 15000;
		else if (all->count > 10000)
			all->count = 10000;
		else if (all->count > 5000)
			all->count = 5000;
		else
			all->count = 0;
		put_images(all);
	}
	else
		end_game(all);
}

void	animation_position(t_all *all, int x, int y)
{
	animation_back(all, all->t.pos_x, all->t.pos_y, 0);
	all->t.pos_y = y;
	all->t.pos_x = x;
	animation_back(all, all->t.pos_x, all->t.pos_y, 0);
	animation_player(all, all->t.pos_x, all->t.pos_y, 0);
}

int	ft_method(t_all *all, int x, int y, char status)
{
	all->t.key = status;
	if (all->game[y][x] == '1')
		return (0);
	else if (all->game[y][x] == 'C')
	{
		all->game[y][x] = '0';
		all->m.coins += 1;
		put_img(*all, all->m.eg2, all->wth * x, all->hgt * y);
		return (1);
	}
	else if (all->game[y][x] == 'E' && (all->m.coins == all->m.coins_max))
		end_game(all);
	else if (all->game[y][x] == 'I')
	{
		all->t.key = 'X';
		animation_position(all, all->t.pos_x, all->t.pos_y);
		ft_lives(all);
		return (0);
	}
	animation_position(all, x, y);
	return (1);
}

int	ft_method_mode2(t_all *all, int x, int y, char status)
{
	all->t.key = status;
	if (all->game[y][x] == 'I')
	{
		put_img(*all, all->f.k, all->wth * x, all->hgt * y);
		all->game[y][x] = '0';
		path_mode1(all, &all->t);
		return (1);
	}
	else
		return (ft_method(all, x, y, status));
}
//system("leaks -- so_long");