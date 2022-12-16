/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 02:05:06 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/16 04:14:00 by mmourdal         ###   ########.fr       */
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

char	*ft_read_file(char *map)
{
	int		readret;
	char	*tmp;
	char	*buffer;
	int		fd;

	buffer = malloc(sizeof(char) * 2);
	tmp = NULL;
	readret = 1;
	fd = open(map, O_RDONLY);
	while (readret)
	{
		readret = read(fd, buffer, 1);
		buffer[readret] = '\0';
		tmp = ft_join(tmp, buffer);
	}
	free(buffer);
	return (tmp);
}

char	**check_map(char *map, t_map *game)
{
	char	*tmp;
	size_t	len_first_x;

	tmp = ft_read_file(map);
	if (ft_checkspacemap(tmp))
	{
		free(tmp);
		exit(1);
	}
	game->map = ft_split(tmp, '\n');
	free(tmp);
	len_first_x = ft_strlen(game->map[0]);
	if (ft_checkmaprectangle(game, len_first_x))
		exit (1);
	game->checkmap = 1;
	return (game->map);
}
