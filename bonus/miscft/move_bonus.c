/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 23:20:19 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/27 00:30:13 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	ft_esc(t_startmlx *gplay)
{
	if (gplay->coin != 0)
		ft_printf("\n%s\tVous n'avez pas recuperer : %d Collectible(s)%s\n",
			RED, gplay->coin, END);
	else
		ft_printf("\n\t%sVous avez recuperer : %d Collectible(s)%s\n",
			GREEN, gplay->needcoin, END);
	if (gplay->coin == 0
		&& gplay->map[gplay->start[0]][gplay->start[1]] ==
		gplay->map[gplay->exit[0]][gplay->exit[1]])
		ft_printf("%s\tVous avez utiliser la sortie !%s\n\n", GREEN, END);
	else
		ft_printf("%s\t  Vous n'avez pas utiliser la sortie%s\n", RED, END);
	mlx_loop_end(gplay->mlx);
	return (0);
}

static void	ft_move(t_startmlx *gplay, int m_x, int m_y, int op)
{
	if (gplay->map[gplay->start[0] + m_y][gplay->start[1] + m_x] != '1')
	{
		if (gplay->map[gplay->start[0] + m_y][gplay->start[1] + m_x] == 'M')
		{
			ft_esc(gplay);
			ft_printf("\t\t%sEn plus tu est mort 😢%s\n", RED, END);
		}
		if (gplay->map[gplay->start[0] + m_y][gplay->start[1] + m_x] == 'C' &&
				gplay->coin != 0)
		{
			gplay->coin--;
			gplay->needcoin++;
			if (gplay->coin == 0)
				gplay->map[gplay->exit[0]][gplay->exit[1]] = 'E';
		}
		gplay->map[gplay->start[0] + m_y][gplay->start[1] + m_x] = 'P';
		gplay->map[gplay->start[0]][gplay->start[1]] = '0';
		if (op == 1)
			gplay->start[0] = gplay->start[0] + (m_x + m_y);
		if (op == 0)
			gplay->start[1] += (m_x + m_y);
		gplay->step++;
	}
	ft_fillmap(gplay);
}

int	deal_key(int keysym, t_startmlx *gplay)
{
	if (gplay->rand == 1)
		gplay->rand = 2;
	else
		gplay->rand = 1;
	if (keysym == ESC)
		ft_esc(gplay);
	if (keysym == D)
		ft_move(gplay, 1, 0, 0);
	if (keysym == A)
		ft_move(gplay, -1, 0, 0);
	if (keysym == W)
		ft_move(gplay, 0, -1, 1);
	if (keysym == S)
		ft_move(gplay, 0, 1, 1);
	if (keysym == StructureNotifyMask)
		ft_esc(gplay);
	return (0);
}

static void	ft_put_image_window(t_startmlx *gplay, int y, int x)
{
	if (gplay->map[y][x] == 'P')
	{
		ft_put_image(gplay, 0, x, y);
		if (gplay->rand == 1)
			ft_put_image(gplay, 1, x, y);
		if (gplay->rand == 2)
			ft_put_image(gplay, 0, x, y);
	}
	if (gplay->map[y][x] == '1')
		ft_put_image(gplay, 3, x, y);
	if (gplay->map[y][x] == 'C')
		ft_put_image(gplay, 4, x, y);
	if (gplay->map[y][x] == 'E')
	{
		if (gplay->coin == 0)
			ft_put_image(gplay, 2, x, y);
		if (gplay->coin != 0)
			ft_put_image(gplay, 5, x, y);
	}
	if (gplay->map[y][x] == '0')
		ft_put_image(gplay, 5, x, y);
	if (gplay->map[y][x] == 'M')
		ft_put_image(gplay, 6, x, y);
}

void	ft_fillmap(t_startmlx *gplay)
{
	int	x;
	int	y;
	int	xx;
	int	yy;

	x = 0;
	y = -1;
	if (gplay->coin == 0)
				gplay->map[gplay->exit[0]][gplay->exit[1]] = 'E';
	while (++y < (int)gplay->size_y)
	{
		x = 0;
		while (x < (int)gplay->size_x)
			ft_put_image_window(gplay, y, x++);
	}
	xx = -1;
	yy = gplay->size_y - 1;
	while (++yy < (int)gplay->size_y + 1)
	{
		while (++xx < (int)gplay->size_x)
			ft_put_image(gplay, 5, xx, yy);
	}
	ft_display_bonus_counter(gplay, gplay->step, x - 1);
	ft_display_player_in_exit(gplay);
}
