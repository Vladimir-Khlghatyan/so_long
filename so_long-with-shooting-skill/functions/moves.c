/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:53:15 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 16:53:19 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_step(t_long *sl, int x_step, int y_step)
{
	if (x_step * y_step == 0 && \
		(x_step + y_step == -1 || x_step + y_step == 1))
	{
		sl->map[sl->pl_y + y_step][sl->pl_x + x_step] = 'P';
		sl->map[sl->pl_y][sl->pl_x] = '0';
		sl->pl_x += x_step;
		sl->pl_y += y_step;
		sl->moves++;
		print_in_terminal(sl);
	}
}

void	ft_move(t_long *sl, int x_step, int y_step)
{
	if (sl->map[sl->pl_y + y_step][sl->pl_x + x_step] == '0')
		ft_step(sl, x_step, y_step);
	else if (sl->map[sl->pl_y + y_step][sl->pl_x + x_step] == 'C')
	{
		ft_step(sl, x_step, y_step);
		sl->collected++;
	}
	else if (sl->map[sl->pl_y + y_step][sl->pl_x + x_step] == 'E' && \
		sl->collected == sl->coins)
	{
		ft_step(sl, x_step, y_step);
		showerror("\n\33[1;32mYou won!\n", sl);
	}
	else if (sl->map[sl->pl_y + y_step][sl->pl_x + x_step] == 'T')
	{
		ft_step(sl, x_step, y_step);
		showerror("\n\33[1;31mYou lost!\n", sl);
	}
}
