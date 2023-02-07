/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:10:19 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/07 16:46:45 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include "mlx/mlx.h"
// # include <mlx.h>
# include <stdio.h>
// # include <zlib.h>
# include <string.h>

typedef struct s_map
{
	char	**map;
	void	*img;
	char	*addr;
	int	x;
	int	y;
	int c_cnt;
	int p_index;
	int e_index;
	int	bits_per_pixel;
	int	line_length;
} t_map;

char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(const char *s);
int	ft_strcmp(char *s1, char *s2);
#endif