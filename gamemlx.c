/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamemlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 23:20:19 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/20 21:38:33 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_tab_fill_xpm(t_startmlx *gplay)
{
	int	r;

	gplay->img[0] = mlx_xpm_file_to_image(gplay->mlx, "img/player.xpm", &r, &r);
	gplay->img[1] = mlx_xpm_file_to_image(gplay->mlx, "img/exit.xpm", &r, &r);
	gplay->img[2] = mlx_xpm_file_to_image(gplay->mlx, "img/wall.xpm", &r, &r);
	gplay->img[3] = mlx_xpm_file_to_image(gplay->mlx, "img/collec.xpm", &r, &r);
	gplay->img[4] = mlx_xpm_file_to_image(gplay->mlx, "img/floor.xpm", &r, &r);
}

int	deal_key(int keysym, t_startmlx *gplay)
{
	if (keysym == ESCAPE)
	{
		mlx_loop_end(gplay->mlx);
		return (0);
	}
	if (keysym == D)
	{
		if (gplay->map[gplay->start[0]][gplay->start[1] + 1] != '1')
		{
			if (gplay->map[gplay->start[0]][gplay->start[1] + 1] == 'C' && gplay->coin != 0)
			{
				gplay->coin--;
				ft_printf("\nNombre de Collectible Restant : [ %d ]\n", gplay->coin);
			}
			gplay->map[gplay->start[0]][gplay->start[1] + 1] = 'P';
			gplay->map[gplay->start[0]][gplay->start[1]] = '0';
			gplay->start[1] += 1;
			gplay->step++;
			printf("Nombre de Pas : [%d]\n", gplay->step);
		}
		ft_fillmap(gplay);
	}
	if (keysym == A)
	{
		if (gplay->map[gplay->start[0]][gplay->start[1] - 1] != '1')
		{
			if (gplay->map[gplay->start[0]][gplay->start[1] - 1] == 'C' && gplay->coin != 0)
			{
				gplay->coin--;
				ft_printf("\nNombre de Collectible Restant : [ %d ]\n", gplay->coin);
			}
			gplay->map[gplay->start[0]][gplay->start[1] - 1] = 'P';
			gplay->map[gplay->start[0]][gplay->start[1]] = '0';
			gplay->start[1] -= 1;
			gplay->step++;
			printf("Nombre de Pas : [%d]\n", gplay->step);
		}
		ft_fillmap(gplay);
	}
	if (keysym == W)
	{
		if (gplay->map[gplay->start[0] - 1][gplay->start[1]] != '1')
		{
			if (gplay->map[gplay->start[0] - 1][gplay->start[1]] == 'C' && gplay->coin != 0)
			{
				gplay->coin--;
				ft_printf("\nNombre de Collectible Restant : [ %d ]\n", gplay->coin);
			}	
			gplay->map[gplay->start[0] - 1][gplay->start[1]] = 'P';
			gplay->map[gplay->start[0]][gplay->start[1]] = '0';
			gplay->start[0] -= 1;
			gplay->step++;
			printf("Nombre de Pas : [%d]\n", gplay->step);
		}
		ft_fillmap(gplay);
	}
	if (keysym == S)
	{
		if (gplay->map[gplay->start[0] + 1][gplay->start[1]] != '1')
		{
			if (gplay->map[gplay->start[0] + 1][gplay->start[1]] == 'C' && gplay->coin != 0)
			{
				gplay->coin--;
				ft_printf("\nNombre de Collectible Restant : [ %d ]\n", gplay->coin);
			}
			gplay->map[gplay->start[0] + 1][gplay->start[1]] = 'P';
			gplay->map[gplay->start[0]][gplay->start[1]] = '0';
			gplay->start[0] += 1;
			gplay->step++;
			printf("Nombre de Pas : [%d]\n", gplay->step);
		}
		ft_fillmap(gplay);
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
		if (gplay->coin != 0)
			mlx_put_image_to_window(gplay->mlx, gplay->mlx_win,
				gplay->img[4], x * 64, y * 64);
		if (gplay->coin == 0)
			mlx_put_image_to_window(gplay->mlx, gplay->mlx_win,
				gplay->img[4], x * 64, y * 64);
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
}