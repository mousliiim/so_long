/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:39:43 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/26 22:25:34 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_check_arg(char *maparg)
{
	if (!(ft_strcmp(maparg + (ft_strlen(maparg) - 4), ".ber") == 0)
		|| ft_strcmp(maparg, ".ber") == 0)
		return (0);
	else
		return (1);
}

void	ft_freemap(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	ft_empty_t_map(t_map *game)
{
	game->map = NULL;
	game->size_x = 0;
	game->size_y = 0;
	game->coin = 0;
	game->map_e = 0;
	game->map_p = 0;
	game->start[0] = 0;
	game->start[1] = 0;
	game->exit[0] = 0;
	game->exit[1] = 0;
}

void	ft_empty_struct(t_startmlx *gplay, t_map *game)
{
	free(gplay->mlx);
	ft_freemap(gplay->map);
	gplay->map = NULL;
	gplay->mlx = 0;
	gplay->mlx_win = 0;
	gplay->size_x = 0;
	gplay->size_y = 0;
	gplay->step = 0;
	gplay->coin = 0;
	gplay->start[0] = 0;
	gplay->start[1] = 0;
	gplay->exit[0] = 0;
	gplay->exit[1] = 0;
	ft_empty_t_map(game);
}

int	main(int argc, char **argv, char **env)
{
	static t_map		game = {0};
	static t_startmlx	gplay = {0};

	if (!env || !*env)
		return (0);
	if (argc == 2)
	{
		if (!(ft_check_arg(argv[1])))
			return (ft_printf("%s\t    Error\n-> ./so_long [Your Map .ber]%s\n",
					RED, END));
		check_map(argv[1], &game);
		ft_pathvalid(&game, argv[1], &gplay);
		ft_fillmap(&gplay);
		mlx_hook(gplay.mlx_win, KeyPress, KeyPressMask, &deal_key, &gplay);
		mlx_hook(gplay.mlx_win, 17, (1L << 17), &close_x, &gplay);
		mlx_loop(gplay.mlx);
		ft_exit(&gplay, &game);
	}
	else if (argc != 2)
		ft_printf("%s\t    Error\n-> ./so_long [Your Map .ber]%s\n", RED, END);
}
