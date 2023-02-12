/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:10:19 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/12 22:42:18 by ahassan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

enum
{
	ON_KEYDOWN = 125,
	ON_KEYUP = 126,
	ON_KEYLEFT = 123,
	ON_KEYRIGHT = 124,
	ON_W = 13,
	ON_A = 0,
	ON_D = 2,
	ON_S = 1,
	ON_DESTROY = 53,
	MAX_H = 200,
	MAX_W = 200
};

typedef struct s_map
{
	char	**map;
	char 	map_dup[MAX_H][MAX_W];
	void	*img;
	char	*addr;
	void	*mlx;
	void	*player;
	void	*wall;
	void	*coin;
	void	*space;
	void	*exit;
	int		x;
	int		y;
	int		p_ypos;
	int		p_xpos;
	int		xpos;
	int		ypos;
	int		h;
	int		l;
	int		w;
	int		v;
	int 	total_moves;
	int		c_cnt;
	int		e_cnt;
	int		dupc_cnt;
	int		dupe_cnt;
	int		valid;
}			t_map;

int			parsing(int ac, char **av, t_map *map);
void		draw_map(t_map *map);
void 		valid_path(t_map *map);
char		*ft_strcpy(char *dest, char *src);
char		*ft_strdup(const char *s);
int			ft_strcmp(char *s1, char *s2);
int			ft_len(const char *c);
void		header_footer(char *line);
int			map_requisite(t_map *map, int h);
int			valid_map(t_map *map);
int			is_valid_name(char *str);
void		move_player_right(t_map *map);
void		move_player_left(t_map *map);
void		move_player_up(t_map *map);
void		move_player_down(t_map *map);
void		header_footer(char *line);
int			is_required(char c);
void		is_equal(t_map *map);
void		free_map(t_map *map);
#endif