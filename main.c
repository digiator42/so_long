/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:21:52 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/14 17:50:20 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_images(t_map *img)
{
	mlx_destroy_image(img->mlx, img->coin);
	mlx_destroy_image(img->mlx, img->player);
	mlx_destroy_image(img->mlx, img->wall);
	mlx_destroy_image(img->mlx, img->space);
}

int	x_click(t_map *m)
{
	free_map(m->map);
	destroy_images(m);
	mlx_destroy_window(m->mlx, m->img);
	exit(0);
}

int	tracing(int key, t_map *map)
{
	if (key == ON_DESTROY)
		x_click(map);
	if (key == ON_KEYDOWN || key == ON_S)
		move_player_down(map);
	if (key == ON_KEYUP || key == ON_W)
		move_player_up(map);
	if (key == ON_KEYLEFT || key == ON_A)
		(move_player_left(map));
	if (key == ON_KEYRIGHT || key == ON_D)
		(move_player_right(map));
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (!parsing(ac, av, &map))
		exit(1);	
	map_init(&map);
	draw_map(&map);
	mlx_hook(map.img, 2, 0, tracing, &map);
	mlx_hook(map.img, 17, 0, x_click, &map);
	mlx_loop(map.mlx);
	return (0);
}
