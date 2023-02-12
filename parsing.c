/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:00:35 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/13 00:38:22 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_requisite(t_map *map, int h)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 1;
	map->e_cnt = 0;
	while (y < h)
	{
		x = 0;
		while (map->map[y][x] && map->map[y][x] != '\n')
		{
			if (!is_required(map->map[y][x]))
				return (0);
			if (map->map[y][x] == 'C')
				map->c_cnt++;
			if (map->map[y][x] == 'P')
				(count++, 
				(map->p_ypos = y), 
				(map->p_xpos = x));
			if (map->map[y][x] == 'E')
				(count++, map->e_cnt++);
			x++;
		}
		y++;
	}
	if (count != 2)
		return (ft_printf("Wrong requisite"), 0);
	return (1);
}

int	valid_map(t_map *map)
{
	int	h;
	int	x;
	int	len;

	h = 0;
	while (map->map[h])
	{
		if (map->map[h][0] != '1')
			return (ft_printf("Y not valid"), 0);
		h++;
	}
	x = 0;
	len = ft_strlen(map->map[x]) - 2;
	while (map->map[x])
	{
		if (x == 0 || x == h - 1)
			header_footer(map->map[x]);
		if (map->map[x][len] != '1')
			return (ft_printf("X not valid"), 0);
		x++;
	}
	if (!map_requisite(map, h) || (map->x == map->y))
		return (0);
	return (1);
}

int	read_map(char *arg, t_map *map)
{
	int		i;
	char	*line;
	int		fd;

	map->y = 0;
	fd = open(arg, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		(free(line), map->y++);
	}
	close(fd);
	map->map = malloc(sizeof(char *) * (map->y + 1));
	map->map[map->y] = NULL;
	fd = open(arg, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->map[i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
		ft_strcpy(map->map[i], line);
		free(line);
		i++;
	}
	close(fd);
	map->x = ft_strlen(map->map[0]) - 1;
	return 1;
}

int	parsing(int ac, char **av, t_map *map)
{
	if (ac != 2)
		return (0);
	read_map(av[1], map);
	if (!is_valid_name(av[1]) || !valid_map(map) || !is_equal(map))
		return (0);
	return (1);
}
