/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:57:29 by rteles            #+#    #+#             */
/*   Updated: 2022/05/10 11:51:33 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"
#include <stdio.h>
#include <unistd.h>

int	key_hook(int keycode, t_all *all)
{
	int	i;
	
	if (keycode == 53 || keycode == 65307)//ESC
		i = end_game(all);
	else if (keycode == 13 || keycode == 119)//W
		i = ft_method(all, all->t.pos_x, all->t.pos_y - 1, 'W');
	else if (keycode == 0 || keycode == 97)//A
		i = ft_method(all, all->t.pos_x - 1, all->t.pos_y, 'A');
	else if (keycode == 1 || keycode == 115)//S
		i = ft_method(all, all->t.pos_x, all->t.pos_y + 1, 'S');
	else if (keycode == 2 || keycode == 100)//D
		i = ft_method(all, all->t.pos_x + 1, all->t.pos_y, 'D');
	else
		return (0);
	all->m.paws += i;
	put_menu(all, 0);
	return (0);
}

int	put_images(t_all *all)
{
	static int	count = 0;
	int			x;
	int			y;

	y = 0;
	if (count == 0 || count == 5000 || count == 10000 || count == 15000)
	{
		while ((y <= all->max_y))
		{
			x = 0;
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
						all->game[y][x] = '0';
					}
					else if (all->game[y][x] == 'C')
						animation_egg(all, x, y, count);
					else if (all->game[y][x] == 'E' && (all->m.coins == all->m.coins_max))
						animation_portal(all, x, y, count);
					else if (all->game[y][x] == 'I')
						animation_enemy(all, x, y, count);
				}
				x++;
			}
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

void	create_map(t_all *all, int y, int fd)
{
	char	*str;

	str = get_next_line(fd);
	if (str != NULL)
		create_map(all, y + 1, fd);
	else
	{
		all->game = (char **)malloc(sizeof(char *) * (y + 1));
		all->max_y = y - 1;
	}
	all->game[y] = str;
}

int	main(int argc, char **argv)
{
	int				fd;
	t_all			all;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error Number % d\n", errno);/////
		perror("Program");
	}
	create_map(&all, 0, fd);
	all.max_x = ft_countn_n(all.game[0]) - 1;
	all.ptr = mlx_init();
	if (!all.ptr)
		exit(0);
	path_images(&all);
	verification_map(&all, 0, 0, all.game);
	//printf("Max_X: %i Max_Y: %i\n", all.max_x, all.max_y);
	//printf("Player: %i Portal: %i Coins: %i\n", all.t.player, all.m.portal , all.m.coins_max);
	all.wth = 34;
	all.hgt = 31;
	all.win = mlx_new_window(all.ptr, (all.max_x + 1) * all.wth,
			(all.max_y + 2) * all.hgt, "Jogo");
	put_menu(&all, 0);
	put_str(&all, all.m.time, 0x00FFFFFF, all.wth *  1.5, -1);
	mlx_key_hook(all.win, key_hook, &all);
	mlx_loop_hook(all.ptr, put_images, &all);
	mlx_loop(all.ptr);
	//system("leaks -- so_long");
	return (0);
}
//ft_PRINTF