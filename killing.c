/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   killing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:00:48 by rapelcha          #+#    #+#             */
/*   Updated: 2023/02/23 16:45:57 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_map(t_game *t_game, t_img *t_img)
{
	mlx_delete_image(t_game->mlx, t_img->background[0]);
	mlx_delete_image(t_game->mlx, t_img->background[1]);
	mlx_delete_image(t_game->mlx, t_img->background[2]);
	mlx_delete_image(t_game->mlx, t_img->background[3]);
	mlx_delete_image(t_game->mlx, t_img->collectible[0]);
	mlx_delete_image(t_game->mlx, t_img->collectible[1]);
	mlx_delete_image(t_game->mlx, t_img->collectible[2]);
	mlx_delete_image(t_game->mlx, t_img->collectible[3]);
	mlx_delete_image(t_game->mlx, t_img->collectible[4]);
	mlx_delete_image(t_game->mlx, t_img->collectible[5]);
	mlx_delete_image(t_game->mlx, t_img->collectible[6]);
	mlx_delete_image(t_game->mlx, t_img->collectible[7]);
	mlx_delete_image(t_game->mlx, t_img->wall);
	mlx_delete_image(t_game->mlx, t_img->ex[0]);
	mlx_delete_image(t_game->mlx, t_img->ex[1]);
	mlx_delete_image(t_game->mlx, t_img->pl);
	mlx_delete_image(t_game->mlx, t_img->pl_1);
	mlx_delete_image(t_game->mlx, t_img->en);
	if (t_img->move)
		mlx_delete_image(t_game->mlx, t_img->move);
}

void	free_map(char **map)
{
	int	y;

	y = 0;
	if (!map)
		return ;
	while (map[y])
		free(map[y++]);
	free(map);
}
