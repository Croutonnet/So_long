/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:56:14 by rapelcha          #+#    #+#             */
/*   Updated: 2023/04/17 14:13:13 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define MAP "map/norm.ber"
# define BIG "BIG MAP"
# define ERRORMAP "Map Invalid¡"
# define FINISHGAME "Game finished¡"
# define BACK1 "asset/xpm/BCK0.xpm42"
# define BACK2 "asset/xpm/BCK1.xpm42"
# define BACK3 "asset/xpm/BCK2.xpm42"
# define BACK4 "asset/xpm/BCK3.xpm42"	
# ifndef BONUS
#  define BONUS 0
# endif
# include "src/MLX42/include/MLX42/MLX42.h"
# include "src/libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_map
{
	int		width;
	int		height;
	int		widthnb;
	int		heightnb;
	int		fd;
	char	**mappe;
}			t_map;

typedef struct s_img
{
	mlx_image_t	*pl;
	mlx_image_t	*background[4];
	mlx_image_t	*wall;
	mlx_image_t	*collectible[8];
	mlx_image_t	*ex[2];
	mlx_image_t	*move;
	mlx_image_t	*en;
	mlx_image_t	*pl_1;
}			t_img;

typedef struct s_game
{
	mlx_t	*mlx;
	t_map	t_map;
	t_img	nowimg;
	t_img	oldimg;
	int		xpl;
	int		ypl;
	int		coll;
	int		nbe;
	int		xen;
	int		yen;
	int		nbcr;
	int		idcol;
	int		nb_mov;
	int		error;
	int		idan;
	int		answ;
	int		ant;
	int		idbck;
}			t_game;

mlx_image_t	*load_image(mlx_t *mlx, char *path);
int			valid_extension(char *mappath);
int			verif_map(t_game *t_game);
int			if_bad(char c);
void		player_animation(t_game *t_game);
void		initialize_error(t_game *t_game, char *error_type, char *location);
void		finish_game(t_game *t_game, char *message);
void		put_collectible(t_game *t_game, int x, int y);
void		move_string(t_game *t_game);
void		put_player(t_game *t_game, int x, int y);
void		put_wall(t_game *t_game, int x, int y);
void		put_enemie(t_game *t_game, int x, int y);
void		put_background(t_game *t_game, int x, int y);
void		put_exit(t_game *t_game, int x, int y);
void		sizemap(char *new, t_game *t_game);
void		spawn_map(t_game *t_game, t_map *t_map);
void		wich_move(t_game *t_game, t_map *t_map, int x, int y);
void		player_pos(t_game *t_game);
void		map(t_game *t_game);
void		free_map(char **map);
void		back_anima(void *param);
void		explore_map(int x, int y, t_game *t_game, char **map);
void		delete_map(t_game *t_game, t_img *t_img);
void		initialize_image(t_game *t_game);
void		valid_map(char *map, t_game *t_game);
void		move_player(t_game *t_game, int newx, int newy);
void		replace_map(t_game *t_game);
void		valid_frame(t_game *t_game, t_map *t_map);
void		search_enemie(t_game *t_game);
void		move_enemie(t_game *t_game, int newx, int newy);

#endif