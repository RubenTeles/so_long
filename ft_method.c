/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_method.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:57:29 by rteles            #+#    #+#             */
/*   Updated: 2022/05/11 20:58:40 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"
#include <stdio.h>
#include <unistd.h>

int	end_game(t_all *all)
{
	int	y;

	mlx_clear_window(all->ptr, all->win);
	mlx_destroy_window(all->ptr, all->win);
	y = -1;
	while (all->game[++y])
		free(all->game[y]);
	free(all->game);
	//system("leaks -- so_long");
	exit(0);
	return (0);
}

void	ft_lives(t_all *all)
{
	all->m.lives -= 1;
	if (all->m.lives > 0)
	{
		printf("lives: %i\n", all->m.lives);
		all->t.pos_x = all->frst_pos_x;
		all->t.pos_y = all->frst_pos_y;
		all->t.key = 'S';
		all->j.pos_x = all->frst_pos_x;
		all->j.pos_y = all->frst_pos_y;
		all->j.key = 'S';
		put_str(all, all->m.time, 0x00000000, all->wth * 1.5, -1);
		all->m.time = (all->m.coins_max + all->m.portal + all->t.player) * 3;
		put_str(all, all->m.time, 0x00FFFFFF, all->wth * 1.5, -1);
	}
	else
		end_game(all);
}

void	animation_position(t_all *all, int x, int y)
{
	if (all->status_player == 1)
	{
		animation_back(all, all->t.pos_x, all->t.pos_y, 0);
		all->t.pos_y = y;
		all->t.pos_x = x;
		animation_back(all, all->t.pos_x, all->t.pos_y, 0);
		animation_player(all, all->t.pos_x, all->t.pos_y, 0);
	}
	else if (all->status_player == 2)
	{
		animation_back(all, all->j.pos_x, all->j.pos_y, 0);
		all->j.pos_y = y;
		all->j.pos_x = x;
		animation_back(all, all->j.pos_x, all->j.pos_y, 0);
		animation_player2(all, all->j.pos_x, all->j.pos_y, 0);
	}
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

int	ft_method_player2(t_all *all, int x, int y, char status)
{
	all->j.key = status;
	if (all->game[y][x] == '1' || all->game[y][x] == 'C')
		return (0);
	else if (all->game[y][x] == 'E' && (all->m.coins == all->m.coins_max))
		end_game(all);
	else if (all->game[y][x] == 'I')
	{
		put_img(*all, all->f.k, all->wth * x, all->hgt * y);
		all->game[y][x] = '0';
		return (1);
	}
	animation_position(all, x, y);
	return (1);
}
