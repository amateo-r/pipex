/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 11:15:10 by amateo-r          #+#    #+#             */
/*   Updated: 2021/06/03 11:15:13 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libpipex.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*dst;

	dst = (char *)b;
	while (len > 0)
	{
		dst[len - 1] = c;
		len--;
	}
	return (b);
}
