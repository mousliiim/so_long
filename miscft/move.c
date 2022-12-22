/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 23:20:19 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/22 04:02:02 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	deal_key(int keysym, t_startmlx *gplay)
{
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

int	ft_esc(t_startmlx *gplay)
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
		ft_printf("%s\t  Vous n'avez pas utiliser la sortie%s\n\n", RED, END);
	mlx_loop_end(gplay->mlx);
	return (0);
}

void	ft_move(t_startmlx *gplay, int m_x, int m_y, int op)
{
	if (gplay->map[gplay->start[0] + m_y][gplay->start[1] + m_x] != '1')
	{
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
		ft_printf("\t->Nombre de Pas : [ %s%d%s ]<-\n", GREEN, gplay->step, END);
	}
	ft_fillmap(gplay);
}

void	ft_fillmap(t_startmlx *gplay)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (gplay->coin == 0)
				gplay->map[gplay->exit[0]][gplay->exit[1]] = 'E';
	while (y < (int)gplay->size_y)
	{
		x = 0;
		while (x < (int)gplay->size_x)
			ft_put_image_window(gplay, y, x++);
	y++;
	}
	if (gplay->coin == 0
		&& gplay->map[gplay->start[0]][gplay->start[1]] ==
			gplay->map[gplay->exit[0]][gplay->exit[1]])
	{
		ft_printf("%s\n\t      -> Felicitation ! <-%s\n", GREEN, END);
		ft_printf("%s       -> Vous avez utiliser la sortie ! <-%s\n",
			GREEN, END);
		ft_printf("%s   -> Vous avez recuperer : %d Collectible(s) <-%s\n\n",
			GREEN, gplay->needcoin, END);
		mlx_loop_end(gplay->mlx);
	}
}

void	ft_put_image_window(t_startmlx *gplay, int y, int x)
{
	if (gplay->map[y][x] == 'P')
		ft_put_image(gplay, 0, x, y);
	if (gplay->map[y][x] == '1')
		ft_put_image(gplay, 2, x, y);
	if (gplay->map[y][x] == 'C')
		ft_put_image(gplay, 3, x, y);
	if (gplay->map[y][x] == 'E')
	{
		if (gplay->coin == 0)
			ft_put_image(gplay, 1, x, y);
		if (gplay->coin != 0)
			ft_put_image(gplay, 4, x, y);
	}
	if (gplay->map[y][x] == '0')
		ft_put_image(gplay, 4, x, y);
}
