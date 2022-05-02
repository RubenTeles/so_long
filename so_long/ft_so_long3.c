/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:57:29 by rteles            #+#    #+#             */
/*   Updated: 2022/04/29 21:29:58 by rteles           ###   ########.fr       */
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
	if (a == '0')
		img->path = "./Frames/Background/b0.xpm";
	else if (a == '1')
		img->path = "./Frames/Background/w0.xpm";
	else if (a == 'C')
		img->path = "./Frames/Menu/egg0.xpm";
	else if (a == 'P')
		img->path = "./Frames/Terriermon/S0.xpm";
	else if (a == 'E')
		img->path = "./Frames/Menu/p0.xpm";
	else if (a == '\n' || a == '\0')
		return (0);
	mlx_xpm_file_to_image(mlx->ptr, img->path, &img->width, &img->height);
	return (1);
}

void	while_string(char *str, t_vars *mlx, t_img **img, int y)
{
	int		x;

	x = 0;
	while (str[x] != '\n' || str[x])
	{
		if (str[x] == '0')
			img[x]->path = "./Frames/Background/b0.xpm";
		else if (str[x] == '1')
			img[x]->path = "./Frames/Background/w0.xpm";
		else if (str[x] == 'C')
			img[x]->path = "./Frames/Menu/egg0.xpm";
		else if (str[x] == 'P')
			img[x]->path = "./Frames/Terriermon/S0.xpm";
		else if (str[x] == 'E')
			img[x]->path = "./Frames/Menu/p0.xpm";
		mlx_xpm_file_to_image(mlx->ptr, img[x]->path, &img[x]->width,
			&img[x]->height);
		mlx_put_image_to_window(mlx->ptr, mlx->win, img[x]->img,
			(img[x]->width * x), (img[x]->width * y));
		x++;
	}
}

int	main(int argc, char **argv)
{
	int				fd;
	char			*str;
	char			*last_line;
	static t_img	img_game[5][13];
	t_vars			mlx;
	int				x;
	int				y;

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
	while_string(str, &mlx, img_game[y], y);
	//y = ft_strlen(str) - 1;
	printf("string: %s\n", str);
/*	mlx.win = mlx_new_window(mlx.ptr, 1920, 1080, "Jogo");
	img_game[y][x].path = "./Frames/Terriermon/Dead.xpm";
	img_game[y][x].img = mlx_xpm_file_to_image(mlx.ptr, img_game[y][x].path, &img_game[y][x].width, &img_game[y][x].height);
	mlx_put_image_to_window(mlx.ptr, mlx.win, img_game[y][x].img, 0, 0);
	x++;
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
	mlx_loop(mlx.ptr);
//	system("leaks -- so_long");
	return (0);
}
//using argv[1]
//ft_PRINTF
