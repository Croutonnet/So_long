/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:16:10 by rapelcha          #+#    #+#             */
/*   Updated: 2023/04/03 12:59:30 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	spawn_enemie(t_game *t_game, int x, int y)
{
	mlx_image_to_window(t_game->mlx, t_game->nowimg.en, (x * SIZE), (y * SIZE));
}

void	wichmove(t_game *t_game, int d)
{
	if (d == 1)
		move_enemie(t_game, 0, 1);
	else if (d == 2)
		move_enemie(t_game, -1, 0);
	else if (d == 3)
		move_enemie(t_game, 0, -1);
	else if (d == 4)
		move_enemie(t_game, 1, 0);
}

void	search_enemie(t_game *t_game)
{
	int	d;
	int	y;
	int	x;

	y = 0;
	while (t_game->t_map.mappe[y])
	{
		x = 0;
		while (t_game->t_map.mappe[y][x])
		{
			t_game->xen = x;
			t_game->yen = y;
			if (t_game->t_map.mappe[y][x] == 'x')
			{
				d = ft_rand(1, 4);
				wichmove(t_game, d);
			}
			x++;
		}
		y++;
	}
}
