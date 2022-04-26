/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:57:29 by rteles            #+#    #+#             */
/*   Updated: 2022/04/26 22:30:15 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"
#include <stdio.h>
#include <unistd.h>

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