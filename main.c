/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:39:43 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/16 02:13:20 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_arg(char *maparg, t_map *game)
{
	if (!(ft_strcmp(maparg + (ft_strlen(maparg)- 4), ".ber") == 0))
		return (game->checkarg = 0);
	else
		return (game->checkarg = 1);
}

int	ft_msgerror(int error)
{
	if (error == 1)
		ft_printf("\n%sError\n-> Map Invalide !%s\n\n", RED, END);
	return (0);
}

// void	ft_display(char **tab)
// {
// 	int	i;

// 	i = -1;
// 	printf("\n\n");
// 	while (tab[++i])
// 		ft_printf("%s\n", tab[i]);
// }

int	main(int argc, char **argv)
{
	t_map	game;

	if (argc < 2 || ft_check_arg(argv[1], &game))
		if (game.checkarg == 0)
			return (ft_printf("./so_long [Your Map .ber]\n"));
	// ft_printf("CHECK ARG IS %d\n", game.checkarg);
	if (game.checkarg == 1)
		check_map(argv[1], &game);
	if (game.checkmap == 1)
		ft_printf("CHECKMAP STRUCT VALUE : %d\n", game.checkmap);
	// ft_display(game.map);
}