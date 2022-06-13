/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:30:27 by amateo-r          #+#    #+#             */
/*   Updated: 2022/06/13 10:30:29 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libpipex.h"

/**
 * Input error handler.
 * ARGUMENTS:
 * @param	int		argc	'argv' len.
 * @param	char	**argv	Consol inputs.
 * @param	char	**env	Environ.
 */
int	exception_manager(int argc, char **argv, char **env)
{
	if (argc != 5)
	{
		write(1, "Error: incorrect number of arguments\n", 37);
		return (0);
	}
	else if (access(argv[1], F_OK | R_OK) != 0)
	{
		write(1, "Error: input file\n", 19);
		return (0);
	}
	else if (access(argv[3], F_OK) == 0)
	{
		if (access(argv[3], W_OK) != 0)
		{
			write(1, "Error: output file\n", 20);
			return (0);
		}
	}
	else if (!env)
	{
		write (1, "Error: environ problem\n", 23);
		return (0);
	}
	return (1);
}
