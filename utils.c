/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:25:04 by mmourdal          #+#    #+#             */
/*   Updated: 2022/12/16 02:13:30 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_msgerror(int error)
{
	if (error == 1)
		ft_printf("\n%sError\n-> Map Invalide !%s\n\n", RED, END);
	return (0);
}

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