/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:57:29 by rteles            #+#    #+#             */
/*   Updated: 2022/05/02 23:09:04 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"
#include <stdio.h>
#include <unistd.h>

int	key_hook(int keycode, t_all *vars)
{
	int	x;
	int	y;
	if (keycode == 53)//ESC
	{
		mlx_clear_window(vars->ptr, vars->win);
		mlx_destroy_window(vars->ptr, vars->win);
		y = -1;
		while (++y <= vars->max_y + 1)
		{
			x = -1;
			while (++x <= vars->max_x)
				free(&vars->game[y][x]);
			free(&vars->game[y]);
		}
		system("leaks -- so_long");
		exit(0);
	}
	else if (keycode == 13)//W
	{
		printf("W \n");
	}
	else if (keycode == 0)//A
	{
		printf("A \n");
		return (1);
	}
	else if (keycode == 1)//S
	{
		printf("S \n");
	}
	else if (keycode == 2)//D
	{
		printf("D \n");
	}
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

int	put_img(t_all all, void *img, int x, int y)
{
	mlx_put_image_to_window(all.ptr, all.win, img, x, y);
	return (1);
}

int	animation_wall(t_all *all, int x, int y, int count)
{
	if(count == 0)
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
	if((count == 5000) || (count == 15000))
		put_img(*all, all->b.b0, all->wth * x, all->hgt * y);
	else if ((count == 10000) || (count == 0))
		put_img(*all, all->b.b1, all->wth * x, all->hgt * y);
	return (0);
}

int	animation_egg(t_all *all, int x, int y, int count)
{
	if((count == 5000) || (count == 15000))
		put_img(*all, all->m.eg0, all->wth * x, all->hgt * y);
	else if ((count == 10000) || (count == 0))
		put_img(*all, all->m.eg1, all->wth * x, all->hgt * y);
	return (0);
}

int	animation_portal(t_all *all, int x, int y, int count)
{
	if((count == 5000) || (count == 15000))
		put_img(*all, all->m.p0, all->wth * x, all->hgt * y);
	else if ((count == 10000) || (count == 0))
		put_img(*all, all->m.p1, all->wth * x, all->hgt * y);
	return (0);
}


int	animation_player(t_all *all, int x, int y, int count)
{
	if((count == 5000) || (count == 15000))
		put_img(*all, all->t.s0, all->wth * x, all->hgt * y);
	else if ((count == 10000) || (count == 0))
		put_img(*all, all->t.s1, all->wth * x, all->hgt * y);
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
							animation_player(all, x, y, count);
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
	}
	count++;
	if (count == 19999)
		count = 0;
	return (0);
}

/*char **ft_temp(t_all all)
{
	char 	**temp;
	int		y;

	y = 0;
	temp = (char**)malloc(sizeof(char*) * all.max_y + 1);
	while (y <= all.max_y)
	{
		temp[y] = (char*)malloc(sizeof(char) * all.max_x + 1);
		ft_strlcpy(temp[y], all.game[y], all.max_x + 1);
		if (all.game[y] != NULL)
			free(all.game[y]);
		y++;
	}
	if (all.game != NULL)
		free(all.game);
	return (temp);
}*/

int	main(int argc, char **argv)
{
	int				fd;
	char			*str;
	char			*last_line;
	t_img			**img_game;
	t_img			**tmp;
	t_vars			mlx;
	int				x;
	int				y;
	void			**background;
	t_back			back;
	t_all			all;

	all.wth = 31;
	all.hgt = 34;

	x = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error Number % d\n", errno);
		perror("Program");
	}
	str = get_next_line(fd);//se for null ou nao for tudo 1 = ERRO
	all.max_y = 4;
	all.max_x = ft_strlen(str) - 1;
	printf("X: %i\n", all.max_x);

	all.game = (char**)malloc(sizeof(char*) * all.max_y + 1);
	y = 0;
	while (str != NULL)
	{
		printf("string: %s\n", str);
		all.game[y] = (char*)malloc(sizeof(char) * all.max_x + 1);
		ft_strlcpy(all.game[y], str, all.max_x + 1);
		str = get_next_line(fd);
		if(!str)
			break;
		y++;
	}
	printf("y: %i! \n", y);
	all.ptr = mlx_init();
	if (!all.ptr)
		exit(0);
	path_images(&all);
	all.win = mlx_new_window(all.ptr, (all.max_x) * all.wth,
		(all.max_y + 1) * all.hgt, "Jogo");
	//put_images(&all);
	mlx_key_hook(all.win, key_hook, &all);
	mlx_loop_hook(all.ptr, put_images, &all);
	mlx_loop(all.ptr);
y = -1;
while (++y <= all.max_y)
{
	x = -1;
	while (++x <= all.max_x)
		free(&all.game[y][x]);
	free(&all.game[y]);
}
	system("leaks -- so_long");
	return (0);
}
//using argv[1]
//ft_PRINTF