/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:00:41 by rapelcha          #+#    #+#             */
/*   Updated: 2023/01/21 20:38:53 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;

	if (!s1)
		return (NULL);
	str = (char *)ft_calloc((ft_strlen(s1) + 1), sizeof(char));
	if (!str)
		return (0);
	ft_memcpy(str, s1, ft_strlen(s1));
	return (str);
}
