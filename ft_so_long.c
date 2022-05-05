/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:57:29 by rteles            #+#    #+#             */
/*   Updated: 2022/05/05 22:44:37 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"
#include <stdio.h>
#include <unistd.h>

int	key_hook(int keycode, t_all *all)
{
	int	x;
	int	y;

	x = all->t.pos_x;
	y = all->t.pos_y;
	if (keycode == 53)//ESC
	{
		mlx_clear_window(all->ptr, all->win);
		mlx_destroy_window(all->ptr, all->win);
		y = -1;
		while (all->game[++y])
			free(all->game[y]);
		free(all->game);
		system("leaks -- so_long");
		exit(0);
	}
	else if (keycode == 13)//W
	{
		if (all->game[y - 1][x] == '1')
			return (0);
		else if (all->game[y - 1][x] == 'C')
			all->game[y - 1][x] = '0';
		else if (all->game[y - 1][x] == 'E')	//END GAME
		{
			all->game[y - 1][x] = '0';
			printf("END GAME\n");
			key_hook(53, all);
		}
		else if (all->game[y - 1][x] == 'I')	//GAME OVER
		{
			all->game[y - 1][x] = '0';
			all->t.key = 'X';
			return (0);
		}
		animation_back(all, all->t.pos_x, all->t.pos_y, 0);
		all->t.pos_y = y - 1;
		all->t.key = 'W';
	}
	else if (keycode == 0)//A
	{
		if (all->game[y][x - 1] == '1')
			return (0);
		else if (all->game[y][x - 1] == 'C')
			all->game[y][x - 1] = '0';
		else if (all->game[y][x - 1] == 'E')	//END GAME
		{
			all->game[y][x - 1] = '0';
			printf("END GAME\n");
			key_hook(53, all);
		}
		else if (all->game[y][x - 1] == 'I')	//GAME OVER
		{
			all->game[y][x - 1] = '0';
			all->t.key = 'X';
			return (0);
		}
		animation_back(all, all->t.pos_x, all->t.pos_y, 0);
		all->t.pos_x = x - 1;
		all->t.key = 'A';
		//printf("Andou para cima! (W) \n");
	}
	else if (keycode == 1)//S
	{
		if (all->game[y + 1][x] == '1')
			return (0);
		else if (all->game[y + 1][x] == 'C')
		{
			all->game[y + 1][x] = '0';
			put_img(*all, all->m.eg2, x, y + 1);
		}
		else if (all->game[y + 1][x] == 'E')
		{
			all->game[y + 1][x] = '0';
			printf("END GAME\n");
			key_hook(53, all);
		}
		else if (all->game[y + 1][x] == 'I')
		{
			all->game[y + 1][x] = '0';
			all->t.key = 'X';
			return (0);
		}
		animation_back(all, all->t.pos_x, all->t.pos_y, 0);
		all->t.pos_y = y + 1;
		all->t.key = 'S';
		//printf("Andou para cima! (W) \n");
	}
	else if (keycode == 2)//D
	{
		if (all->game[y][x + 1] == '1')
			return (0);
		else if (all->game[y][x + 1] == 'C')
		{
			all->game[y][x + 1] = '0';
			put_img(*all, all->m.eg2, x, y + 1);
		}
		else if (all->game[y][x + 1] == 'E')
		{
			all->game[y][x + 1] = '0';
			printf("END GAME\n");
			key_hook(53, all);
		}
		else if (all->game[y][x + 1] == 'I')
		{
			all->game[y][x + 1] = '0';
			all->t.key = 'X';
			return (0);
		}
		animation_back(all, all->t.pos_x, all->t.pos_y, 0);
		all->t.pos_x = x + 1;
		all->t.key = 'D';
		//printf("Andou para a Direita! (D) \n");
	}
	else
		return (0);
	animation_back(all, all->t.pos_x, all->t.pos_y, 0);
	animation_player(all, all->t.pos_x, all->t.pos_y, 0);
	printf("Passos: %i \n", ++all->paws);
	return (0);
}

/*void	ft_so_long(void)
{
	t_all	ctr;
	t_vars	mlx;
	t_img	img;
	int		a;
	a = 0;
	img.path = "./Frames/Terriermon/Dead.xpm";
	mlx.ptr = mlx_init();
	if (!mlx.ptr)
		exit(0);
	mlx.win = mlx_new_window(mlx.ptr, 1920, 1080, "Jogo");
	img.img = mlx_xpm_file_to_image(mlx.ptr, img.path, &img.width, &img.height);
	mlx_put_image_to_window(mlx.ptr, mlx.win, img.img, 0, 0);
	a = mlx_key_hook(mlx.win, key_hook, &mlx);
	if (a == 1)
	{
		mlx_destroy_image(mlx.ptr, &img);
	}
//	mlx_loop_hook(mlx.ptr, asjadsjadj, &mlx);
	mlx_loop(mlx.ptr);
	system("leaks -- so_long");
}*/

void	put_menu(t_all *all)
{
	put_img(*all, all->m.dgi, all->wth * 0,
		all->hgt * (all->max_y + 1));
	/*mlx_string_put(all->ptr, all->win, all->wth * 40,
		all->hgt * 0, {{font color|green|greentext}}, ft_itoa(all->paws));*/
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
					else if (all->game[y][x] == 'E')
						animation_portal(all, x, y, count);
				}
				x++;
			}
			y++;
		}
		put_menu(all);
		animation_player(all, all->t.pos_x, all->t.pos_y, count);
	}
	count++;
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
		printf("Error Number % d\n", errno);
		perror("Program");
	}
	create_map(&all, 0, fd);
	all.max_x = ft_strlen(all.game[0]) - 1;
	printf("\nX: %i Y: %i", all.max_x, all.max_y);
	all.ptr = mlx_init();
	if (!all.ptr)
		exit(0);
	path_images(&all);
	all.wth = 34;
	all.hgt = 31;
	all.win = mlx_new_window(all.ptr, (all.max_x) * all.wth,
			(all.max_y + 2) * all.hgt, "Jogo");
	mlx_key_hook(all.win, key_hook, &all);
	mlx_loop_hook(all.ptr, put_images, &all);
	mlx_loop(all.ptr);
	system("leaks -- so_long");
	return (0);
}
//using argv[1]
//ft_PRINTF