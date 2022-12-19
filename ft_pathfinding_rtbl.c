/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathfinding_rtbl.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 23:38:46 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/19 00:00:46 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * Ces fonctions font partie de ft_pathfind, elles vérifie les chemins
 * disponibles autour d'une position donnée. Les fonctions ci-dessous vérifient
 * les chemins à droite, en haut, en bas et à gauche à partir de la position 
 * donner et, si un chemin est trouvé, met à jour la map temporairerement et 
 * incrémente la variable count qui serviras pour savoir si il est encore possib
 * -le d'ecrire des X pour voir si un chemin est possible dans la map.
*/

void	ft_check_path_right(t_map *game, int pox, int poy, int *count)
{
	if (game->map[poy][pox + 1] == '0' ||
		game->map[poy][pox + 1] == 'C' ||
		game->map[poy][pox + 1] == 'E')
	{
		game->map[poy][pox + 1] = 'X';
		if (game->map[poy][pox + 1] == 'X')
			(*count)++;
	}
}

void	ft_check_path_top(t_map *game, int pox, int poy, int *count)
{
	if (game->map[poy - 1][pox] == '0' ||
		game->map[poy - 1][pox] == 'C' ||
		game->map[poy - 1][pox] == 'E')
	{
		game->map[poy - 1][pox] = 'X';
		if (game->map[poy - 1][pox] == 'X')
			(*count)++;
	}
}

void	ft_check_path_bottom(t_map *game, int pox, int poy, int *count)
{
	if (game->map[poy + 1][pox] == '0' ||
		game->map[poy + 1][pox] == 'C' ||
		game->map[poy + 1][pox] == 'E')
	{
		game->map[poy + 1][pox] = 'X';
		if (game->map[poy + 1][pox] == 'X')
			(*count)++;
	}
}

void	ft_check_path_left(t_map *game, int pox, int poy, int *count)
{
	if (game->map[poy][pox - 1] == '0' ||
		game->map[poy][pox - 1] == 'C' ||
		game->map[poy][pox - 1] == 'E')
	{
		game->map[poy][pox - 1] = 'X';
		if (game->map[poy][pox - 1] == 'X')
			(*count)++;
	}
}
