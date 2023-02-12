/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:49:52 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/12 23:18:25 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	first_depth(int py, int px, t_map *path)
{
	int x;
 	ft_printf("%c %d %d\n", path->map_dup[py][px], py, px);
	if(path->map_dup[py][px] == '1' || path->map_dup[py][px] == 'M')
		return ;	
	static int i = 1;
	path->map_dup[py][px] = 'M';
	first_depth(py, px+1, path);

}

void valid_path(t_map *map)
{	
	int x;
	int y = 0;
	if(map->y > MAX_H || map->x > MAX_W)
		(ft_printf("valid map\nreached max height"), exit(0));
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
	map->dupc_cnt = map->c_cnt;
	map->dupe_cnt = map->e_cnt;
	first_depth(map->p_ypos, map->p_xpos, map);
	y = 0;
	while(y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			ft_printf("%c", map->map_dup[y][x]);
			x++;			
		}
		ft_printf("\n");
		y++;
	}
}