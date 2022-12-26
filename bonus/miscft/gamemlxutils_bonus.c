/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamemlxutils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 01:08:16 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/26 07:46:32 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
	while (i < 7 && gplay->img[i])
	{
		mlx_destroy_image(gplay->mlx, gplay->img[i]);
		gplay->img[i] = 0;
		i++;
	}
	i = 0;
	while (i < 10 && gplay->counterimg[i])
	{
		mlx_destroy_image(gplay->mlx, gplay->counterimg[i]);
		gplay->counterimg[i] = 0;
		i++;
	}
	mlx_clear_window(gplay->mlx, gplay->mlx_win);
	mlx_destroy_window(gplay->mlx, gplay->mlx_win);
	mlx_destroy_display(gplay->mlx);
	ft_empty_struct(gplay, game);
}

void	ft_display_bonus_counter(t_startmlx *gplay, int nbr, int i)
{
	if (nbr != 0)
	{
		mlx_put_image_to_window(gplay->mlx, gplay->mlx_win,
			gplay->counterimg[nbr % 10],
			(i * 64), (gplay->size_y * 64));
		ft_display_bonus_counter(gplay, (nbr / 10), i - 1);
	}
}

void	ft_display_player_in_exit(t_startmlx *gplay)
{
	if (gplay->coin == 0
		&& gplay->map[gplay->start[0]][gplay->start[1]] ==
			gplay->map[gplay->exit[0]][gplay->exit[1]])
	{
		ft_printf("%s\n\t      -> Felicitation ! <-%s\n", GREEN, END);
		ft_printf("%s       -> Vous avez utiliser la sortie ! <-%s\n",
			GREEN, END);
		ft_printf("%s   -> Vous avez recuperer : %d Collectible(s) <-%s\n\n",
			GREEN, gplay->needcoin, END);
		mlx_loop_end(gplay->mlx);
	}
}
