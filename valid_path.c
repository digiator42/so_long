/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:49:52 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/13 00:30:53 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void first_depth(int py, int px, t_map *path)
{

	if(path->map_dup[py][px] == '1' || path->map_dup[py][px] == 'X')
		return ;	

	path->map_dup[py][px] = 'X';
	first_depth(py, px+1, path);
	first_depth(py, px-1, path);
	first_depth(py-1, px, path);
	first_depth(py+1, px, path);
}


int is_valid_path(t_map *map)
{	
	int x;
	int y = 0;
	if(map->y > MAX_H || map->x > MAX_W)
		return (ft_printf("valid map\nreached max height"), 0);
	while(y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			map->map_dup[y][x] = map->map[y][x];
			x++;			
		}
		y++;
	}
	first_depth(map->p_ypos, map->p_xpos, map);
	y = 0;
	while(y < map->y)
	{
		x = 0;
		while (x < map->x)
			if(map->map_dup[y][x++] == 'C' || map->map_dup[y][x++] == 'E')
				return (ft_printf("Not Valid Path"), 0);
		y++;
	}
	return 1;
}