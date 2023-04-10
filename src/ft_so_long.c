/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:57:29 by rteles            #+#    #+#             */
/*   Updated: 2022/05/12 21:33:17 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	key_hook_mode2(int keycode, t_all *all)
{
	int	i;

	if (keycode == 53 || keycode == 65307)
		i = bye_bye(all);
	else if (keycode == 13 || keycode == 119)
		i = ft_method_mode2(all, all->t.pos_x, all->t.pos_y - 1, 'W');
	else if (keycode == 0 || keycode == 97)
		i = ft_method_mode2(all, all->t.pos_x - 1, all->t.pos_y, 'A');
	else if (keycode == 1 || keycode == 115)
		i = ft_method_mode2(all, all->t.pos_x, all->t.pos_y + 1, 'S');
	else if (keycode == 2 || keycode == 100)
		i = ft_method_mode2(all, all->t.pos_x + 1, all->t.pos_y, 'D');
	else
		i = 0;
	path_mode1(all, &all->t);
	animation_player(all, all->t.pos_x, all->t.pos_y, 0);
	put_menu(all);
	return (i);
}

int	key_hook_mode1(int keycode, t_all *all)
{
	int	i;

	if (all->t.mode == 2)
		i = key_hook_mode2(keycode, all);
	else if (keycode == 53 || keycode == 65307)
		i = bye_bye(all);
	else if (keycode == 13 || keycode == 119)
		i = ft_method(all, all->t.pos_x, all->t.pos_y - 1, 'W');
	else if (keycode == 0 || keycode == 97)
		i = ft_method(all, all->t.pos_x - 1, all->t.pos_y, 'A');
	else if (keycode == 1 || keycode == 115)
		i = ft_method(all, all->t.pos_x, all->t.pos_y + 1, 'S');
	else if (keycode == 2 || keycode == 100)
		i = ft_method(all, all->t.pos_x + 1, all->t.pos_y, 'D');
	else if (keycode == 46 || keycode == 109)
	{
		path_mode2(all, &all->t);
		i = animation_player(all, all->t.pos_x, all->t.pos_y, 0);
	}
	else
		return (0);
	all->m.paws += i;
	put_menu(all);
	return (0);
}

void	create_map(t_all *all, int y, int fd)
{
	char	*str;

	str = get_next_line(fd);
	if (y == 0 && !str)
	{
		ft_erro(4);
		return ;
	}
	if (str != NULL)
		create_map(all, y + 1, fd);
	else
	{
		all->game = (char **)malloc(sizeof(char *) * (y + 1));
		all->max_y = y - 1;
	}
	all->game[y] = str;
}

void	ft_loop_game(t_all *all, int argc, char **argv)
{
	verification_parameter(all, argv, argc);
	all->max_x = ft_countn_n(all->game[0]) - 1;
	if (!all->ptr)
		exit(0);
	path_images(all);
	verification_map(all, 0, 0, all->game);
	if (all->max_x < 13)
		all->win = mlx_new_window(all->ptr, (13) * all->wth,
				(all->max_y + 2) * all->hgt, "Jogo");
	else
		all->win = mlx_new_window(all->ptr, (all->max_x + 1) * all->wth,
				(all->max_y + 2) * all->hgt, "Jogo");
	put_menu(all);
	mlx_key_hook(all->win, key_hook_mode1, all);
	mlx_hook(all->win, 17, 0, bye_bye, all);
}

int	main(int argc, char **argv)
{
	t_all			all;

	if (argc < 2)
	{
		ft_erro(4);
		return (0);
	}
	all.ptr = mlx_init();
	all.t.lives = 3;
	all.argc_max = argc - 1;
	all.argc_corrent = 1;
	all.argv = argv;
	ft_loop_game(&all, all.argc_corrent, all.argv);
	mlx_loop_hook(all.ptr, put_images, &all);
	mlx_loop(all.ptr);
	return (0);
}
