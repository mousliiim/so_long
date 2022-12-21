/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamemlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 23:20:19 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/21 07:41:20 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_tab_fill_xpm(t_startmlx *gplay)
{
	int	r;
	int	j;

	r = 0;
	j = -1;
	gplay->img[0] = mlx_xpm_file_to_image(gplay->mlx, "img/player.xpm", &r, &r);
	gplay->img[1] = mlx_xpm_file_to_image(gplay->mlx, "img/exit.xpm", &r, &r);
	gplay->img[2] = mlx_xpm_file_to_image(gplay->mlx, "img/wall.xpm", &r, &r);
	gplay->img[3] = mlx_xpm_file_to_image(gplay->mlx, "img/collec.xpm", &r, &r);
	gplay->img[4] = mlx_xpm_file_to_image(gplay->mlx, "img/floor.xpm", &r, &r);
	gplay->img[5] = 0;
	while (gplay->img[++j])
		gplay->nbrimg++;
}

int	deal_key(int keysym, t_startmlx *gplay)
{
	if (keysym == ESCAPE)
	{
		if (gplay->coin != 0)
			ft_printf("\n%s\tVous n'avez pas recuperer : %d Collectible(s)%s\n",
				RED, gplay->coin, END);
		else
			ft_printf("\n\t%sVous avez recuperer : %d Collectible(s)%s\n",
				GREEN, gplay->needcoin, END);
		if (gplay->unlock == 1
			&& gplay->map[gplay->start[0]][gplay->start[1]] ==
			gplay->map[gplay->exit[0]][gplay->exit[1]])
			ft_printf("%s\tVous avez utiliser la sortie !%s\n\n", GREEN, END);
		else
			ft_printf("%s\t  Vous n'avez pas utiliser la sortie%s\n\n", RED, END);
		mlx_loop_end(gplay->mlx);
		return (0);
	}
	if (keysym == D)
	{
		if (gplay->map[gplay->start[0]][gplay->start[1] + 1] != '1')
		{
			if (gplay->map[gplay->start[0]][gplay->start[1] + 1] == 'C' &&
				gplay->coin != 0)
			{
				gplay->coin--;
				gplay->needcoin++;
				if (gplay->coin == 1)
					gplay->map[gplay->exit[0]][gplay->exit[1]] = 'E';
			}
			if (gplay->unlock == 1
				&& gplay->map[gplay->start[0]][gplay->start[1]] ==
				gplay->map[gplay->exit[0]][gplay->exit[1]])
			{
				ft_printf("%s\tVous avez utiliser la sortie !%s\n\n", GREEN, END);
				mlx_loop_end(gplay->mlx);
			}
			gplay->map[gplay->start[0]][gplay->start[1] + 1] = 'P';
			gplay->map[gplay->start[0]][gplay->start[1]] = '0';
			gplay->start[1] += 1;
			gplay->step++;
			ft_printf("\t-> Nombre de Pas : [ %s%d%s ] <-\n",
				GREEN, gplay->step, END);
		}
		ft_fillmap(gplay);
		ft_display(gplay->map);
	}
	if (keysym == A)
	{
		if (gplay->map[gplay->start[0]][gplay->start[1] - 1] != '1')
		{
			if (gplay->map[gplay->start[0]][gplay->start[1] - 1] == 'C' &&
				gplay->coin != 0)
			{
				gplay->coin--;
				gplay->needcoin++;
				if (gplay->coin == 1)
					gplay->map[gplay->exit[0]][gplay->exit[1]] = 'E';
			}
			if (gplay->unlock == 1
				&& gplay->map[gplay->start[0]][gplay->start[1]] ==
				gplay->map[gplay->exit[0]][gplay->exit[1]])
			{
				ft_printf("%s\tVous avez utiliser la sortie !%s\n\n", GREEN, END);
				mlx_loop_end(gplay->mlx);
			}
			gplay->map[gplay->start[0]][gplay->start[1] - 1] = 'P';
			gplay->map[gplay->start[0]][gplay->start[1]] = '0';
			gplay->start[1] -= 1;
			gplay->step++;
			ft_printf("\t-> Nombre de Pas : [ %s%d%s ] <-\n",
				GREEN, gplay->step, END);
		}
		ft_fillmap(gplay);
		ft_display(gplay->map);
	}
	if (keysym == W)
	{
		if (gplay->map[gplay->start[0] - 1][gplay->start[1]] != '1')
		{
			if (gplay->map[gplay->start[0] - 1][gplay->start[1]] == 'C' &&
				gplay->coin != 0)
			{
				gplay->coin--;
				gplay->needcoin++;
				if (gplay->coin == 1)
					gplay->map[gplay->exit[0]][gplay->exit[1]] = 'E';
			}
			if (gplay->unlock == 1
				&& gplay->map[gplay->start[0]][gplay->start[1]] ==
				gplay->map[gplay->exit[0]][gplay->exit[1]])
			{
				ft_printf("%s\tVous avez utiliser la sortie !%s\n\n", GREEN, END);
				mlx_loop_end(gplay->mlx);
			}
			gplay->map[gplay->start[0] - 1][gplay->start[1]] = 'P';
			gplay->map[gplay->start[0]][gplay->start[1]] = '0';
			gplay->start[0] -= 1;
			gplay->step++;
			ft_printf("\t-> Nombre de Pas : [ %s%d%s ] <-\n",
				GREEN, gplay->step, END);
		}
		ft_fillmap(gplay);
		ft_display(gplay->map);
	}
	if (keysym == S)
	{
		if (gplay->map[gplay->start[0] + 1][gplay->start[1]] != '1')
		{
			printf("%d Coin\n", gplay->coin);
			if (gplay->map[gplay->start[0] + 1][gplay->start[1]] == 'C' &&
				gplay->coin != 0)
			{
				gplay->coin--;
				gplay->needcoin++;
				if (gplay->unlock == 1)
					gplay->map[gplay->exit[0]][gplay->exit[1]] = 'E';
			}
			if (gplay->unlock == 1
				&& gplay->map[gplay->start[0]][gplay->start[1]] ==
				gplay->map[gplay->exit[0]][gplay->exit[1]])
			{
				ft_printf("%s\tVous avez utiliser la sortie !%s\n\n", GREEN, END);
				mlx_loop_end(gplay->mlx);
			}
			gplay->map[gplay->start[0] + 1][gplay->start[1]] = 'P';
			gplay->map[gplay->start[0]][gplay->start[1]] = '0';
			gplay->start[0] += 1;
			gplay->step++;
			ft_printf("\t-> Nombre de Pas : [ %s%d%s ] <-\n",
				GREEN, gplay->step, END);
		}
		ft_fillmap(gplay);
		ft_display(gplay->map);
	}
	return (0);
}

void	ft_put_image_window(t_startmlx *gplay, int y, int x)
{
	if (gplay->map[y][x] == 'P')
		mlx_put_image_to_window(gplay->mlx, gplay->mlx_win,
			gplay->img[0], x * 64, y * 64);
	if (gplay->map[y][x] == '1')
		mlx_put_image_to_window(gplay->mlx, gplay->mlx_win,
			gplay->img[2], x * 64, y * 64);
	if (gplay->map[y][x] == 'C')
		mlx_put_image_to_window(gplay->mlx, gplay->mlx_win,
			gplay->img[3], x * 64, y * 64);
	if (gplay->map[y][x] == 'E')
	{
		if (gplay->coin == 0)
		{
			mlx_put_image_to_window(gplay->mlx, gplay->mlx_win,
				gplay->img[1], x * 64, y * 64);
			gplay->unlock = 1;
		}
		if (gplay->coin != 0)
		{
			mlx_put_image_to_window(gplay->mlx, gplay->mlx_win,
				gplay->img[4], x * 64, y * 64);
			gplay->unlock = 0;
		}
	}
	if (gplay->map[y][x] == '0')
		mlx_put_image_to_window(gplay->mlx, gplay->mlx_win,
			gplay->img[4], x * 64, y * 64);
}

void	ft_fillmap(t_startmlx *gplay)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < (int)gplay->size_y)
	{
		x = 0;
		while (gplay->map[y][x])
		{
			ft_put_image_window(gplay, y, x);
			x++;
		}
	y++;
	}
	ft_printf("\nPosition du E : [%d][%d]\n", gplay->exit[0], gplay->exit[1]);
	ft_printf(" UNLOCK VALEUR = %d\n", gplay->unlock);
	if (gplay->unlock == 1
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