/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:07:37 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/18 01:27:01 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_in_terminal(t_long *sl)
{
	ft_putstr("\r");
	ft_putstr("Coins: ");
	ft_putnmb(sl->collected);
	ft_putstr("	Moves: ");
	ft_putnmb(sl->moves);
}

int	key_hook(int keycode, t_long *sl)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(sl->mlx, sl->win);
		exit(1);
	}
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		ft_move(sl, 1, 0);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		ft_move(sl, -1, 0);
	if (keycode == KEY_W || keycode == KEY_UP)
		ft_move(sl, 0, -1);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		ft_move(sl, 0, 1);
	return (0);
}

int	so_long(t_long *sl)
{
	char	*line;

	load_xpm_with_animation(sl);
	mlx_string_put(sl->mlx, sl->win, 45, 45, 0x000000, "Coins: ");
	line = ft_itoa(sl->collected);
	mlx_string_put(sl->mlx, sl->win, 110, 45, 0x000000, line);
	free(line);
	mlx_string_put(sl->mlx, sl->win, 45, 65, 0x000000, "Moves: ");
	line = ft_itoa(sl->moves);
	mlx_string_put(sl->mlx, sl->win, 110, 65, 0x000000, line);
	free(line);
	return (0);
}

int	main(int ac, char **av)
{
	t_long	sl;

	if (ac != 2)
		return (ft_putstr("Inwalid number of agruments!\n"));
	initiator(&sl);
	check_and_create_map(av[1], &sl);
	create_window(&sl);
	mlx_hook(sl.win, 2, 1L << 0, key_hook, &sl);
	mlx_loop_hook(sl.mlx, so_long, &sl);
	mlx_loop(sl.mlx);
	tabfree(sl.map);
	return (0);
}
