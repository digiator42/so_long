/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:10:19 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/09 18:56:03 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include "mlx/mlx.h"
// # include <mlx.h>
# include <stdio.h>
// # include <zlib.h>
# include <string.h>

enum {
	ON_KEYDOWN = 125,
	ON_KEYUP = 126,
	ON_KEYLEFT = 123,
	ON_KEYRIGHT = 124,
	ON_W = 13,
	ON_A = 0,
	ON_D = 2,
	ON_X = 7,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 53
};

typedef struct s_map
{
	char	**map;
	void	*img;
	char	*addr;
	void *mlx;
	void *player;
	void *wall;
	void *coin;
	void *space;
	void *exit;
	int	x;
	int	y;
	int	xpos;
	int	ypos;
	int h;
	int l;
	int w;
	int v;
	int c_cnt;
	int	bits_per_pixel;
	int	line_length;
} t_map;

int parsing(int ac, char **av, t_map *map);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(const char *s);
int	ft_strcmp(char *s1, char *s2);
int	ft_len(const char *c);
int is_valid_name(char *str);
void header_footer(char *line);
int map_requisite(t_map *map, int h);
int valid_map(t_map *map);
int is_valid_name(char *str);
void header_footer(char *line);
int is_required(char c);
void is_equal(t_map *map);

#endif