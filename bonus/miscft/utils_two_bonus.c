/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:51:02 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/26 22:00:53 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_xpm_error(t_startmlx *gplay, int i, int j)
{
	ft_freemap(gplay->map);
	while (++i < j)
		mlx_destroy_image(gplay->mlx, gplay->img[i]);
	mlx_clear_window(gplay->mlx, gplay->mlx_win);
	mlx_destroy_window(gplay->mlx, gplay->mlx_win);
	mlx_destroy_display(gplay->mlx);
	free(gplay->mlx);
	ft_msgerror(3);
}
