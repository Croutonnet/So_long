/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:20:30 by rapelcha          #+#    #+#             */
/*   Updated: 2023/04/17 13:28:15 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	finish_game(t_game *t_game, char *message)
{
	delete_map(t_game, &t_game->oldimg);
	delete_map(t_game, &t_game->nowimg);
	printf("%s\n", message);
	if (t_game->mlx)
		mlx_terminate (t_game->mlx);
	exit(0);
}
