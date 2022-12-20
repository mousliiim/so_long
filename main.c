/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:39:43 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/20 05:46:24 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_arg(char *maparg)
{
	if (!(ft_strcmp(maparg + (ft_strlen(maparg) - 4), ".ber") == 0))
		return (0);
	else if (ft_strcmp(maparg, ".ber") == 0)
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
		mlx_loop(gplay.mlx);
		ft_freemap(game.map);
	}
	else if (argc != 2)
		ft_printf("%s\t    Error\n-> ./so_long [Your Map .ber]%s\n", RED, END);
}
