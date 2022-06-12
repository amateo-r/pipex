/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:08:31 by amateo-r          #+#    #+#             */
/*   Updated: 2021/05/31 13:26:47 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libpipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (!s || ft_strlen(s) == 0)
		return (NULL);
	if (*s == '\0' || start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start + 1 > len + 1)
		dst = ft_calloc(len + 1, sizeof(char));
	else
		dst = ft_calloc(ft_strlen(s) - start + 1, sizeof(char));
	if (!dst)
		return (0);
	while (s[start] && i < len)
	{
		dst[i] = s[start];
		start++;
		i++;
	}
	return (dst);
}
