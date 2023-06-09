/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:45:15 by rapelcha          #+#    #+#             */
/*   Updated: 2022/12/14 17:35:13 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, uint32_t c, size_t n)
{
	char	*pstr;

	pstr = str;
	if (!str)
		return (NULL);
	while (n-- > 0)
		*pstr++ = c;
	return (str);
}
