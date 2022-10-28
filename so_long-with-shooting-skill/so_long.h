/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:38:22 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/18 00:56:55 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define ESC 53
# define UP 126
# define LEFT 123
# define DOWN 125
# define RIGHT 124
# define RED_CROSS 17 

typedef struct s_long
{
	void	*mlx;
	void	*win;
	void	*xpm[12];
	void	*pxl;
	int		wxpm;
	int		hxpm;
	char	**map;
	int		map_x;
	int		map_y;
	int		pl_x;
	int		pl_y;
	int		coins;
	int		collected;
	int		moves;
	int		loop_cnt;
	int		shoot;
	int		shoot_cnt;
}				t_long;

/* libft_utils_1.c */
int		ft_strlen(const char *str);
int		ft_putstr(char *str);
char	*ft_itoa(int n);
void	ft_putnmb(int n);

/* libft_utils_2.c */
char	**tabfree(char **tab);
char	**ft_split(char const *s, char c);
char	*ft_strjoin_free(char *s1, char const *s2);

/* get_next_line.c */
char	*get_next_line(int fd);

/* map_name_and_lines_check.c */
void	map_name_check(char *map_path);
void	showerror(char *str, t_long *sl);
void	check_symbols(char *s, t_long *sl);
void	first_or_last_str(char *s, t_long *sl);
void	mid_str(char *s, t_long *sl);

/* map_values_check.c */
int		rows_in_map(char *map_path, t_long *sl);
char	**clear_carriage_return_from_end_of_strings(char **map);
void	create_map(char *map_path, t_long *sl);
int		maplen(char **map);
void	map_values_check(t_long *sl);

/* check_and_create_map.c */
void	check_and_create_map(char *map_path, t_long *sl);

/* createwindow.c */
void	create_window(t_long *sl);
void	load_xpm_with_animation(t_long *sl);

/* initiator.c */
void	initiator(t_long *sl);

/* moves.c */
void	ft_move(t_long *sl, int x_step, int y_step);

/* so_long.c */
void	print_in_terminal(t_long *sl);
int		key_hook(int keycode, t_long *sl);
int		so_long(t_long *sl);
void	reset_map(t_long *sl);

/* shoots.c */
void	shoot_up(t_long *sl);
void	shoot_down(t_long *sl);
void	shoot_left(t_long *sl);
void	shoot_right(t_long *sl);
void	shoot_reset_map(t_long *sl);

#endif
