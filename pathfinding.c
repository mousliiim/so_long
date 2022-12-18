/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 23:21:39 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/18 22:57:07 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_pathfind(t_map *game, int pox, int poy, int *count)
{
	int x;
	int y;

	x = 0;
	y = 1;
	while (y < (int)game->size_y - 1)
	{
		x = 1;
		while (game->map[y][x] && x < (int)game->size_x - 1)
		{
			if (game->map[poy][pox + 1] == '0' ||
				game->map[poy][pox + 1] == 'C' ||
				game->map[poy][pox + 1] == 'E')
			{
				game->map[poy][pox + 1] = 'X';
				if (game->map[poy][pox + 1] == 'X')
					(*count)++;
			}
			if (game->map[poy - 1][pox] == '0' ||
				game->map[poy - 1][pox] == 'C' ||
				game->map[poy - 1][pox] == 'E')
			{
				game->map[poy - 1][pox] = 'X';
				if (game->map[poy - 1][pox] == 'X')
					(*count)++;
			}
			if (game->map[poy + 1][pox] == '0' ||
				game->map[poy + 1][pox] == 'C' ||
				game->map[poy + 1][pox] == 'E')
			{
				game->map[poy + 1][pox] = 'X';
				if (game->map[poy + 1][pox] == 'X')
					(*count)++;
			}
			if (game->map[poy][pox - 1] == '0' ||
				game->map[poy][pox - 1] == 'C' ||
				game->map[poy][pox - 1] == 'E')
			{
				game->map[poy][pox - 1] = 'X';
				if (game->map[poy][pox - 1] == 'X')
					(*count)++;
			}
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

	sleep(1);
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
				ft_pathfind(game, pox, poy,  count);
			pox++;
		}
		poy++;
	}
	ft_display(game->map);
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

void	ft_pathvalid(t_map *game)
{
	int		count;

	count = 1;
	while (ft_check_if_exit(game) && count != 0)
	{
		count = 0;
		ft_beforepathfind(game, game->start[1], game->start[0], &count);
	}
	if (ft_check_if_exit(game) && count == 0)
	{
		ft_freemap(game->map);
		ft_msgerror(1);
	}
	else if (count == 1)
		ft_printf("%s\n\t    MAP VALIDE ..%s\n\n", GREEN, END);
}