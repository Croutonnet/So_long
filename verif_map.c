/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:45:11 by rapelcha          #+#    #+#             */
/*   Updated: 2023/04/03 15:02:44 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	explore_map(int x, int y, t_game *t_game, char **map)
{
	if ((y > 0 && y < t_game->t_map.heightnb)
		&& (x > 0 && x < t_game->t_map.widthnb) && (map[y]))
	{
		if (if_bad_character_in_map(map[y][x]) == 0)
			return ;
		else if (map[y][x] == 'C')
		{
			map[y][x] = 'c';
			t_game->nb_collectible++;
		}
		else if (map[y][x] == 'E')
		{
			map[y][x] = 'e';
			t_game->nb_e++;
			return ;
		}
		else if (map[y][x] == '0')
			map[y][x] = 'o';
		else if (map[y][x] == 'X')
			map[y][x] = 'x';
		explore_map(x + 1, y, t_game, t_game->t_map.mappe);
		explore_map(x - 1, y, t_game, t_game->t_map.mappe);
		explore_map(x, y + 1, t_game, t_game->t_map.mappe);
		explore_map(x, y - 1, t_game, t_game->t_map.mappe);
	}
}

int	verif_map(t_game *t_game)
{
	t_game->nb_e = 0;
	explore_map(t_game->xpl, t_game->ypl, t_game, t_game->t_map.mappe);
	if (t_game->nb_collectible == t_game->nb_collectible_2 && t_game->nb_e == 1)
		return (1);
	else
		initialize_error(t_game, ERRORMAP, "Game impossible to solve¡");
	return (0);
}

void	valid_map(char *map, t_game *t_game)
{
	int	i;
	int	p;
	int	e;

	i = 0;
	p = 0;
	e = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			t_game->nb_collectible_2++;
		else if (map[i] == 'E')
			e++;
		else if (map[i] == 'P')
			p++;
		else if (!(map[i] == '1' || map[i] == '0' || map[i] == 'P'
				|| map[i] == 'E' || map[i] == 'C'
				|| map[i] == '\n' || map[i] == 'X') || p > 1 || e > 1)
		{	
			free(map);
			initialize_error(t_game, ERRORMAP, "Invalid character in .ber¡");
		}
		i++;
	}
}

void	valid_frame(t_game *t_game, t_map *t_map)
{
	int	y;
	int	x;
	int	fr;

	y = 0;
	fr = (((t_map->widthnb + t_map->heightnb) * 2) - 4);
	while (t_map->mappe[y])
	{
		x = 0;
		while (t_map->mappe[y][x])
		{
			if (t_map->mappe[y][x] == '1')
				if ((y == 0 || y == (t_map->heightnb - 1))
					|| (x == 0 || x == (t_map->widthnb - 1)))
					fr--;
			x++;
		}
		y++;
	}
	if (fr > 0)
	{
		initialize_error(t_game, ERRORMAP, "Map dont have a frame¡");
	}
}
