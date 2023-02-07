/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:21:52 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/07 13:27:25 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_valid(char *str)
{
	int len;
	
	len = ft_strlen(str);
	if(!len)
		return 0;
	if(str[len-1] != 'r' || str[len-2] != 'e' 
		|| str[len-3] != 'b' || str[len-4] != '.')
			return 0;
	return 1;		
}

int parsing(int ac, char **av)
{
	if(ac != 2)
		return 0;

	if(!is_valid(av[1]))
		return 0;	
	return 1;	
}

int valid(char **map)
{
	int y = 0;
	while (map[y])
	{
		if(map[y][0] != '1')
			return 0;
		y++;
	}
	y = 0;
	int len = ft_strlen(map[y]) - 1;
	while(map[y][len])
	{
		if(map[y][len] != '1')
			return(0);
		y++;
	}
	return 1;
}

void header_footer(char *line, int i, int len)
{
	int j;

	j = 0;
	
	while(line[j] && line[j] != '\n')
	{
		if((i == 0 || i == len-1) && line[j] != '1')
			return (printf("not 1"), free(line), exit(0));
		j++;
	}
	
}

void read_map(char *arg, t_map *map)
{
	int i;
	int height;
	char *line;
	
	height = 0;
	int fd = open(arg, O_RDONLY);
	while((line = get_next_line(fd)))
		(free(line), height++);
	close(fd);
	map->map = malloc(sizeof(char *) * (height + 1));
	map->map[height] = NULL;
	fd = open(arg, O_RDONLY);
	i = 0;
	while(1)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		map->map[i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
		strcpy(map->map[i], line);
		free(line);
		i++;
	}
}


int	main(int ac, char **av)
{
	t_map map;
	// void *mlx;
	// // void *mlx_win = NULL;
	// t_data img;
	// void *image;
	// int w = 32;
	// int h = 32;
	
	// img.x = 0;
	// img.y = 0;
	
	if(!parsing(ac, av))
		write(2, "ERROR\n", 6);
	read_map(av[1], &map);
	while(*(map.map))
		printf("%s", *(map.map)++);
	// mlx = mlx_init();
	// img.img = mlx_new_window(mlx, 1280, 640, "so_long");
	// image = mlx_xpm_file_to_image(mlx, "space.xpm", &w, &h);
	// while (img.y <= 640)
	// {
	// 	img.x = 0;
	// 	while(img.x <= 1280)
	// 	{
	// 		mlx_put_image_to_window(mlx, img.img, image, img.x, img.y);
	// 		img.x += 64;
	// 	}
	// 	img.y += 64;
	// }	


	// // /****************/
	// image = mlx_xpm_file_to_image(mlx, "sponcha.xpm", &w, &h);
	// mlx_put_image_to_window(mlx, img.img, image, 640, 320);
	// mlx_loop(mlx);
}


