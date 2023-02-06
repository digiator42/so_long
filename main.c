/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:21:52 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/06 16:41:17 by ahassan          ###   ########.fr       */
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

void check_line(char *line, int i, int len)
{
	int j;

	j = 0;
	// write(1, line, strlen(line));
	while(line[j] && line[j] != '\n')
	{
		if((i == 0 || i == len-1) && line[j] != '1')
			return (printf("not 1"), free(line), exit(0));
		j++;
	}
}

void read_map(char *arg)
{
	int i;
	int len;
	char *line;
	
	i = 0;
	len = 0;
	int fd = open(arg, O_RDONLY);
	while(get_next_line(fd))
		len++;
	close(fd);
	
	fd = open(arg, O_RDONLY);
	i = 0;
	while(1)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		check_line(line, i, len);
		i++;
	}
}


int	main(int ac, char **av)
{
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
	read_map(av[1]);
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
