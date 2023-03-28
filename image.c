/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:29:15 by rapelcha          #+#    #+#             */
/*   Updated: 2023/03/02 13:44:33 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_coll(t_game *t_game)
{
	t_game->nowimg.collectible[0] = load_image(t_game->mlx,
			"asset/xpm/cross0(75)_B.xpm42");
	t_game->nowimg.collectible[1] = load_image(t_game->mlx,
			"asset/xpm/cross1(75)_.xpm42");
	t_game->nowimg.collectible[2] = load_image(t_game->mlx,
			"asset/xpm/cross2(75)_.xpm42");
	t_game->nowimg.collectible[3] = load_image(t_game->mlx,
			"asset/xpm/cross3(75)_.xpm42");
	t_game->nowimg.collectible[4] = load_image(t_game->mlx,
			"asset/xpm/cross4(75)_.xpm42");
	t_game->nowimg.collectible[5] = load_image(t_game->mlx,
			"asset/xpm/cross5(75)_.xpm42");
	t_game->nowimg.collectible[6] = load_image(t_game->mlx,
			"asset/xpm/cross6(75)_.xpm42");
	t_game->nowimg.collectible[7] = load_image(t_game->mlx,
			"asset/xpm/cross7(75)_.xpm42");
}

void	initialize_image(t_game *t_game)
{
	t_game->nowimg.background[0] = load_image(t_game->mlx, BACK1);
	t_game->nowimg.background[1] = load_image(t_game->mlx, BACK2);
	t_game->nowimg.background[2] = load_image(t_game->mlx, BACK3);
	t_game->nowimg.background[3] = load_image(t_game->mlx, BACK4);
	t_game->nowimg.en = load_image(t_game->mlx, "asset/xpm/Jesus(75).xpm42");
	t_game->nowimg.wall = load_image(t_game->mlx, "asset/xpm/wall(75).xpm42");
	t_game->nowimg.pl = load_image(t_game->mlx, "asset/xpm/Patate(75).xpm42");
	t_game->nowimg.ex[0] = load_image(t_game->mlx, "asset/xpm/Door_1.xpm42");
	t_game->nowimg.ex[1] = load_image(t_game->mlx, "asset/xpm/Door_2.xpm42");
	t_game->nowimg.pl_1 = load_image(t_game->mlx,
			"asset/xpm/Patate_sad(75).xpm42");
	load_coll(t_game);
}

mlx_image_t	*load_image(mlx_t *mlx, char *path)
{
	mlx_image_t		*img;
	xpm_t			*xpm;
	mlx_texture_t	txt;

	xpm = mlx_load_xpm42(path);
	txt = xpm->texture;
	img = mlx_texture_to_image(mlx, &txt);
	mlx_delete_xpm42(xpm);
	return (img);
}

void	wich_move(t_game *t_game, t_map *t_map, int x, int y)
{
	if (t_map->mappe[y][x] == '1')
		put_wall(t_game, x, y);
	else if (t_map->mappe[y][x] == 'o' || t_map->mappe[y][x] == '0')
		put_background(t_game, x, y);
	else if (t_map->mappe[y][x] == 'x' || t_map->mappe[y][x] == 'X')
		put_enemie(t_game, x, y);
	else if (t_map->mappe[y][x] == 'p' || t_map->mappe[y][x] == 'P')
		put_player(t_game, x, y);
	else if (t_map->mappe[y][x] == 'e' || t_map->mappe[y][x] == 'E')
		put_exit(t_game, x, y);
	else if (t_map->mappe[y][x] == 'c' || t_map->mappe[y][x] == 'C')
		put_collectible(t_game, x, y);
}
