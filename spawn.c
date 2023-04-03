/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:16:20 by rapelcha          #+#    #+#             */
/*   Updated: 2023/04/03 15:01:53 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	spawn_collectible(t_game *t_game, int x, int y)
{
	spawn_background(t_game, x, y);
	mlx_image_to_window(t_game->mlx,
		t_game->nowimg.collectible[t_game->i_collectible],
		(x * SIZE), (y * SIZE));
}

void	spawn_player(t_game *t_game, int x, int y)
{
	spawn_background(t_game, x, y);
	if (t_game->i_animation_player == 0)
		mlx_image_to_window(t_game->mlx,
			t_game->nowimg.pl, (x * SIZE), (y * SIZE));
	else
	{
		mlx_image_to_window(t_game->mlx,
			t_game->nowimg.pl_1, (x * SIZE), (y * SIZE));
		t_game->i_animation_player = 0;
	}
}

void	spawn_wall(t_game *t_game, int x, int y)
{
	mlx_image_to_window(t_game->mlx,
		t_game->nowimg.wall, (x * SIZE), (y * SIZE));
}

void	spawn_background(t_game *t_game, int x, int y)
{
	mlx_image_to_window(t_game->mlx,
		t_game->nowimg.background[t_game->i_background],
		(x * SIZE), (y * SIZE));
}

void	spawn_exit(t_game *t_game, int x, int y)
{
	spawn_background(t_game, x, y);
	if (t_game->nb_collectible_2 > 0)
		mlx_image_to_window(t_game->mlx,
			t_game->nowimg.ex[0], (x * SIZE), (y * SIZE));
	else
		mlx_image_to_window(t_game->mlx,
			t_game->nowimg.ex[1], (x * SIZE), (y * SIZE));
}
