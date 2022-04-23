/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:57:29 by rteles            #+#    #+#             */
/*   Updated: 2022/04/23 20:45:56 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_so_long.h"

/*int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->ptr, vars->win);
	keycode = 0;
	return (0);
}*/

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)//ESC
	{
		mlx_clear_window(vars->ptr, vars->win);
		mlx_destroy_window(vars->ptr, vars->win);
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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	asjadsjadj(t_vars *mlx)
{
	printf("D \n");
	return (0);
}

int	main(void)
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
	mlx_loop_hook(mlx.ptr, asjadsjadj, &mlx);
	mlx_loop(mlx.ptr);
	system("leaks -- so_long");
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