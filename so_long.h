/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:49:32 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/20 04:15:53 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "includes/libft/libft.h"
# include "includes/ft_printf/ft_printf.h"
# include "mlx/mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define END "\033[0m"
# define ESCAPE 65307
# define W 119
# define A 97
# define D 100
# define S 115

typedef struct s_map
{
	char	**map;
	size_t	size_x;
	size_t	size_y;
	int		checkmap;
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
	void	*img[256];
	size_t	size_x;
	size_t	size_y;
	int		step;
	int		coin;
	int		start[2];
	int		exit[2];
}	t_startmlx;

int		ft_msgerror(int error);
int		ft_check_arg(char *maparg);
char	*ft_join(char *buffer, char *str);
char	*ft_read_file(char *map);
int		ft_checkspacemap(char *tmp);
int		ft_checkmaprectangle(t_map *game, size_t len_first_line);
void	ft_freemap(char **map);
void	ft_check_border_map(char **map, t_map *game);
char	**check_map(char *map, t_map *game);
void	ft_display(char **tab);
void	ft_check_content_map(char **map, t_map *game);
void	ft_content_condition(char **map, t_map *game, int x, int y);
int		ft_pathfind(t_map *game, int pox, int poy, int *count);
void	ft_pathvalid(t_map *game, char *mapname, t_startmlx *gplay);
int		ft_check_if_exit(t_map *game);
void	ft_check_path_right(t_map *game, int pox, int poy, int *count);
void	ft_check_path_top(t_map *game, int pox, int poy, int *count);
void	ft_check_path_bottom(t_map *game, int pox, int poy, int *count);
void	ft_check_path_left(t_map *game, int pox, int poy, int *count);
void	ft_finalmap(t_map *game, char *mapname, t_startmlx *gplay);
void	ft_fillmap(t_startmlx *gplay);
void	ft_tab_fill_xpm(t_startmlx *gplay);
int		deal_key(int keysym, t_startmlx *gplay);

#endif