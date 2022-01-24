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

extern char	**environ;

static int	ft_count(char const *s, char c)
{
	int	i;
	int	count;
	int	flag;

	i = -1;
	count = 0;
	flag = 0;
	while (s[++i] != '\0')
	{
		if (flag == 1 && s[i] == c)
			flag = 0;
		else if (flag == 0 && s[i] != c)
		{
			flag = 1;
			count++;
		}
	}
	return (count);
}

void	build_path()
{
	char	**env;
	char	**path;
	char	str[51] = "Hola:buenas:tardes:amigo:mio:catalan:visca:catalana";

	str[50] = '\0';
	env = environ;
	while (ft_strncmp("PATH=\0", *env, 5) != 0)
		env++;
	// path = ft_split(*env + 5, ':');
	path = ft_split(str, ':');
	printf("Lenght: %d\n", ft_count(str, ':'));
	while (path)
	{
		printf("%s\n", *path);
		printf("Patata\n");
		path++;
		printf("\n");
	}
	return ;
}

void	fork_test(int pid, int fdp[2])
{
	char	*args[4];
	char	*env[2] = {"./test_files/infile", NULL};

	if (pid == 0)	// 1st child
	{

		dup2(fdp[1], STDOUT_FILENO);
		close(fdp[0]);
		close(fdp[1]);

		//args[0] = "/bin/grep";
		args[0] = "grep";
		args[1] = "a1";
		args[2] = "./test_files/infile";
		args[3] = NULL;
		execve("/usr/bin/grep", args, env);
		perror("Salió algo mal");
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
	build_path();
	//system("leaks pipex.a");
	exit(1);
	return (0);
}
