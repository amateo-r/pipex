/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:02:28 by amateo-r          #+#    #+#             */
/*   Updated: 2021/05/24 11:02:44 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libpipex.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;

	dst = (char *)malloc (sizeof(char) * ft_strlen(s1) + 1);
	if (!dst)
		return (NULL);
	ft_strcpy(dst, s1);
	return (dst);
}
