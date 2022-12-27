/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:49:32 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/27 00:31:41 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include "../includes/libft/libft.h"
# include "../includes/ft_printf/ft_printf.h"
# include "../mlx/mlx/mlx.h"
# include <stdlib.h>
# include <time.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define END "\033[0m"
# define ESC 65307
# define W 119
# define A 97
# define D 100
# define S 115

typedef struct s_map
{
	char	**map;
	size_t	size_x;
	size_t	size_y;
	int		coin;
	int		map_e;
	int		map_p;
	int		start[2];
	int		exit[2];
}	t_map;

typedef struct s_startmlx
{
	char	**map;
	void	*mlx;
	void	*mlx_win;
	void	*img[7];
	void	*imgct[10];
	size_t	size_x;
	size_t	size_y;
	int		step;
	int		coin;
	int		needcoin;
	int		start[2];
	int		exit[2];
	int		rand;
}	t_startmlx;

int		ft_msgerror(int error);
char	*ft_read_file(char *map);
void	ft_freemap(char **map);
char	**check_map(char *map, t_map *game);
void	ft_check_content_map(char **map, t_map *game);
void	ft_content_condition(char **map, t_map *game, int x, int y);
int		ft_pathfind(t_map *game, int pox, int poy, int *count);
void	ft_pathvalid(t_map *game, char *mapname, t_startmlx *gplay);
void	ft_beforepathfind(t_map *game, int pox, int poy, int *count);
int		ft_check_if_exit(t_map *game);
void	ft_finalmap(t_map *game, char *mapname, t_startmlx *gplay);
void	ft_fillmap(t_startmlx *gplay);
int		deal_key(int keysym, t_startmlx *gplay);
void	ft_empty_struct(t_startmlx *gplay, t_map *game);
void	ft_empty_t_map(t_map *game);
void	ft_exit(t_startmlx *gplay, t_map *game);
void	ft_put_image(t_startmlx *gplay, int i_img, int x, int y);
int		close_x(t_startmlx *gplay);
void	ft_display_bonus_counter(t_startmlx *gplay, int nbr, int i);
void	ft_display_player_in_exit(t_startmlx *gplay);
void	ft_xpm_error(t_startmlx *gplay, int i, int j);

#endif