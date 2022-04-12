/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:57:29 by rteles            #+#    #+#             */
/*   Updated: 2022/04/12 22:48:25 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_img {
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_vars {
	void	*ptr;
	void	*win;
}				t_vars;

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
		exit(-1);
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

int	main(void)
{
	t_vars	mlx;
	t_img	img;
	int		a;

	a = 0;
	img.relative_path = "./Frames/Veemon/V_S0.xpm";
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, 1920, 1080, "Jogo");
/*	img.img = mlx_new_image(mlx.ptr, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	my_mlx_pixel_put(&img, 300, 300, 0x00FF0000);*/
	img.img = mlx_xpm_file_to_image(mlx.ptr, img.relative_path, &img.img_width, &img.img_height);
	mlx_put_image_to_window(mlx.ptr, mlx.win, img.img, 0, 0);

	a = mlx_key_hook(mlx.win, key_hook, &mlx);
	if (a == 1)
	{
		mlx_destroy_image(mlx.ptr, &img);
		//img->relative_path = "./Frames/Veemon/V_A0.xpm";
		//img->img = mlx_xpm_file_to_image(vars->ptr, img->relative_path, &img->img_width, &img->img_height);
		//mlx_put_image_to_window(vars->ptr, vars->win, img->img, 0, 0);
	}
//	mlx_loop_hook(mlx.win, &mlx);
	mlx_loop(mlx.ptr);
}
/*	int w;
	int y;*/
//	img = mlx_xpm_file_to_image;
//	mlx_put_image_to_window;

//	mlx_hook(mlx.win, 2, 1L << 5, close, &mlx);
	//printf("Inseriste a Tecla %i \n", keycode);