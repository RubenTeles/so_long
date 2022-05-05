/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:53:14 by rteles            #+#    #+#             */
/*   Updated: 2022/05/05 22:32:42 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <errno.h>
# include "./get_next_line/get_next_line.h"

typedef struct i_terriermon {
	void	*w0;
	void	*w1;
	void	*w2;
	void	*w3;
	void	*a0;
	void	*a1;
	void	*a2;
	void	*a3;
	void	*s0;
	void	*s1;
	void	*s2;
	void	*s3;
	void	*d0;
	void	*d1;
	void	*d2;
	void	*d3;
	void	*x;
	int		pos_x;
	int		pos_y;
	char	key;
}						t_terrier;

typedef struct i_flamemon {
	void	*i0;
	void	*i1;
	void	*i2;
	void	*i3;
}						t_flame;

typedef struct i_menu {
	void	*dgi;
	void	*pws;
	void	*eg0;
	void	*eg1;
	void	*eg2;
	void	*p0;
	void	*p1;
}						t_menu;

typedef struct i_background {
	void	*b0;
	void	*b1;
	void	*w0;
	void	*w1;
	void	*w2;
	void	*w3;
}						t_back;

typedef struct c_all {
	void		*ptr;
	void		*win;
	char		**game;
	char		**temp;
	int			max_x;
	int			max_y;
	t_terrier	t;
	t_flame		f;
	t_menu		m;
	t_back		b;
	int			wth;
	int			hgt;
	int			paws;
}					t_all;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_img {
	void	*img;
	char	*path;
	int		wth;
	int		hgt;
}				t_img;

void	path_images(t_all *a);
void	path_terriermon(t_all *a);
int		put_images(t_all *all);
int		put_img(t_all all, void *img, int x, int y);
int		animation_wall(t_all *all, int x, int y, int count);
int		animation_back(t_all *all, int x, int y, int count);
int		animation_egg(t_all *all, int x, int y, int count);
int		animation_portal(t_all *all, int x, int y, int count);
int		animation_player(t_all *all, int x, int y, int count);
void	animation_player_walk_w(t_all *all, int x, int y, int count);
void	animation_player_walk_a(t_all *all, int x, int y, int count);
void	animation_player_walk_s(t_all *all, int x, int y, int count);
void	animation_player_walk_d(t_all *all, int x, int y, int count);
void	animation_player_w(t_all *all, int x, int y, int count);
void	animation_player_a(t_all *all, int x, int y, int count);
void	animation_player_s(t_all *all, int x, int y, int count);
void	animation_player_d(t_all *all, int x, int y, int count);
char	*ft_itoa(int n);

#endif
