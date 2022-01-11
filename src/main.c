/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:24:04 by amateo-r          #+#    #+#             */
/*   Updated: 2022/01/10 10:24:07 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libpipex.h"

void	fork_test(int i)
{
	char	*args[4];

	args[0] = "/bin/ls";
	args[1] = "-ls";
	args[2] = "> ./test_files/outfile";
	args[3] = NULL;
	if ((i = fork()) == 0)
		execve(args[0], args, 0);
	else
		printf("Fork es igual a cero [%d]\n", i);
	return ;
}
/**
 * NOTAS
 * fdp	Pipe for the parent, (F)ile (D)escriptor (P)arent.
 * fdp	Pipe for the parent, (F)ile (D)escriptor (C)hild.
 */
int	main(void)
{
	int		pid;
	int		fdp[2];
	int		fdc[2];
	char	str[4096];

	pipe(fdp);
	pipe(fdc);
	pid = fork();
	if (pid > 0)
	{
		close(fdp[0]);
		wait(NULL);
		read(fdc[0], str, 4096);
		printf("Parece que resultó\n");
		printf("Salida?: %s\n", str);
	}
	else if (pid == 0)
	{
		char	*args[3];

		dup2(fdp[1], STDOUT_FILENO);
		close(fdp[1]);
		close(fdp[0]);

		args[0] = "/bin/ls";
		args[1] = "-ls";
		args[2] = NULL;
		execve(args[0], args, 0);
		exit(1);
	}
	return (0);
}
