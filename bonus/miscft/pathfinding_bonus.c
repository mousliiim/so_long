/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 23:21:39 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/26 07:56:48 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_check_if_exit(t_map *game)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	while (y < (int)game->size_y)
	{
		x = 0;
		while (game->map[y][x] && x < (int)game->size_x - 1)
		{
			if (game->map[y][x] == 'E' || game->map[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_beforepathfind(t_map *game, int pox, int poy, int *count)
{
	int	pos_x;
	int	pos_y;

	pox = 0;
	poy = 0;
	pos_x = game->start[1];
	pos_y = game->start[0];
	ft_pathfind(game, pos_x, pos_y, count);
	while (poy < (int)game->size_y)
	{
		pox = 0;
		while (pox < (int)game->size_x)
		{
			if (game->map[poy][pox] == 'X')
				ft_pathfind(game, pox, poy, count);
			pox++;
		}
		poy++;
	}
}

static void	ft_swapstruct(t_map *game, t_startmlx *gplay)
{
	gplay->map = game->map;
	gplay->size_x = game->size_x;
	gplay->size_y = game->size_y;
	gplay->coin = game->coin;
	gplay->start[0] = game->start[0];
	gplay->start[1] = game->start[1];
	gplay->exit[0] = game->exit[0];
	gplay->exit[1] = game->exit[1];
	gplay->rand = 2;
}

void	ft_finalmap(t_map *game, char *mapname, t_startmlx *gplay)
{
	ft_freemap(game->map);
	ft_empty_t_map(game);
	check_map(mapname, game);
	ft_swapstruct(game, gplay);
	gplay->mlx = mlx_init();
	if (!gplay->mlx)
		exit(0);
	gplay->mlx_win = mlx_new_window(gplay->mlx, game->size_x * 64,
			game->size_y * 64 + 1 * 64, "so_long");
	if (!gplay->mlx_win)
		exit(0);
	ft_tab_fill_count_xpm(gplay);
	ft_tab_fill_xpm(gplay);
}

void ft_tab_fill_count_xpm(t_startmlx *gplay)
{
	int			r;
	int			j;
	int			i;
	static char	*imgs[10] = {"bonus/img/0.xpm", "bonus/img/1.xpm", \
		"bonus/img/2.xpm", "bonus/img/3.xpm", "bonus/img/4.xpm", \
		"bonus/img/5.xpm", "bonus/img/6.xpm", "bonus/img/7.xpm", \
		"bonus/img/8.xpm", "bonus/img/9.xpm"};

	j = -1;
	i = -1;
	while (++j < 10)
	{
		gplay->counterimg[j] = mlx_xpm_file_to_image(gplay->mlx, imgs[j], &r, &r);
		if (!gplay->counterimg[j])
		{
			ft_freemap(gplay->map);
			while (++i < j)
				mlx_destroy_image(gplay->mlx, gplay->counterimg[i]);
			mlx_clear_window(gplay->mlx, gplay->mlx_win);
			mlx_destroy_window(gplay->mlx, gplay->mlx_win);
			mlx_destroy_display(gplay->mlx);
			free(gplay->mlx);
			ft_msgerror(3);
		}
	}
}

void	ft_tab_fill_xpm(t_startmlx *gplay)
{
	int			r;
	int			j;
	int			i;
	static char	*imgs[7] = {"img/player.xpm", "bonus/img/player2.xpm", \
		"img/exit.xpm", "img/wall.xpm", "img/collec.xpm", "img/floor.xpm", \
		"bonus/img/ennemy.xpm"};

	j = -1;
	i = -1;
	while (++j < 7)
	{
		gplay->img[j] = mlx_xpm_file_to_image(gplay->mlx, imgs[j], &r, &r);
		if (!gplay->img[j])
		{
			while (++i < 10 && gplay->counterimg[i])
			{
				mlx_destroy_image(gplay->mlx, gplay->counterimg[i]);
				gplay->counterimg[i] = 0;
			}
			i = -1;
			ft_freemap(gplay->map);
			while (++i < j)
				mlx_destroy_image(gplay->mlx, gplay->img[i]);
			mlx_clear_window(gplay->mlx, gplay->mlx_win);
			mlx_destroy_window(gplay->mlx, gplay->mlx_win);
			mlx_destroy_display(gplay->mlx);
			free(gplay->mlx);
			ft_msgerror(3);
		}
	}
	while (gplay->img[++j])
		gplay->nbrimg++;
}
