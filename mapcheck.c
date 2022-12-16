/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 02:05:06 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/16 02:06:47 by mmourdal         ###   ########.fr       */
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
		{
			ft_msgerror(1);
			return (1);
		}
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
			ft_msgerror(1);
			return (1);
		}
		i++;
	}
	return (0);
}

char	**check_map(char *map, t_map *game)
{
	int		fd;
	int		readret;
	char	*tmp;
	int		i;
	size_t	len_first_x;

	tmp = NULL;
	fd = open(map, O_RDONLY);
	readret = 1;
	i = 1;
	while (readret)
	{
		readret = read(fd, map, 1);
		map[readret] = '\0';
		tmp = ft_join(tmp, map);
	}
	if (ft_checkspacemap(tmp))
		exit(1);
	game->map = ft_split(tmp, '\n');
	len_first_x = ft_strlen(game->map[0]);
	if (ft_checkmaprectangle(game, len_first_x))
		exit (1);
	free(tmp);
	game->checkmap = 1;
	return (game->map);
}
