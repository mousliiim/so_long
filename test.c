/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 01:45:40 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/15 21:54:00 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_join(char *buffer, char *str)
{
	char	*mstr;
	int		i;
	int		j;

	if (!buffer)
	{
		buffer = (char *)malloc(sizeof(char) * 1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	if (!str || !buffer)
		return (NULL);
	mstr = malloc(sizeof(char) * (ft_strlen(buffer) + ft_strlen(str) + 1));
	if (!mstr)
		return (NULL);
	i = -1;
	while (buffer[++i])
		mstr[i] = buffer[i];
	j = 0;
	while (str[j])
		mstr[i++] = str[j++];
	mstr[i] = '\0';
	free(buffer);
	return (mstr);
}

int	ft_check_arg(char *maparg)
{
	if (!(ft_strcmp(maparg + (ft_strlen(maparg)- 4), ".ber") == 0))
		return (1);
	else
		exit(1);
}

void	ft_display(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		ft_printf("|%s|\n", tab[i]);
}
// int main(int argc, char **argv)
// {
// 	(void)argc;
// 	if (argc < 2 || ft_check_arg(argv[1]))
// 		return (ft_printf("./so_long [Your Map .ber]\n"));
// }

int main(int argc, char *argv[])
{
	char	*map;
	char	*tmp = NULL;
	int readret = 1;
	int	len_first_x;
	int fd;
	char **tab;
	int i = 0;
	t_map	*mapping;
	mapping = malloc(sizeof(t_map));

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	map = malloc(2);
	while (readret)
	{
		readret = read(fd, map, 1);
		map[readret] = '\0';
		tmp = ft_join(tmp, map);
	}
	while (tmp[i])
	{
		if (tmp[0] == '\n' || (tmp[i] == '\n' && tmp[i + 1] == '\n')
			|| (i == (int)ft_strlen(tmp) - 1 && tmp[i] == '\n'))
		{
			ft_printf("MAP INVALIDE\n");
			exit(1);
		}
		else if (tmp[i] == 'C')
			mapping->collectible++;
		else if (tmp[i] == 'E')
			mapping->sortie += 1;
		else if (tmp[i] == 'P')
			mapping->depart += 1;
		i++;
	}
	i = 0;
	tab = ft_split(tmp, '\n');
	len_first_x = ft_strlen(tab[0]);
	ft_printf("X : %d\n", len_first_x);
	while (tab[++i])
	{
		if ((int)ft_strlen(tab[i]) != len_first_x)
		{
			ft_printf("%d | CE N'EST PAS UN RECTANGLE\n", i);
			exit(1);
		}
		else if ((int)ft_strlen(tab[i]) == len_first_x)
			ft_printf("%d | C'EST UN RECTANGLE\n", i);
	}
	ft_display(tab);
	printf("\n\nCollectible Find : %d\n", mapping->collectible);
	printf("\n\nSortie Find : %d\n", mapping->sortie);
	printf("\n\nDepart Find : %d\n", mapping->depart);
	return (1);
}