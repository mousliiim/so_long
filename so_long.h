/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:49:32 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/16 02:11:10 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "includes/libft/libft.h"
# include "includes/ft_printf/ft_printf.h"
# include "mlx/mlx/mlx.h"

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define END "\033[0m"

typedef struct s_map
{
	char	**map;
	int		checkarg;
	int		checkmap;
	int		start;
	int		exit[2];
}	t_map;

int		ft_msgerror(int error);
char	*ft_join(char *buffer, char *str);
int		ft_checkspacemap(char *tmp);
int		ft_checkmaprectangle(t_map *game, size_t len_first_line);
char	**check_map(char *map, t_map *game);

#endif