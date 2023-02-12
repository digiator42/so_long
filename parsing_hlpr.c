/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_hlpr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:35:52 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/13 02:09:54 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_name(char *str)
{
	while (*str != '.')
		str++;
	if (ft_strcmp((char *)str, ".ber"))
		return (ft_printf("wrong name"));
	return (1);
}

int	header_footer(char *line)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (line[j] != '1' && line[j] != '\n')
			return (0);
		j++;
	}
	return (1);
}

int	is_required(char c)
{
	int		i;
	char	*str;

	i = 0;
	str = "1CPE0";
	while (i < 5)
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_equal(t_map *map)
{
	map->ypos = 0;
	while (map->map[map->ypos])
	{
		map->xpos = map->ypos + 1;
		if (map->map[map->xpos] && ft_len(map->map[map->ypos]) != ft_len(map->map[map->xpos]))
			return (ft_printf("Not equal\n"), 0);
		map->ypos++;
	}
	return (1);
}