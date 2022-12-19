/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:39:43 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/19 05:25:32 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_arg(char *maparg, t_map *game)
{
	if (!(ft_strcmp(maparg + (ft_strlen(maparg) - 4), ".ber") == 0))
		return (game->checkarg = 0);
	else if (ft_strcmp(maparg, ".ber") == 0)
		return (game->checkarg = 0);
	else
		return (game->checkarg = 1);
}

void	ft_freemap(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	ft_startgame(t_startmlx *gplay, t_map *game)
{
	int	r;
	int	x;
	int	y;

	x = 0;
	y = 0;
	gplay->mlx = mlx_init();
	gplay->size_win = mlx_new_window(gplay->mlx, game->size_x * 64, game->size_y * 64, "so_long");
	gplay->img[0] = mlx_xpm_file_to_image(gplay->mlx, "img/player.xpm", &r, &r);
	gplay->img[1] = mlx_xpm_file_to_image(gplay->mlx, "img/exit.xpm", &r, &r);
	gplay->img[2] = mlx_xpm_file_to_image(gplay->mlx, "img/wall.xpm", &r, &r);
	gplay->img[3] = mlx_xpm_file_to_image(gplay->mlx, "img/collectible.xpm", &r, &r);
	gplay->img[4] = mlx_xpm_file_to_image(gplay->mlx, "img/floor.xpm", &r, &r);
	while (y < (int)game->size_y)
	{
		x = 0;
		while (gplay->map[y][x])
		{
			if (gplay->map[y][x] == 'P')
				mlx_put_image_to_window(gplay->mlx, gplay->size_win, gplay->img[0], x * 64, y * 64);
			if (gplay->map[y][x] == '1')
				mlx_put_image_to_window(gplay->mlx, gplay->size_win, gplay->img[2], x * 64, y * 64);
			if (gplay->map[y][x] == 'C')
				mlx_put_image_to_window(gplay->mlx, gplay->size_win, gplay->img[3], x * 64, y * 64);
			if (gplay->map[y][x] == 'E')
				mlx_put_image_to_window(gplay->mlx, gplay->size_win, gplay->img[1], x * 64, y * 64);
			if (gplay->map[y][x] == '0')
				mlx_put_image_to_window(gplay->mlx, gplay->size_win, gplay->img[4], x * 64, y * 64);
			x++;
		}
		y++;
	}
	mlx_loop(gplay->mlx);
}

int	main(int argc, char **argv, char **env)
{
	static t_map		game = {0};
	static t_startmlx	gplay = {0};

	if (!env || !*env)
		return (0);
	if (argc == 2)
	{
		ft_check_arg(argv[1], &game);
		if (game.checkarg == 0)
			return (ft_printf("%s\t    Error\n-> ./so_long [Your Map .ber]%s\n",
					RED, END));
		if (game.checkarg == 1)
		{
			check_map(argv[1], &game);
			ft_pathvalid(&game, argv[1]);
			gplay.map = game.map;
			ft_startgame(&gplay, &game);
			ft_display(gplay.map);
		}
		ft_freemap(game.map);
	}
	else if (argc != 2)
		ft_printf("%s\t    Error\n-> ./so_long [Your Map .ber]%s\n", RED, END);
}
