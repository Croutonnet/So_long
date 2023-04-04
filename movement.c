/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:32:10 by rapelcha          #+#    #+#             */
/*   Updated: 2023/04/04 10:19:56 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_game *t_game, int newx, int newy)
{
	int	x;
	int	y;

	x = t_game->xpl;
	y = t_game->ypl;
	t_game->t_map.mappe[y][x] = 'o';
	t_game->t_map.mappe[y - newy][x - newx] = 'P';
	t_game->ypl = y - newy;
	t_game->xpl = x - newx;
	replace_map(t_game);
	t_game->nb_mov++;
}

void	move_player(t_game *t_game, int newx, int newy)
{
	int	x;
	int	y;

	x = t_game->xpl;
	y = t_game->ypl;
	if (t_game->t_map.mappe[y - newy][x - newx] == '1')
	{
		player_animation(t_game);
		return ;
	}
	else if (t_game->t_map.mappe[y - newy][x - newx] == 'e')
	{
		if (t_game->nb_collectible_2 == 0)
			initialize_error(t_game, FINISHGAME, "Bravo, you've won¡");
		return ;
	}
	else if (t_game->t_map.mappe[y - newy][x - newx] == 'c')
		t_game->nb_collectible_2--;
	else if (t_game->t_map.mappe[y - newy][x - newx] == 'x')
		initialize_error(t_game, FINISHGAME, "Don't hug Jesus¡");
	move(t_game, newx, newy);
}

void	move_enemie(t_game *t_game, int newx, int newy)
{
	int	x;
	int	y;

	x = t_game->xen;
	y = t_game->yen;
	if (t_game->t_map.mappe[y - newy][x - newx] == '1'
		|| t_game->t_map.mappe[y - newy][x - newx] == 'e'
		|| t_game->t_map.mappe[y - newy][x - newx] == 'c'
		|| t_game->t_map.mappe[y - newy][x - newx] == 'x')
		return ;
	else if (t_game->t_map.mappe[y - newy][x - newx] == 'P')
		initialize_error(t_game, FINISHGAME, "Jesus hugged you¡");
	t_game->t_map.mappe[y][x] = 'o';
	t_game->t_map.mappe[y - newy][x - newx] = 'x';
	t_game->yen = y - newy;
	t_game->xen = x - newx;
}
