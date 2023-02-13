/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:49:52 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/13 22:11:06 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	first_depth(int py, int px, t_map *path, char map_dup[][path->x])
{
	if (map_dup[py][px] == '1' || map_dup[py][px] == 'X')
		return ;
	if(map_dup[py][px] == 'E')
	{
		path->dupe_cnt--;
		map_dup[py][px] = 'X';
		return ;	
	}
	map_dup[py][px] = 'X';
	first_depth(py, px + 1, path, map_dup);
	first_depth(py, px - 1, path, map_dup);
	first_depth(py - 1, px, path, map_dup);
	first_depth(py + 1, px, path, map_dup);
}

int	is_valid_path(t_map *map)
{
	int x;
	int y = 0;
	char map_dup[map->y][map->x];
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			map_dup[y][x] = map->map[y][x];
			ft_printf("%c", map_dup[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
	first_depth(map->p_ypos, map->p_xpos, map, map_dup);
	// first_depth2(map, map->x, map_dup);
	y = 0;
	ft_printf("\n");
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			ft_printf("%c", map_dup[y][x]);
			if (map_dup[y][x] == 'C' || map->dupe_cnt)
				return (ft_printf("Not Valid Path %d %d", y, x), 0);
			x++;	
		}
		ft_printf("\n");
		y++;
	}
	return (1);
}