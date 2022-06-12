/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 12:48:57 by amateo-r          #+#    #+#             */
/*   Updated: 2021/05/24 13:00:09 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libpipex.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*data;

	data = malloc (count * size);
	if (!data)
		return (0);
	ft_bzero(data, count * size);
	return (data);
}
