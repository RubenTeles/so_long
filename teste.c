/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:32:56 by rteles            #+#    #+#             */
/*   Updated: 2022/04/26 22:16:31 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_so_long.h"

void	path_terriermon(t_terrier *t)
{
	t->p_w0 = "./Frames/Terriermon/W0.xpm";
	t->p_w1 = "./Frames/Terriermon/W1.xpm";
	t->p_w2 = "./Frames/Terriermon/W2.xpm";
	t->p_w3 = "./Frames/Terriermon/W3.xpm";
	t->p_a0 = "./Frames/Terriermon/A0.xpm";
	t->p_a1 = "./Frames/Terriermon/A1.xpm";
	t->p_a2 = "./Frames/Terriermon/A2.xpm";
	t->p_a3 = "./Frames/Terriermon/A3.xpm";
	t->p_s0 = "./Frames/Terriermon/S0.xpm";
	t->p_s1 = "./Frames/Terriermon/S1.xpm";
	t->p_s2 = "./Frames/Terriermon/S2.xpm";
	t->p_s3 = "./Frames/Terriermon/S3.xpm";
	t->p_d0 = "./Frames/Terriermon/D0.xpm";
	t->p_d1 = "./Frames/Terriermon/D1.xpm";
	t->p_d2 = "./Frames/Terriermon/D2.xpm";
	t->p_d3 = "./Frames/Terriermon/D3.xpm";
	t->p_dead = "./Frames/Terriermon/Dead.xpm";
}

void	path_images(t_terrier *t, t_flame *f, t_menu *m, t_back *b)
{
	path_terriermon(&t);
	f->p_0 = "./Frames/Flamemon/0.xpm";
	f->p_1 = "./Frames/Flamemon/1.xpm";
	f->p_2 = "./Frames/Flamemon/2.xpm";
	f->p_3 = "./Frames/Flamemon/3.xpm";
	m->p_digi = "./Frames/Menu/digi.xpm";
	m->p_paws = "./Frames/Menu/paws.xpm";
	m->p_egg0 = "./Frames/Menu/egg0.xpm";
	m->p_egg1 = "./Frames/Menu/egg1.xpm";
	m->p_egg2 = "./Frames/Menu/egg2.xpm";
	m->p_p0 = "./Frames/Menu/p0.xpm";
	m->p_p1 = "./Frames/Menu/p1.xpm";
	b->p_w0 = "./Frames/Background/w0.xpm";
	b->p_w1 = "./Frames/Background/w1.xpm";
	b->p_w2 = "./Frames/Background/w2.xpm";
	b->p_w3 = "./Frames/Background/w3.xpm";
	b->p_b0 = "./Frames/Background/b0.xpm";
	b->p_b1 = "./Frames/Background/b1.xpm";
}
