/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:25:08 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/14 13:25:51 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_map *m)
{
	int	w;
	int	h;

	w = 64;
	h = 64;
	m->total_moves = 0;
	m->mlx = mlx_init();
	m->img = mlx_new_window(m->mlx, (m->x * 64), (m->y * 64), "so_long");
	m->player = mlx_xpm_file_to_image(m->mlx, "includes/player.xpm", &w, &h);
	m->wall = mlx_xpm_file_to_image(m->mlx, "includes/wall.xpm", &w, &h);
	m->coin = mlx_xpm_file_to_image(m->mlx, "includes/coin.xpm", &w, &h);
	m->space = mlx_xpm_file_to_image(m->mlx, "includes/floor.xpm", &w, &h);
	m->exit = mlx_xpm_file_to_image(m->mlx, "includes/exit.xpm", &w, &h);
}

void	draw_basics(t_map *m)
{
	m->ypos = 0;
	m->v = 0;
	while (m->ypos < m->y)
	{
		m->xpos = 0;
		m->l = 0;
		while (m->xpos < m->x)
		{
			mlx_put_image_to_window(m->mlx, m->img, m->space, m->l, m->v);
			if (m->map[m->ypos][m->xpos] == '1')
				mlx_put_image_to_window(m->mlx, m->img, m->wall, m->l, m->v);
			m->xpos++;
			m->l += 64;
		}
		m->ypos++;
		m->v += 64;
	}
}

void	draw_map(t_map *m)
{
	draw_basics(m);
	m->ypos = 0;
	m->v = 0;
	while (m->ypos < m->y)
	{
		m->xpos = 0;
		m->l = 0;
		while (m->xpos < m->x)
		{
			if (m->ypos == m->p_ypos && m->xpos == m->p_xpos)
				mlx_put_image_to_window(m->mlx, m->img, m->player, m->l, m->v);
			else if (m->map[m->ypos][m->xpos] == 'E')
				mlx_put_image_to_window(m->mlx, m->img, m->exit, m->l, m->v);
			else if (m->map[m->ypos][m->xpos] == 'C')
				mlx_put_image_to_window(m->mlx, m->img, m->coin, m->l, m->v);
			m->xpos++;
			m->l += 64;
		}
		m->ypos++;
		m->v += 64;
	}
}
