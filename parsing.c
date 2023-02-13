/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:00:35 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/13 16:51:40 by ahassan          ###   ########.fr       */
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
	map->dupe_cnt = 0;
	map->c_cnt = 0;
	while (y < h)
	{
		x = 0;
		while (map->map[y][x] && map->map[y][x] != '\n')
		{
			if (!is_required(map->map[y][x]))
				return (ft_printf("invalid char %d %d", y, x), 0);
			if (map->map[y][x] == 'C')
				map->c_cnt++;
			if (map->map[y][x] == 'P')
				(count++,
					(map->p_ypos = y),
					(map->p_xpos = x));
			if (map->map[y][x] == 'E')
				(count++, map->dupe_cnt++);
			x++;
		}
		y++;
	}
	if (count != 2 || !map->c_cnt)
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
			return (ft_printf("1st col not valid"), 0);
		h++;
	}
	x = 0;
	len = ft_len(map->map[x]) - 1;
	while (map->map[x])
	{
		if (x == 0 || x == h - 1)
			if(!header_footer(map->map[x]))
				return (ft_printf("Not 1 header footer"), 0);
		if (map->map[x][len] != '1')
			return (ft_printf("last col not valid"), 0);
		x++;
	}
	if (!map_requisite(map, h))
		return (0);
	return (1);
}

int	read_map(char *arg, t_map *map)
{
	int		i;
	char	*line;
	int		fd;

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
	return (1);
}

int	parsing(int ac, char **av, t_map *map)
{
	char	*line;
	int		fd;
	if (ac != 2)
		return (0);
	map->y = 0;
	fd = open(av[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		(free(line), map->y++);
	}
	close(fd);	
	read_map(av[1], map);
	if(map->x == map->y)
		return (ft_printf("is equal"), 0);
	if (!is_valid_name(av[1]) ||  !is_equal(map)
		|| !valid_map(map) || !is_valid_path(map))
		return (0);
	return (1);
}
