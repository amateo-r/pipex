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

void	free_my_chars(char **matrix)
{
	int	i;

	if (matrix)
	{
		i = -1;
		while(matrix[++i])
			free(matrix[i]);
		free(matrix);
	}
	return ;
}

char**	build_command(char *file, char *command)
{
	int		len;
	char	**args;

	len = ft_count(command, ' ');
	args = ft_splitn(command, ' ', 1);
	ft_strlcpy(args[len], file, ft_strlen(file) + 1);
	args[len + 1] = NULL;
	return (args);
}

char*	build_path(char	*argv)
{
	int		i;
	int		flag;
	char	**env;
	char	**mat_path;
	char	*path;

	env = environ;
	while (ft_strncmp("PATH=\0", *env, 5) != 0)
		env++;
	mat_path = ft_split(*env + 5, ':');
	i = -1;
	flag = 0;
	while (mat_path[++i] && flag == 0)
	{
		path = (char *)malloc (sizeof(char) * (ft_strlen(mat_path[i]) + ft_strlen(argv) + 2));
		ft_strlcpy(path, mat_path[i], ft_strlen(mat_path[i]) + 1);
		ft_strlcat(path, "/", ft_strlen(path) + 2);
		ft_strlcat(path, argv, ft_strlen(path) + ft_strlen(argv) + 1);
		if (access(path, F_OK) == 0)
			flag = 1;
		else
			free(path);
	}
	free_my_chars(mat_path);
	return (path);
}

/**
 *	Aquí es necesario pasar dos argumentos más:
 *	@param	int		pid		Proces id.
 *	@param	int		fdp[2]	File Descriptor Proces
 *	@param	char	*path	Path of command.
 *	@param	char	**args	Command builded.
 */
void	make_proces(int pid, int fdp[2], char *path, char **args)
{
	// char	*args[4];
	char	*env[2] = {"./test_files/infile", NULL};

	if (pid == 0)
	{
		dup2(fdp[1], STDOUT_FILENO);
		close(fdp[0]);
		close(fdp[1]);
		int i = -1;
		while (args[++i])
			if (args[i])
				printf("[%d]: %s\n", i, args[i]);
		execve(path, args, env);
		perror("Salió algo mal");
		exit(1);
	}
	return ;
}
/**
 * NOTAS
 * fdp	Pipe for the parent, (F)ile (D)escriptor (P)arent.
 */
int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	int		fdp[2];
	char	str[4096];
	char	str2[4096];
	char	**args;
	char	*path;

	if (exc_manager(argc, argv) == 0)
	{
		args = build_command(argv[1], argv[2]);
		path = build_path(args[0]);
		pipe(fdp);
		pid = fork();
		make_proces(pid, fdp, path, args);

		if (pid > 0)
		{
			close(fdp[1]);
			read(fdp[0], str, 4096);
			wait(NULL);
			pid = fork();
			// free_my_chars(args);
			// args = build_command(argv[1], argv[3]);
			// path = build_path(args[0]);
			make_proces(pid, fdp, path, args);
			close(fdp[1]);
			read(fdp[0], str2, 4096);
		}
		i = -1;
		while(args[++i])
		 	free(args[i]);
	}
	system("leaks pipex.a");
	exit(1);
	return (0);
}
