/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:53:44 by rapelcha          #+#    #+#             */
/*   Updated: 2023/03/02 11:54:20 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_animation(t_game *t_game)
{
	t_game->idan = 1;
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
			(t_game->t_map.width / 2) - 75, 30);
	free(str);
}

void	back_anima(void *param)
{
	t_game	*t_game;

	t_game = param;
	t_game->ant++;
	if ((t_game->ant % 60) == 0)
		search_enemie(t_game);
	if ((t_game->ant % 15) == 0)
	{		
		t_game->idcol++;
		if (t_game->idcol == 8)
			t_game->idcol = 0;
	}
	if ((t_game->ant % 3) == 0)
	{
		t_game->idbck++;
		if (t_game->idbck == 4)
			t_game->idbck = 0;
		replace_map(t_game);
	}
}
