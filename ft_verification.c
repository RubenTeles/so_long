/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verification.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:57:29 by rteles            #+#    #+#             */
/*   Updated: 2022/05/12 17:27:39 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"
#include <stdio.h>
#include <unistd.h>

int	ft_countn_n(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

void	ft_erro(int type)
{
	if (type == 1)
		ft_printf("Error: The Map is not rectangular!\n");
	else if (type == 2)
		ft_printf("Error: The Map doesn't have the Minimum of Components!\n");
	else if (type == 3)
		ft_printf("Error: The Map must be surrounded by Walls!\n");
	else if (type == 4)
		ft_printf("Error: Can not read the file!\n");
	else if (type == 5)
		ft_printf("Error: Is not .ber file!\n");
	exit(0);
}

void	verification_map_2(t_all *all)
{
	int	x;
	int	y;

	x = all->max_x + 1;
	y = all->max_y + 1;
	if (x < 3 && y < 3)
		ft_erro(1);
	else if ((x == 3 && y < 5) || (y == 3 && x < 5))
		ft_erro(1);
	else if (all->m.coins_max < 1 || all->m.portal < 1 || all->t.player < 1)
		ft_erro(2);
	else
		path_begining_game(all);
}

void	verification_map(t_all *all, int y, int x, char **str)
{
	while (str[y])
	{
		if (all->max_x != (int)ft_countn_n(str[y]) - 1)
			ft_erro(1);
		x = 0;
		while (str[y][x] != '\n' && str[y][x])
		{
			if (str[0][x] != '1' || str[all->max_y][x] != '1' ||
				str[y][all->max_x] != '1' || str[y][0] != '1')
				ft_erro(3);
			if (str[y][x] == '0' || str[y][x] == '1' || str[y][x] == 'I')
				all->m.other_blocks += 1;
			else if (str[y][x] == 'P')
				all->t.player += 1;
			else if (str[y][x] == 'E')
				all->m.portal += 1;
			else if (str[y][x] == 'C')
				all->m.coins_max += 1;
			else
				ft_erro(2);
			x++;
		}
		y++;
	}
	verification_map_2(all);
}

void	verification_parameter(t_all *all, char **argv, int x)
{
	int	fd;
	int	len;

	len = ft_strlen(argv[x]);
	if (argv[x][len - 4] != '.' || argv[x][len - 3] != 'b'
		|| argv[x][len - 2] != 'e' || argv[x][len - 1] != 'r')
		ft_erro(5);
	fd = open(argv[x], O_RDONLY);
	if (fd < 0)
		ft_erro(4);
	create_map(all, 0, fd);
}
