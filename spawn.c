/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:16:20 by rapelcha          #+#    #+#             */
/*   Updated: 2023/02/23 16:48:15 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_collectible(t_game *t_game, int x, int y)
{
	put_background(t_game, x, y);
	mlx_image_to_window(t_game->mlx, t_game->nowimg.collectible[t_game->idcol],
		(x * 75), (y * 75));
}

void	put_player(t_game *t_game, int x, int y)
{
	put_background(t_game, x, y);
	if (t_game->idan == 0)
		mlx_image_to_window(t_game->mlx, t_game->nowimg.pl, (x * 75), (y * 75));
	else
	{
		mlx_image_to_window(t_game->mlx,
			t_game->nowimg.pl_1, (x * 75), (y * 75));
		t_game->idan = 0;
	}
}

void	put_wall(t_game *t_game, int x, int y)
{
	mlx_image_to_window(t_game->mlx, t_game->nowimg.wall, (x * 75), (y * 75));
}

void	put_background(t_game *t_game, int x, int y)
{
	mlx_image_to_window(t_game->mlx,
		t_game->nowimg.background[t_game->idbck], (x * 75), (y * 75));
}

void	put_exit(t_game *t_game, int x, int y)
{
	put_background(t_game, x, y);
	if (t_game->coll > 0)
		mlx_image_to_window(t_game->mlx,
			t_game->nowimg.ex[0], (x * 75), (y * 75));
	else
		mlx_image_to_window(t_game->mlx,
			t_game->nowimg.ex[1], (x * 75), (y * 75));
}
