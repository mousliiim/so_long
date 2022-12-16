/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:39:43 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/16 04:13:21 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_arg(char *maparg, t_map *game)
{
	if (!(ft_strcmp(maparg + (ft_strlen(maparg)- 4), ".ber") == 0))
		return (game->checkarg = 0);
	else if (ft_strcmp(maparg, ".ber") == 0)
		return (game->checkarg = 0);
	else
		return (game->checkarg = 1);
}

void	ft_display(char **tab)
{
	int	i;

	i = -1;
	printf("\n\n");
	while (tab[++i])
		ft_printf("%s\n", tab[i]);
	printf("\n\n");
}

void	ft_freemap(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

int	main(int argc, char **argv)
{
	t_map	game;

	if (argc == 2)
	{
		ft_check_arg(argv[1], &game);
		if (game.checkarg == 0)
			return (ft_printf("./so_long [Your Map .ber]\n"));
		// ft_printf("CHECK ARG IS %d\n", game.checkarg);
		if (game.checkarg == 1)
			check_map(argv[1], &game);
		if (game.checkmap == 1)
			ft_printf("\n\nCHECKMAP STRUCT VALUE : %d\n", game.checkmap);
		//ft_display(game.map);
	}
	ft_freemap(game.map);
}