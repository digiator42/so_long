/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:02:57 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/14 17:50:42 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player_right(t_map *map)
{
	if (map->map[map->p_ypos][map->p_xpos + 1] == '0'
		|| map->map[map->p_ypos][map->p_xpos + 1] == 'C')
	{
		ft_printf("total moves %d\n", ++map->total_moves);
		if (map->map[map->p_ypos][map->p_xpos + 1] == 'C')
			map->c_cnt--;
		++map->p_xpos;
		draw_map(map);
		map->map[map->p_ypos][map->p_xpos - 1] = '0';
		map->map[map->p_ypos][map->p_xpos] = '0';
	}
	else if (map->map[map->p_ypos][map->p_xpos + 1] == 'E')
	{
		if (!map->c_cnt)
			(x_click(map));
	}
}

void	move_player_left(t_map *map)
{
	if (map->map[map->p_ypos][map->p_xpos - 1] == '0'
		|| map->map[map->p_ypos][map->p_xpos - 1] == 'C')
	{
		ft_printf("total moves %d\n", ++map->total_moves);
		if (map->map[map->p_ypos][map->p_xpos - 1] == 'C')
			map->c_cnt--;
		--map->p_xpos;
		draw_map(map);
		map->map[map->p_ypos][map->p_xpos + 1] = '0';
		map->map[map->p_ypos][map->p_xpos] = '0';
	}
	else if (map->map[map->p_ypos][map->p_xpos - 1] == 'E')
	{
		if (!map->c_cnt)
			(x_click(map));
	}
}

void	move_player_up(t_map *map)
{
	if (map->map[map->p_ypos - 1][map->p_xpos] == '0' || map->map[map->p_ypos
		- 1][map->p_xpos] == 'C')
	{
		ft_printf("total moves %d\n", ++map->total_moves);
		if (map->map[map->p_ypos - 1][map->p_xpos] == 'C')
			map->c_cnt--;
		--map->p_ypos;
		draw_map(map);
		map->map[map->p_ypos + 1][map->p_xpos] = '0';
		map->map[map->p_ypos][map->p_xpos] = '0';
	}
	else if (map->map[map->p_ypos - 1][map->p_xpos] == 'E')
	{
		if (!map->c_cnt)
			(x_click(map));
	}
}

void	move_player_down(t_map *map)
{
	if (map->map[map->p_ypos + 1][map->p_xpos] == '0' || map->map[map->p_ypos
		+ 1][map->p_xpos] == 'C')
	{
		ft_printf("total moves %d\n", ++map->total_moves);
		if (map->map[map->p_ypos + 1][map->p_xpos] == 'C')
			map->c_cnt--;
		++map->p_ypos;
		draw_map(map);
		map->map[map->p_ypos - 1][map->p_xpos] = '0';
		map->map[map->p_ypos][map->p_xpos] = '0';
	}
	else if (map->map[map->p_ypos + 1][map->p_xpos] == 'E')
	{
		if (!map->c_cnt)
			(x_click(map));
	}
}
