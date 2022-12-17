/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:25:04 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/17 22:15:30 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_content_condition(char **map, t_map *game, int x, int y)
{
	while (map[y][x])
	{
		if (map[y][x] == 'C')
				game->coin++;
		if (map[y][x] == 'E')
		{
			game->exit[0] = y;
			game->exit[1] = x;
			game->map_e++;
		}
		if (map[y][x] == 'P')
		{
			game->start[0] = y;
			game->start[1] = x;
			game->map_p++;
		}
		if (!((map[y][x] == '1') || map[y][x] == '0' || map[y][x] == 'P' ||
			map[y][x] == 'E' || map[y][x] == 'C'))
		{
			ft_freemap(game->map);
			ft_msgerror(1);
		}
		x++;
	}
}

char	*ft_read_file(char *map)
{
	int		readret;
	char	*tmp;
	char	*buffer;
	int		fd;

	buffer = malloc(sizeof(char) * 2);
	if (!buffer)
		return (NULL);
	tmp = NULL;
	readret = 1;
	fd = open(map, O_RDONLY);
	while (readret)
	{
		readret = read(fd, buffer, 1);
		if (readret < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readret] = '\0';
		tmp = ft_join(tmp, buffer);
	}
	free(buffer);
	close(fd);
	return (tmp);
}

int	ft_msgerror(int error)
{
	if (error == 1)
	{
		ft_printf("\n%s\t    Error\n\tMap Invalide !%s\n\n", RED, END);
		exit (1);
	}
	return (0);
}

char	*ft_join(char *buffer, char *str)
{
	char	*mstr;
	int		i;
	int		j;

	if (!buffer)
	{
		buffer = (char *)malloc(sizeof(char) * 1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	if (!str || !buffer)
		return (NULL);
	mstr = malloc(sizeof(char) * (ft_strlen(buffer) + ft_strlen(str) + 1));
	if (!mstr)
		return (NULL);
	i = -1;
	while (buffer[++i])
		mstr[i] = buffer[i];
	j = 0;
	while (str[j])
		mstr[i++] = str[j++];
	mstr[i] = '\0';
	free(buffer);
	return (mstr);
}