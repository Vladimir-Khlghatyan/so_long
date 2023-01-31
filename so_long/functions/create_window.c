/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:53:15 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 16:53:19 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_close(t_long *sl)
{
	mlx_destroy_window(sl->mlx, sl->win);
	exit(1);
}

void	create_window(t_long *sl)
{
	sl->win = mlx_new_window(sl->mlx, (sl->wxpm) * (sl->map_x), \
		(sl->hxpm) * (sl->map_y), "So long!");
	mlx_hook(sl->win, RED_CROSS, 0, ft_close, sl);
	ft_putstr("Coins: 0	Moves: 0");
}

static int	imagecode(char c)
{
	int	i;

	i = 0;
	if (c == '0')
		i = 0;
	else if (c == '1')
		i = 1;
	else if (c == 'P')
		i = 2;
	else if (c == 'E')
		i = 4;
	else if (c == 'C')
		i = 5;
	else if (c == 'T')
		i = 7;
	return (i);
}

static void	load_xpm(t_long *sl)
{
	int	x;
	int	y;
	int	i;

	y = -1;
	while (++y < sl->map_y)
	{
		x = -1;
		while (++x < sl->map_x)
		{
			i = imagecode(sl->map[y][x]);
			if (i == 2 && sl->collected == sl->coins)
				i = 3;
			if (i == 5 && sl->loop_cnt % 24 < 12)
				i = 6;
			if (i == 7 && sl->loop_cnt % 12 < 6)
				i = 8;
			mlx_put_image_to_window(sl->mlx, sl->win, sl->xpm[i], x * sl->wxpm, \
				y * sl->wxpm);
		}
	}
}

void	load_xpm_with_animation(t_long *sl)
{
	sl->loop_cnt++;
	if (sl->loop_cnt == 24)
		sl->loop_cnt = 0;
	// mlx_clear_window(sl->mlx, sl->win);
	load_xpm(sl);
}
