/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:02:57 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/11 15:10:34 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_player_right(t_map *map)
{
	if (map->map[map->p_ypos][map->p_xpos+1] == '0'){
		ft_printf("%d %d\n", map->p_ypos, map->p_xpos);
		(++map->p_xpos, draw_map(map));
		map->map[map->p_ypos][map->p_xpos-1] = '0';
	}
}

void move_player_left(t_map *map)
{
	ft_printf("%d %d\n", map->p_ypos, map->p_xpos);
	if (map->map[map->p_ypos][map->p_xpos-1] == '0')
		(--map->p_xpos, draw_map(map));
}

void move_player_up(t_map *map)
{
	ft_printf("%d %d\n", map->p_ypos, map->p_xpos);
	if (map->map[map->p_ypos-1][map->p_xpos] == '0')
		(--map->p_ypos, draw_map(map));
}

void move_player_down(t_map *map)
{
	ft_printf("%d %d\n", map->p_ypos, map->p_xpos);
	if (map->map[map->p_ypos+1][map->p_xpos] == '0')
		(++map->p_ypos, draw_map(map));
}