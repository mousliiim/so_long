/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:25:04 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/23 21:44:13 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
		tmp = ft_strjoin(tmp, buffer);
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
	if (error == 2)
	{
		ft_printf("\n%s\t\t Error\n", RED);
		ft_printf("  Sortie ou Collectible non atteignable !%s\n\n", END);
		exit (1);
	}
	if (error == 3)
	{
		ft_printf("\n%s\t\t Error\n", RED);
		ft_printf("  Une des images du jeu est erronée !%s\n\n", END);
		exit (1);
	}
	return (0);
}

void	ft_put_image(t_startmlx *gplay, int i_img, int x, int y)
{
	mlx_put_image_to_window(gplay->mlx, gplay->mlx_win, gplay->img[i_img],
		x * 64, y * 64);
}
