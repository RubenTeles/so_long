/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:53:14 by rteles            #+#    #+#             */
/*   Updated: 2022/04/23 20:41:30 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

typedef struct i_terriermon {
	void	*img;
	char	*p_w0;
	char	*p_w1;
	char	*p_w2;
	char	*p_w3;
	char	*p_a0;
	char	*p_a1;
	char	*p_a2;
	char	*p_a3;
	char	*p_s0;
	char	*p_s1;
	char	*p_s2;
	char	*p_s3;
	char	*p_d0;
	char	*p_d1;
	char	*p_d2;
	char	*p_d3;
	char	*p_dead;
	int		img_width;
	int		img_height;
}						t_terrier;

typedef struct i_flamemon {
	void	*img;
	char	*p_0;
	char	*p_1;
	char	*p_2;
	char	*p_3;
	int		img_width;
	int		img_height;
}						t_flame;

typedef struct i_menu {
	void	*img;
	char	*p_digi;
	char	*p_paws;
	char	*p_egg0;
	char	*p_egg1;
	char	*p_egg2;
	char	*p_p0;
	char	*p_p1;
	int		img_width;
	int		img_height;
}						t_menu;

typedef struct i_background {
	void	*img;
	char	*p_w0;
	char	*p_w1;
	char	*p_w2;
	char	*p_w3;
	char	*p_b0;
	char	*p_b1;
	int		img_width;
	int		img_height;
}						t_back;

typedef struct c_all {
	t_terrier	t;
	t_flame		f;
	t_menu		m;
	t_back		b;
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
	int		width;
	int		height;
}				t_img;

typedef struct s_vars {
	void	*ptr;
	void	*win;
}				t_vars;

void	path_images(t_terrier *t, t_flame *f, t_menu *m, t_back *b);
void	path_terriermon(t_terrier *t);

#endif
