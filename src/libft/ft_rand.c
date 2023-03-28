/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:20:50 by rapelcha          #+#    #+#             */
/*   Updated: 2023/02/16 12:24:04 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_rand(int lower, int upper)
{
	int	swap;
	int	numb;

	if (lower > upper)
	{
		swap = lower;
		lower = upper;
		upper = swap;
	}
	numb = (rand() % (upper - lower + 1)) + lower;
	return (numb);
}
