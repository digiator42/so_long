/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:49:52 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/13 20:03:50 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	first_depth(t_map *path, int w, char map_dup[][w])
{
	if (map_dup[path->p_ypos][path->p_xpos] == '1' 
		|| map_dup[path->p_ypos][path->p_xpos] == 'X')
			return ;
	if(map_dup[path->p_ypos][path->p_xpos] == 'E')
	{
		path->dupe_cnt--;
		map_dup[path->p_ypos][path->p_xpos] = 'X';
		return ;	
	}
	map_dup[path->p_ypos][path->p_xpos] = 'X';
	first_depth(path, w, map_dup);
	path->p_xpos++;
	first_depth(path, w, map_dup);
	path->p_xpos--;
	first_depth(path, w, map_dup);
	path->p_ypos--;
	first_depth(path, w, map_dup);
	path->p_ypos++;
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
	first_depth(map, map->x, map_dup);
	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			ft_printf("%c", map_dup[y][x]);
			// if (map_dup[y][x] == 'C' || map->dupe_cnt)
			// 	return (ft_printf("Not Valid Path %d %d", y, x), 0);
			x++;	
		}
		ft_printf("\n");
		y++;
	}
	return (1);
}