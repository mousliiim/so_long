/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamemlxutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 01:08:16 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/27 00:56:40 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_x(t_startmlx *gplay)
{
	if (gplay->coin != 0)
		ft_printf("\n%s\tVous n'avez pas recuperer : %d Collectible(s)%s\n",
			RED, gplay->coin, END);
	else
		ft_printf("\n\t%sVous avez recuperer : %d Collectible(s)%s\n",
			GREEN, gplay->needcoin, END);
	if (gplay->coin == 0
		&& gplay->map[gplay->start[0]][gplay->start[1]] ==
		gplay->map[gplay->exit[0]][gplay->exit[1]])
		ft_printf("%s\tVous avez utiliser la sortie !%s\n\n", GREEN, END);
	else
		ft_printf("%s\t  Vous n'avez pas utiliser la sortie%s\n\n", RED, END);
	mlx_loop_end(gplay->mlx);
	return (0);
}

void	ft_exit(t_startmlx *gplay, t_map *game)
{
	int	i;

	i = 0;
	while (i < gplay->nbrimg && gplay->img[i])
	{
		mlx_destroy_image(gplay->mlx, gplay->img[i]);
		gplay->img[i] = 0;
		i++;
	}
	mlx_clear_window(gplay->mlx, gplay->mlx_win);
	mlx_destroy_window(gplay->mlx, gplay->mlx_win);
	mlx_destroy_display(gplay->mlx);
	ft_empty_struct(gplay, game);
}
