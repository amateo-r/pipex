/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:05:25 by amateo-r          #+#    #+#             */
/*   Updated: 2022/01/25 15:05:28 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libpipex.h"

/**
 * Handle error and control input. Return 0 if successful, -1 in other case.
 */
int	exc_manager(int argc, char **argv)
{
	//	Controla que la entrada de argumentos sean cuatro.
	if (argc != 5)
		return (-1);
	else if (access(argv[1], F_OK) != 0)
		return (-1);
	return (0);
}
