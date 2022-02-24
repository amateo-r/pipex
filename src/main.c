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
		while (matrix[++i])
			free(matrix[i]);
		free(matrix);
	}
	return ;
}

char	**build_command(char *file, char *command)
{
	int		len;
	char	**args;

	len = ft_count(command, ' ');
	args = ft_splitn(command, ' ', 1);
	args[len + 1] = NULL;
	args[len] = (char *) malloc(sizeof(*file) + (ft_strlen(file) + 1));
	ft_strlcpy(args[len], file, ft_strlen(file) + 1);
	return (args);
}

char	*build_path(char	*argv)
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
 * ARGUMENTS:
 * @param	int		n		fdp modifier.
 * @param	int		fdp[2]	File Descriptor Procs
 * @param	char	**args	Command builded.
 */
void	make_proces(const int n, int fdp[2], char **args)
{
	char	*path;

	path = build_path(args[0]);
	dup2(fdp[1 - n], STDOUT_FILENO);
	// close(fdp[0 + n]);
	close(fdp[1 - n]);
	execve(path, args, environ);
	perror("execve failed");
	exit(0);
}

/**
 * ARGUMENTS:
 * @param	int		argc	Number of input parameters. It must be 5
 * @param	char	**argv	Input arguments. It must be: path, file, command, command and file.
 *
 * VARIABLES:
 * @param	int		i		Counter.
 * @param	int		fdp[2]	(F)ile (D)escriptor (P)roces.
 * @param	pid_t	pid		Identifier of thread.
 * @param	char	*str	String where is stored result of the first child.
 * @param	char	*str	String where is stored result of the second child.
 * @param	args	**args	Path and its command builded.
 */
int	main(int argc, char **argv)
{
	int		i;
	int		fdo;
	int		fdp[2];
	pid_t	pid;
	char	*str;
	char	**args;

	if (exc_manager(argc, argv) == 0)
	{
		str = (char *) malloc((sizeof(char) * 4096 + 1));
		args = build_command(argv[1], argv[2]);
		if (pipe(fdp) == -1)
			perror("Cosa mala esta");
		pid = fork();
		if (pid == 0)
			make_proces(0, fdp, args);
		close(fdp[0]);
		close(fdp[1]);
		waitpid(pid, 0, WNOHANG);

		i = read(fdp[0], str, 4096);
		fdo = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY);
		write(fdo, str, i);
		free_my_chars(args);
		free(str);

		args = build_command(argv[4], argv[3]);
		pid = fork();
		if (pid == 0)
			make_proces(1, fdp, args);
		close(fdp[0]);
		close(fdp[1]);
		waitpid(pid, 0, WNOHANG);
		str = NULL;
		str = (char *) malloc((sizeof(char) * 4096 + 1));

		i = read(fdp[0], str, 4096);
		write(fdo, str, i);
		close(fdo);

		close(fdp[0]);
		close(fdp[1]);
		free_my_chars(args);
		free(str);
	}
	// system("leaks pipex.a");
	return (0);
}
