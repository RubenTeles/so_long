/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:57:29 by rteles            #+#    #+#             */
/*   Updated: 2022/05/02 20:56:21 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"
#include <stdio.h>
#include <unistd.h>

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

int	iniciar_jogo(t_vars mlx)
{
	t_all	ctr;

	mlx.ptr = mlx_init();
	if (!mlx.ptr)
		exit(0);
	return (1);
}

int	meter_imagens_com_string(char a, t_vars *mlx, t_img *img)
{
	//if (a == '0')
	//	img->path = "./Frames/Background/b0.xpm";
	//else if (a == '1')
	//	img->path = "./Frames/Background/w0.xpm";
	//else if (a == 'C')
	//	img->path = "./Frames/Menu/egg0.xpm";
	//else if (a == 'P')
	//	img->path = "./Frames/Terriermon/S0.xpm";
	//else if (a == 'E')
	//	img->path = "./Frames/Menu/p0.xpm";
	//else if (a == '\n' || a == '\0')
	//	return (0);
	//mlx_xpm_file_to_image(mlx->ptr, img->path, &img->width, &img->height);
	return (1);
}

int	animation(t_all *all)
{
	static int	i;
	int			width;
	int			height;

	if(i == 10000)
	{
		all->b.b0 = all->b.b1;
	}
	else if (i == 30000)
	{
		all->b.b0 = all->b.w0;
		i = 0;
	}
	i++;
	return (0);
}

int	put_images(t_all all)
{
	int	x;
	int	y;

	while ((y <= all.max_y))
	{
		while (x <= all.max_x)
		{
			if (all.game[y][x] == '1')
			{
				mlx_put_image_to_window(all.ptr, all.win, all.b.w0,
						(all.wth * x), (all.hgt * y));
			}
			else
			{
				mlx_put_image_to_window(all.ptr, all.win, all.b.b0,
						(all.wth * x), (all.hgt * y));
				if (all.game[y][x] == 'P')
				{
					mlx_put_image_to_window(all.ptr, all.win, all.t.s0,
							(all.wth * x), (all.hgt * y));
				}
				else if (all.game[y][x] == 'C')
				{
					mlx_put_image_to_window(all.ptr, all.win, all.m.eg0,
							(all.wth * x), (all.hgt * y));
				}
				else if (all.game[y][x] == 'E')
				{
					mlx_put_image_to_window(all.ptr, all.win, all.m.p0,
							(all.wth * x), (all.hgt * y));
				}
			}
			x++;
		}
		y++;
	}
	return (1);
}

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
	void			*imagem;
	t_all			all;

	all.wth = 31;
	all.hgt = 34;
	y = 0;
	x = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error Number % d\n", errno);
		perror("Program");
	}
	str = get_next_line(fd);
	mlx.ptr = mlx_init();
	all.ptr = &mlx.ptr;
	path_images(&all);
	mlx.win = mlx_new_window(mlx.ptr, 500, 500, "Jogo");
	background = &all.b.b0;
	img_game = (t_img**)malloc(sizeof(t_img*) * (5));
	while (str != NULL)
	{
		printf("Entrou\n");
		//img_game = (t_img**)malloc(sizeof(t_img*) * (y + 1));
		x = ft_strlen(str) - 1;
		printf("x:%i  ", x);
		img_game[y] = (t_img*)malloc(sizeof(t_img) * x);
		x = 0;
		while ((str[x] != '\n') && (str[x] != '\0'))
		{
			printf("Array: y:%i x:%i  ", y, x);
			printf("char:%c\n", str[x]);
			if (str[x] == '1')
			{
				mlx_put_image_to_window(mlx.ptr, mlx.win, all.b.w0,
						(all.wth * x), (all.hgt * y));
			}
			else
			{
				mlx_put_image_to_window(mlx.ptr, mlx.win, *background,
						(all.wth * x), (all.hgt * y));
				if (str[x] == 'P')
				{
					mlx_put_image_to_window(mlx.ptr, mlx.win, all.t.s0,
							(all.wth * x), (all.hgt * y));
				}
				else if (str[x] == 'C')
				{
					mlx_put_image_to_window(mlx.ptr, mlx.win, all.m.eg0,
							(all.wth * x), (all.hgt * y));
				}
				else if (str[x] == 'E')
				{
					mlx_put_image_to_window(mlx.ptr, mlx.win, all.m.p0,
							(all.wth * x), (all.hgt * y));
				}
			}
			x++;
		}
		str = get_next_line(fd);
		if(!str)
			break;
		y++;
	}
//	mlx.win = mlx_new_window(mlx.ptr, x * width, y * height, "Jogo");

	
	
	
	//while_string(str, &mlx, &img_game[y], y);
//	printf("string: %s\n", str);
	x = 0;
//	printf("Array: y:%i x:%i\n", y, x);
	
//img_game[y][x].path = path('1');
//img_game[y][x].img = mlx_xpm_file_to_image(mlx.ptr, img_game[y][x].path, &img_game[y][x].width, &img_game[y][x].height);
//mlx_put_image_to_window(mlx.ptr, mlx.win, img_game[y][x].img, 0, 0);
/*	x++;
	img_game[y][x].path = "./Frames/Terriermon/W0.xpm";
	img_game[y][x].img = mlx_xpm_file_to_image(mlx.ptr, img_game[y][x].path, &img_game[y][x].width, &img_game[y][x].height);
	mlx_put_image_to_window(mlx.ptr, mlx.win, img_game[y][x].img, (img_game[y][x].width * x), 0);
	x++;
	img_game[y][x].path = "./Frames/Terriermon/D2.xpm";
	img_game[y][x].img = mlx_xpm_file_to_image(mlx.ptr, img_game[y][x].path, &img_game[y][x].width, &img_game[y][x].height);
	mlx_put_image_to_window(mlx.ptr, mlx.win, img_game[y][x].img, (img_game[y][x].width * x), 0);*/
//	while_string(str, &mlx, y);
	/*while (str != NULL)
	{
		y++;
		last_line = str;
		str = get_next_line(fd);
		while_string(str, &mlx, y);
	}*/
//	printf("string: %s\n", last_line);
//	printf("X: %i\n", x);
//	printf("Y: %i", y);
	//back.ptr = &mlx.ptr;
	mlx_loop_hook(mlx.ptr, animation, &all);
	mlx_loop(mlx.ptr);
//	system("leaks -- so_long");
	//free(&img_game[1][1]);
	//free(&img_game[1][2]);
	//free(&img_game[1][3]);
	//free(&img_game[1][4]);
	//free(&img_game[1][5]);
	//free(&img_game[1][6]);
	//free(&img_game[1][7]);
	//free(&img_game[1][8]);
	//free(&img_game[1][9]);
	//free(&img_game[1][10]);
	//free(&img_game[1][11]);
	//free(&img_game[1][12]);
	//free(&img_game[1][13]);
	//free(&img_game[1]);
	return (0);
}
//using argv[1]
//ft_PRINTF