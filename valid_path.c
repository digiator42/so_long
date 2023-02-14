/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:49:52 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/14 13:57:18 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	first_depth(int py, int px, t_map *path)
{
	if (path->dup_map[py][px] == '1' || path->dup_map[py][px] == 'X')
		return ;
	if (path->dup_map[py][px] == 'E')
	{
		path->dupe_cnt--;
		path->dup_map[py][px] = 'X';
		return ;
	}
	path->dup_map[py][px] = 'X';
	first_depth(py, px + 1, path);
	first_depth(py, px - 1, path);
	first_depth(py - 1, px, path);
	first_depth(py + 1, px, path);
}

int	is_valid_path(t_map *map)
{
	int	y;
	int	x;

	first_depth(map->p_ypos, map->p_xpos, map);
	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->dup_map[y][x] == 'C' || map->dupe_cnt)
				return (ft_printf("Not Valid Path"), 0);
			x++;
		}
		y++;
	}
	return (1);
}
