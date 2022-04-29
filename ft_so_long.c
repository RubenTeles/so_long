/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:57:29 by rteles            #+#    #+#             */
/*   Updated: 2022/04/29 19:41:33 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"
#include <stdio.h>
#include <unistd.h>

ft_so_long(void)
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

int iniciar_jogo(t_vars mlx)
{
	t_all	ctr;

	mlx.ptr = mlx_init();
	if (!mlx.ptr)
		exit(0);
	return (1);
}

void *meter_imagens_com_string(char a, t_vars mlx)
{
	t_img	img;
	
	if (a == '0')
		img.path = "./Frames/Background/b0.xpm";
	else if (a == '1')
		img.path = "./Frames/Background/w0.xpm";
	else if (a == 'C')
		img.path = "./Frames/Menu/egg0.xpm";
	else if (a == 'P')
		img.path = "./Frames/Terriermon/S0.xpm";
	else if (a == 'E')
		img.path = "./Frames/Menu/p0.xpm";
	else if (a == '\n' || a == '\0')
		return (0);
	return (mlx_xpm_file_to_image(mlx.ptr, img.path, &img.width, &img.height));
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*str;
	char	*last_line;
	t_img	**img_game;
	int		y;
	int		x;

	x = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error Number % d\n", errno);
		perror("Program");
	}
	str = get_next_line(fd);
	y = ft_strlen(str) - 1;
	printf("string: %s\n", str);
	while (str != NULL)
	{
		last_line = str;
		str = get_next_line(fd);
		x++;
	}
	printf("string: %s\n", last_line);
	printf("Y: %i\n", y);
	printf("X: %i", x);
	return (0);
}
//using argv[1]
//ft_PRINTF