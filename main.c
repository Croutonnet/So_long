/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:56:05 by rapelcha          #+#    #+#             */
/*   Updated: 2023/04/17 14:15:32 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movementhandler(mlx_key_data_t keydata, void *param)
{
	t_game	*t_game;

	t_game = param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			move_player(t_game, 0, 1);
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			move_player(t_game, 0, -1);
		else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			move_player(t_game, 1, 0);
		else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			move_player(t_game, -1, 0);
		else if (keydata.key == MLX_KEY_ESCAPE)
			initialize_error(t_game, FINISHGAME, "Le jeu est désormais fermé¡");
	}
}

void	initialization(t_game *t_game, char *av)
{
	t_game->t_map.fd = open(av, O_RDONLY);
	if (t_game->t_map.fd < 0)
		initialize_error (t_game, ERRORMAP, "Mauvais fichier¡");
	map(t_game);
	t_game->t_map.width = t_game->t_map.widthnb * 75;
	t_game->t_map.height = t_game->t_map.heightnb * 75;
	t_game->mlx = mlx_init(t_game->t_map.width, t_game->t_map.height,
			"Battle of the Jesus¡", false);
	player_pos(t_game);
	t_game->nbcr = 0;
	initialize_image(t_game);
	if ((verif_map(t_game)) == 1)
		spawn_map(t_game, &t_game->t_map);
	if (BONUS == 0)
		printf("%d\n", t_game->nb_mov);
}

void	player_pos(t_game *t_game)
{
	int	x;
	int	y;

	y = 0;
	while (y < t_game->t_map.heightnb)
	{
		x = 0;
		while (x < t_game->t_map.widthnb)
		{
			if (t_game->t_map.mappe[y][x] == 'P')
			{
				t_game->xpl = x;
				t_game->ypl = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	main(int ac, char **av)
{
	t_game		t_game;

	t_game.idbck = 1;
	t_game.nb_mov = 0;
	t_game.error = 0;
	t_game.coll = 0;
	t_game.ant = 0;
	t_game.answ = 0;
	t_game.idcol = 0;
	t_game.mlx = NULL;
	t_game.idbck = 0;
	t_game.t_map.mappe = NULL;
	if (ac == 1)
		initialization(&t_game, MAP);
	else if (ac == 2 && (valid_extension(av[1]) == 0))
		initialization(&t_game, av[1]);
	else
		initialize_error(&t_game, ERRORMAP,
			"Mauvais type de fichier ou trop d'arguments¡");
	mlx_key_hook(t_game.mlx, movementhandler, &t_game);
	mlx_loop_hook(t_game.mlx, back_anima, &t_game);
	mlx_loop(t_game.mlx);
	free_map(t_game.t_map.mappe);
	mlx_terminate(t_game.mlx);
	return (EXIT_SUCCESS);
}
