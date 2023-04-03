/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:06:14 by rapelcha          #+#    #+#             */
/*   Updated: 2023/04/03 14:25:26 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sizemap(char *new, t_game *t_game)
{
	int	i;

	i = 0;
	t_game->t_map.heightnb = 0;
	t_game->t_map.widthnb = 0;
	while (new[i])
	{
		if (new[i] == '\n' || new[i] == '\0')
			t_game->t_map.heightnb++;
		i++;
	}
	t_game->t_map.heightnb++;
	i = 0;
	while (new[i])
	{
		if (new[i] == '\n')
			break ;
		i++;
		t_game->t_map.widthnb++;
	}
	if (t_game->t_map.heightnb > 18 || t_game->t_map.widthnb > 34)
	{
		free(new);
		initialize_error(t_game, BIG, "Maximum size: (34X18)¡");
	}
}

void	generate_map(t_game *t_game, t_map *t_map)
{
	int		x;
	int		y;

	y = 0;
	while (y < t_map->heightnb)
	{
		x = 0;
		while (x < t_map->widthnb)
		{
			which_move(t_game, t_map, x, y);
			x++;
		}
		y++;
	}
	move_string(t_game);
}

void	map(t_game *t_game)
{
	char	*temp;
	char	*new;

	temp = "Pikaboo";
	new = NULL;
	while (temp)
	{
		temp = get_next_line(t_game->t_map.fd);
		new = ft_fstrjoin(new, temp);
		ft_xfree(temp);
	}
	close(t_game->t_map.fd);
	sizemap(new, t_game);
	valid_map(new, t_game);
	t_game->t_map.mappe = ft_split(new, '\n');
	new = ft_xfree(new);
	valid_frame(t_game, &t_game->t_map);
}

void	replace_map(t_game *t_game)
{
	int	i;

	i = 0;
	delete_map(t_game, &t_game->oldimg);
	t_game->oldimg = t_game->nowimg;
	initialize_image(t_game);
	generate_map(t_game, &t_game->t_map);
}
