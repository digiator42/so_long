/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:00:35 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/07 22:00:50 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_valid_name(char *str)
{	
	while(*str != '.')
		str++;
	if(ft_strcmp((char *)str, ".ber"))
		return (printf("wrong name"));
	return 1;		
}


void header_footer(char *line)
{
	int j = 0;
	while(line[j])
	{
		if(line[j] != '1' && line[j] != '\n')
			return (printf("not 1"), exit(0));
		j++;
	}
}

int map_requisite(t_map *map, int h)
{
	int x;
	int y;
	int count;

	count = 0;
	y = 1;
	while(y < h)
	{
		x = 0;
		while (map->map[y][x] && map->map[y][x] != '\n')
		{
			if(map->map[y][x] == 'C')
				map->c_cnt++;
			if(map->map[y][x] == 'P')
				count++;
			if(map->map[y][x] == 'E')
				count++;
			x++;
		}
		y++;
	}
	if(count > 2)
		return (printf("wrong requisite"), 0);
	return 1;	
}

int valid_map(t_map *map)
{
	int h = 0;
	while (map->map[h])
	{
		if(map->map[h][0] != '1')
			return (printf("y not valid"), 0);
		h++;
	}
	int x = 0;
	int len = ft_strlen(map->map[x]) - 2;
	while(map->map[x])
	{
		if(x == 0 || x == h-1)
			header_footer(map->map[x]);
		if(map->map[x][len] != '1')
			return(printf("x not valid"), 0);
		x++;
	}
	if(!map_requisite(map, h) || (map->x == map->y))
		return 0;
	return 1;
}

void is_equal(t_map *map)
{
	map->ypos = 0;
	while(map->map[map->ypos])
	{
		map->xpos = map->ypos + 1;
		if(ft_len(map->map[map->ypos]) < ft_len(map->map[map->xpos]))
			(printf("not equal"), exit(0));
		map->ypos++;
	}
}