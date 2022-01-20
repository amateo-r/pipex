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

void	fork_test(int pid, int fdp[2])
{
	char	*args[3];
	char	*env[2] = {"./test_files/infile", NULL};

	if (pid == 0)	// 1st child
	{

		dup2(fdp[1], STDOUT_FILENO);
		close(fdp[0]);
		close(fdp[1]);

		//args[0] = "/bin/grep";
		args[0] = "./test_files/infile";
		args[1] = "a1";
		args[2] = NULL;
		execve("/bin/grep", args, env);
		exit(1);
	}
	return ;
}
/**
 * NOTAS
 * fdp	Pipe for the parent, (F)ile (D)escriptor (P)arent.
 * fdp	Pipe for the parent, (F)ile (D)escriptor (C)hild.
 */
int	main(void)
{
	// int		pid;
	// int		fdp[2];
	// char	str[4096];
	// // char	str2[4096];

	// pipe(fdp);
	// pid = fork();
	// fork_test(pid, fdp);

	// if (pid > 0)	// Parent
	// {
	// 	close(fdp[1]);
	// 	read(fdp[0], str, 4096);
	// 	printf("Parece que resultó\n");
	// 	printf("Salida del comando 1: %s\n", str);
	// 	wait(NULL);
	// 	// pid = fork();
	// 	// fork_test(pid, fdp);
	// 	// printf("Segunda parte\n");
	// 	// close(fdp[1]);
	// 	// read(fdp[0], str2, 4096);
	// 	// printf("Parece que resultó\n");
	// 	// printf("Salida del comando 2: %s\n", str2);
		
	// }
	char	*args[]  = {"wc", "-l", "./test_files/infile", NULL};
	int i = execve("usr/bin/wc", args, NULL);
	printf ("Algo fue mal, %d", i);
	// exit(1);
	return (0);
}
