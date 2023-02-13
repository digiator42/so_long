/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahassan <ahassan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:10:19 by ahassan           #+#    #+#             */
/*   Updated: 2023/02/13 20:10:54 by ahassan          ###   ########.fr       */
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
	ON_KEYLEFT = 123,
	ON_KEYRIGHT,
	ON_KEYDOWN,
	ON_KEYUP,
	ON_W = 13,
	ON_A = 0,
	ON_S,
	ON_D,
	ON_DESTROY = 53,
};

typedef struct s_map
{
	char	**map;
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
	int		px;
	int		py;
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
int 		is_valid_path(t_map *map);
char		*ft_strcpy(char *dest, char *src);
int			ft_strcmp(char *s1, char *s2);
int			ft_len(const char *c);
int			header_footer(char *line);
int			map_requisite(t_map *map, int h);
int			valid_map(t_map *map);
int			is_valid_name(char *str);
void		move_player_right(t_map *map);
void		move_player_left(t_map *map);
void		move_player_up(t_map *map);
void		move_player_down(t_map *map);
int			is_required(char c);
int			is_equal(t_map *map);
void		free_map(t_map *map);
#endif