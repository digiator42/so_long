/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:21:52 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/04 22:26:25 by ahassan          ###   ########.fr       */
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

int	main(int ac, char **av)
{
	void *mlx;
	// void *mlx_win = NULL;
	t_data img;
	void *image;
	int w = 32;
	int h = 32;
	
	if(!parsing(ac, av))
		write(2, "ERROR\n", 6);

	mlx = mlx_init();
	img.img = mlx_new_window(mlx, 1000, 500, "so_long");
	image = mlx_xpm_file_to_image(mlx, "burger64.xpm", &w, &h);
	mlx_put_image_to_window(mlx, img.img, image, 0, 0);
	/****************/
	image = mlx_xpm_file_to_image(mlx, "sponcha.xpm", &w, &h);
	mlx_put_image_to_window(mlx, img.img, image, 936, 0);
	mlx_loop(mlx);
}