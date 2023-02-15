/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:00:35 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/15 21:10:41 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_requisite(t_map *m)
{
	m->y = 1;
	while (m->y < m->h)
	{
		m->x = 0;
		while (m->map[m->y][m->x] && m->map[m->y][m->x] != '\n')
		{
			if (!is_required(m->map[m->y][m->x]))
				return (0);
			if (m->map[m->y][m->x] == 'C')
				m->c_cnt++;
			if (m->map[m->y][m->x] == 'P')
			{
				m->p_cnt++;
				m->p_ypos = m->y;
				m->p_xpos = m->x;
			}
			if (m->map[m->y][m->x] == 'E')
				m->dupe_cnt++;
			m->x++;
		}
		m->y++;
	}
	return (1);
}

int	valid_map(t_map *m)
{
	int	len;

	m->h = 0;
	m->x = 0;
	while (m->map[m->h])
	{
		if (m->map[m->h][0] != '1')
			return (ft_printf("Error\n1st col not valid"), 0);
		m->h++;
	}
	m->x = 0;
	len = ft_len(m->map[m->x]) - 1;
	while (m->map[m->x])
	{
		if (m->x == 0 || m->x == m->h - 1)
			if (!header_footer(m->map[m->x]))
				return (ft_printf("Error\nNot 1 header footer"), 0);
		if (m->map[m->x][len] != '1')
			return (ft_printf("Error\nlast col not valid"), 0);
		m->x++;
	}
	if (!map_requisite(m) || m->p_cnt != 1
		|| m->dupe_cnt != 1 || !m->c_cnt)
		return (ft_printf("Error\nWrong requisite\n"), 0);
	return (1);
}

int	read_map(char *arg, t_map *map)
{
	int		i;
	char	*line;
	int		fd;

	map->map = malloc(sizeof(char *) * (map->y + 1));
	map->dup_map = malloc(sizeof(char *) * (map->y + 1));
	map->map[map->y] = NULL;
	map->dup_map[map->y] = NULL;
	fd = open(arg, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->map[i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
		map->dup_map[i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
		ft_strcpy(map->map[i], line);
		ft_strcpy(map->dup_map[i], line);
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
	map->p_cnt = 0;
	map->dupe_cnt = 0;
	map->c_cnt = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1 || !is_valid_name(av[1]))
		return (ft_printf("Error\nNot valid"), 0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		(free(line), map->y++);
	}
	close(fd);
	read_map(av[1], map);
	if (!is_equal(map) || !valid_map(map) || !is_valid_path(map))
		return (free_map(map->map), free_map(map->dup_map), 0);
	return (1);
}
