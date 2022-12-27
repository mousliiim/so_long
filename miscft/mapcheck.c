/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 02:05:06 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/26 22:28:58 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_checkspacemap(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[0] == '\n' || (tmp[i] == '\n' && tmp[i + 1] == '\n')
			|| (i == (int)ft_strlen(tmp) - 1 && tmp[i] == '\n'))
		{
			free(tmp);
			ft_msgerror(1);
		}
		i++;
	}
}

static void	ft_checkmaprectangle(t_map *game, size_t len_first_line)
{
	int	i;

	i = -1;
	while (game->map[++i])
	{
		if (ft_strlen(game->map[i]) != len_first_line)
		{
			ft_freemap(game->map);
			ft_msgerror(1);
		}
	}
	game->size_y = i;
}

static void	ft_check_border_map(char **map, t_map *game)
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
}

char	**check_map(char *map, t_map *game)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_read_file(map);
	if ((int)ft_strlen(tmp) == 0)
	{
		free(tmp);
		ft_msgerror(1);
	}
	if (!tmp)
		ft_msgerror(1);
	ft_checkspacemap(tmp);
	game->map = ft_split(tmp, '\n');
	free(tmp);
	game->size_x = ft_strlen(game->map[0]);
	ft_checkmaprectangle(game, game->size_x);
	ft_check_border_map(game->map, game);
	ft_check_content_map(game->map, game);
	return (game->map);
}

void	ft_pathvalid(t_map *game, char *mapname, t_startmlx *gplay)
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
	ft_finalmap(game, mapname, gplay);
}
