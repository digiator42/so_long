/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:21:52 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/13 02:18:00 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_map *map)
{
	int	w;
	int	h;

	w = 64;
	h = 64;
	map->total_moves = 0;
	map->mlx = mlx_init();
	map->img = mlx_new_window(map->mlx, (map->x * 64), (map->y * 64),
			"so_long");
	map->player = mlx_xpm_file_to_image(map->mlx, "includes/player.xpm", &w,
			&h);
	map->wall = mlx_xpm_file_to_image(map->mlx, "includes/wall.xpm", &w, &h);
	map->coin = mlx_xpm_file_to_image(map->mlx, "includes/coin.xpm", &w, &h);
	map->space = mlx_xpm_file_to_image(map->mlx, "includes/floor.xpm", &w, &h);
	map->exit = mlx_xpm_file_to_image(map->mlx, "includes/exit.xpm", &w, &h);
}

void	draw_basics(t_map *map)
{
	map->ypos = 0;
	map->v = 0;
	while (map->ypos < map->y)
	{
		map->xpos = 0;
		map->l = 0;
		while (map->xpos < map->x)
		{
			mlx_put_image_to_window(map->mlx, map->img, map->space, map->l,
					map->v);
			if (map->map[map->ypos][map->xpos] == '1')
				mlx_put_image_to_window(map->mlx, map->img, map->wall, map->l,
						map->v);
			map->xpos++;
			map->l += 64;
		}
		map->ypos++;
		map->v += 64;
	}
}

void	draw_map(t_map *map)
{
	draw_basics(map);
	map->ypos = 0;
	map->v = 0;
	while (map->ypos < map->y)
	{
		map->xpos = 0;
		map->l = 0;
		while (map->xpos < map->x)
		{
			if (map->ypos == map->p_ypos && map->xpos == map->p_xpos)
				mlx_put_image_to_window(map->mlx, map->img, map->player, map->l,
						map->v);
			else if (map->map[map->ypos][map->xpos] == 'E')
				mlx_put_image_to_window(map->mlx, map->img, map->exit, map->l,
						map->v);
			else if (map->map[map->ypos][map->xpos] == 'C')
				mlx_put_image_to_window(map->mlx, map->img, map->coin, map->l,
						map->v);
			map->xpos++;
			map->l += 64;
		}
		map->ypos++;
		map->v += 64;
	}
}

int	x_click(void)
{
	exit(0);
}

int	tracing(int key, t_map *map)
{
	if (key == ON_DESTROY)
		(exit(0));
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
	t_map map;

	if (!parsing(ac, av, &map))
		(free_map(&map), exit(0));
	map_init(&map);
	draw_map(&map);
	mlx_hook(map.img, 2, 0, tracing, &map);
	mlx_hook(map.img, 17, 0, x_click, &map);
	mlx_loop(map.mlx);
	return (0);
}