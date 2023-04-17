/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:27:00 by rapelcha          #+#    #+#             */
/*   Updated: 2023/04/17 13:56:41 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_error(t_game *t_game, char *error_type, char *location)
{
	if (ft_strncmp(error_type, BIG, ft_strlen(BIG) + 1) == 0)
		printf("ERROR\n%s\n", location);
	else if (ft_strncmp(error_type, ERRORMAP, ft_strlen(ERRORMAP) + 1) == 0)
	{
		if (t_game->t_map.mappe != NULL)
			free_map(t_game->t_map.mappe);
		printf("ERROR\n%s\n", location);
	}
	if (t_game->mlx)
		mlx_terminate (t_game->mlx);
	exit(0);
}

int	valid_extension(char *mappath)
{
	mappath = ft_strrchr(mappath, '.');
	if (!mappath)
		return (1);
	else
		return (ft_strncmp(mappath, ".ber", 5));
}

int	if_bad(char c)
{
	if (c == '1' || c == 'c' || c == 'o'
		|| c == 'e' || c == 'x')
		return (0);
	else
		return (1);
}
