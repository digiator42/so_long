/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:21:52 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/07 17:04:10 by ahassan          ###   ########.fr       */
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
	if(!map_requisite(map, h))
		return 0;
	return 1;
}


void read_map(char *arg, t_map *map)
{
	int i;
	char *line;
	
	map->y = 0;
	int fd = open(arg, O_RDONLY);
	while((line = get_next_line(fd)))
		(free(line), map->y++);
	close(fd);
	map->map = malloc(sizeof(char *) * (map->y + 1));
	map->map[map->y] = NULL;
	fd = open(arg, O_RDONLY);
	i = 0;
	while(1)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		map->map[i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
		ft_strcpy(map->map[i], line);
		free(line);
		i++;
	}
	map->x = ft_strlen(map->map[0]) - 1;
}

int parsing(int ac, char **av, t_map *map)
{
	if(ac != 2)
		return 0;
	read_map(av[1], map);
	if(!is_valid_name(av[1]) || !valid_map(map))
		return 0;
	return 1;	
}

void draw_map(t_map *map)
{
	void *mlx;
	int y;
	int x=0;
	// void *mlx_win = NULL;
	void *image;
	int w = 64;
	int h = 64;
	
	mlx = mlx_init();
	map->img = mlx_new_window(mlx, 1280, 640, "so_long");
	image = mlx_xpm_file_to_image(mlx, "includes/space.xpm", &w, &h);
	y = 0;
	while (y <= 640)
	{
		x = 0;
		while(x <= 1280)
		{
			mlx_put_image_to_window(mlx, map->img, image, x, y);
			x += 64;
		}
		y += 64;
	}	
	mlx_loop(mlx);
}

int	main(int ac, char **av)
{
	t_map map;
	
	
	if(!parsing(ac, av, &map))
		write(2, "ERROR\n", 6);
	while(*map.map)
		printf("%s", *map.map++);
	fflush(stdout);	
	draw_map(&map);
}


