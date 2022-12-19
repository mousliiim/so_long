/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 23:21:39 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/19 01:51:44 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_pathfind(t_map *game, int pox, int poy, int *count)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	while (y < (int)game->size_y - 1)
	{
		x = 1;
		while (game->map[y][x] && x < (int)game->size_x - 1)
		{
			ft_check_path_right(game, pox, poy, count);
			ft_check_path_top(game, pox, poy, count);
			ft_check_path_bottom(game, pox, poy, count);
			ft_check_path_left(game, pox, poy, count);
			x++;
		}
		y++;
	}
	return (1);
}

void	ft_beforepathfind(t_map *game, int pox, int poy, int *count)
{
	int	pos_x;
	int	pos_y;

	// sleep(1);
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
	// ft_display(game->map);
}

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

void	ft_finalmap(t_map *game, char *mapname)
{
	ft_freemap(game->map);
	game->map = NULL;
	game->size_x = 0;
	game->size_y = 0;
	game->checkarg = 0;
	game->checkmap = 0;
	game->coin = 0;
	game->map_e = 0;
	game->map_p = 0;
	game->start[0] = 0;
	game->start[1] = 0;
	game->exit[0] = 0;
	game->exit[1] = 0;
	check_map(mapname, game);
}

void	ft_pathvalid(t_map *game, char *mapname)
{
	int	count;

	count = 1;
	while (ft_check_if_exit(game) && count != 0)
	{
		count = 0;
		ft_beforepathfind(game, game->start[1], game->start[0], &count);
	}
	if (ft_check_if_exit(game) && count == 0)
	{
		ft_freemap(game->map);
		ft_msgerror(2);
	}
	ft_finalmap(game, mapname);
}