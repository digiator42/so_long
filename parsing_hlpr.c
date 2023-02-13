/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_hlpr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:35:52 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/13 23:11:39 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_images(t_map *all)
{
	mlx_destroy_image(all->mlx, all->coin);
	mlx_destroy_image(all->mlx, all->player);
	mlx_destroy_image(all->mlx, all->wall);
	mlx_destroy_image(all->mlx, all->space);
}
int	x_click(t_map *m)
{
	free_map(m);
	destroy_images(m);
	mlx_destroy_window(m->mlx, m->img);
	exit(0);
}

int	is_valid_name(char *str)
{
	while (*str != '.')
		str++;
	if (ft_strcmp((char *)str, ".ber"))
		return (ft_printf("wrong name"), 0);
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
	int y;
	
	y = 0;
	while (map->map[y])
	{
		int x = y + 1;
		if (map->map[x] && ft_len(map->map[y]) != ft_len(map->map[x]))
		{
			ft_printf("%d %d", ft_len(map->map[y]), ft_len(map->map[x]));
			return (ft_printf("Not equal\n"), 0);
		}
		y++;
	}
	return (1);
}