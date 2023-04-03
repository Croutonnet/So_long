/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:53:44 by rapelcha          #+#    #+#             */
/*   Updated: 2023/04/03 14:28:16 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_animation(t_game *t_game)
{
	t_game->i_animation_player = 1;
	replace_map(t_game);
}

void	move_string(t_game *t_game)
{
	char	*str;
	char	*nb;

	nb = ft_itoa(t_game->nb_mov);
	str = ft_strjoin("Nombre de mouvement: ", nb);
	nb = ft_xfree(nb);
	t_game->nowimg.move = mlx_put_string(t_game->mlx, str,
			(t_game->t_map.width / 2) - SIZE, 30);
	free(str);
}

void	back_animation(void *param)
{
	t_game	*t_game;

	t_game = param;
	t_game->timer++;
	if ((t_game->timer % 60) == 0)
		search_enemie(t_game);
	if ((t_game->timer % 20) == 0)
	{		
		t_game->i_collectible++;
		if (t_game->i_collectible == 8)
			t_game->i_collectible = 0;
	}
	if ((t_game->timer % 7) == 0)
	{
		t_game->i_background++;
		if (t_game->i_background == 4)
			t_game->i_background = 0;
		replace_map(t_game);
	}
}
