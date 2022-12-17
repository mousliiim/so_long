/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 02:05:06 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/17 22:15:13 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkspacemap(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[0] == '\n' || (tmp[i] == '\n' && tmp[i + 1] == '\n')
			|| (i == (int)ft_strlen(tmp) - 1 && tmp[i] == '\n'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_checkmaprectangle(t_map *game, size_t len_first_line)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) < len_first_line
			|| ft_strlen(game->map[i]) > len_first_line)
		{
			ft_freemap(game->map);
			ft_msgerror(1);
		}
		i++;
	}
	game->size_y = i;
	return (0);
}

char	**check_map(char *map, t_map *game)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_read_file(map);
	if (!tmp)
		ft_msgerror(1);
	if (ft_checkspacemap(tmp))
	{
		free(tmp);
		ft_msgerror(1);
	}
	game->map = ft_split(tmp, '\n');
	free(tmp);
	game->size_x = ft_strlen(game->map[0]);
	if (ft_checkmaprectangle(game, game->size_x))
	{
		ft_freemap(game->map);
		exit (1);
	}
	game->checkmap = 1;
	return (game->map);
}

int	ft_check_border_map(char **map, t_map *game)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!(map[0][x] == '1') ||
				!(map[y][game->size_x - 1] == '1') ||
				!(map[game->size_y - 1][x] == '1') ||
				!(map[y][0] == '1'))
			{
				ft_freemap(game->map);
				ft_msgerror(1);
			}
			x++;
		}
		y++;
	}
	return (1);
}

void	ft_check_content_map(char **map, t_map *game)
{
	int	y;
	int	x;

	x = 0;
	y = 1;
	while (map[y])
	{
		x = 0;
		ft_content_condition(map, game, x, y);
		y++;
	}
	if (game->map_e != 1 || game->map_p != 1 || game->coin <= 0)
	{
		ft_freemap(game->map);
		ft_msgerror(1);
	}
}