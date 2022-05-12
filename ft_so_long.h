/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:53:14 by rteles            #+#    #+#             */
/*   Updated: 2022/05/12 18:56:45 by rteles           ###   ########.fr       */
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
# include "./ft_printf/ft_printf.h"

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
	int		t_ani;
	int		player;
	int		mode;
	int		lives;
}						t_terrier;

typedef struct i_flamemon {
	void	*i0;
	void	*i1;
	void	*i2;
	void	*i3;
	void	*k;
	int		f_ani;
}						t_flame;

typedef struct i_menu {
	void	*dgi;
	void	*pws;
	void	*tim;
	void	*eg0;
	void	*eg1;
	void	*eg2;
	int		e_ani;
	void	*p0;
	void	*p1;
	int		p_ani;
	void	*liv;
	int		portal;
	int		coins_max;
	int		coins;
	int		time;
	int		paws;
	int		other_blocks;
}						t_menu;

typedef struct i_background {
	void	*b0;
	void	*b1;
	int		b_ani;
	void	*w0;
	void	*w1;
	void	*w2;
	void	*w3;
	int		w_ani;
}						t_back;

typedef struct c_all {
	void		*ptr;
	void		*win;
	char		**game;
	int			max_x;
	int			max_y;
	int			frst_pos_x;
	int			frst_pos_y;
	int			count;
	t_terrier	t;
	t_terrier	j;
	t_flame		f;
	t_menu		m;
	t_back		b;
	int			wth;
	int			hgt;
	int			argc_max;
	int			argc_corrent;
	char		**argv;
}					t_all;

void	ft_loop_game(t_all *all, int argc, char **argv);
void	create_map(t_all *all, int y, int fd);
void	put_menu(t_all *all);
int		end_game(t_all *all);
int		ft_method(t_all *all, int x, int y, char status);
int		ft_method_mode2(t_all *all, int x, int y, char status);
void	path_images(t_all *a);
void	path_mode1(t_all *a, t_terrier *t);
void	path_mode2(t_all *a, t_terrier *j);
void	path_begining_game(t_all *a);
int		put_images(t_all *all);
int		put_img(t_all all, void *img, int x, int y);
void	put_str_plus(t_all *all, int number, int color, int x);
void	put_str_less(t_all *all, int number, int color, int x);
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
int		animation_player2(t_all *all, int x, int y, int count);
void	animation_player2_w(t_all *all, int x, int y, int count);
void	animation_player2_a(t_all *all, int x, int y, int count);
void	animation_player2_s(t_all *all, int x, int y, int count);
void	animation_player2_d(t_all *all, int x, int y, int count);
void	animation_enemy(t_all *all, int x, int y, int count);
void	animation_time(t_all *all, int count);
char	*ft_itoa(int n);
void	verification_map(t_all *all, int y, int x, char **str);
void	verification_parameter(t_all *all, char **argv, int x);
void	ft_erro(int type);
int		ft_countn_n(char *str);
void	ft_lives(t_all *all);
int		bye_bye(t_all *all);

#endif
