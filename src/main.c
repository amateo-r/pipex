/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:24:04 by amateo-r          #+#    #+#             */
/*   Updated: 2022/06/12 11:29:05 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libpipex.h"

void	free_my_chars(char **matrix);
void	th_st(int fdp[2], char **argv, char **env);
void	th_nd(int fdp[2], char **argv, char **env);
char	*build_path(char *a, char **env);

/**
 * Free the allocated matrix for the double pointer.
 * ARGUMENTS:
 * @param	char	**matrix	Matrix that will free his memory allocation
 */
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

/**
 * This functions find the path of a command.
 * ARGUMENTS:
 * @param	char	*a		Command needed to find his path.
 * PARAMETERS:
 * @param	int		i;		Counter to manage arrays.
 * @param	int		flag	False boolean to finish loop when path is found.
 * @param	char	**env	An array of strings that for contain environ.
 * @param	char	**m		Possible paths that need to be checked if exist or not.
 * @param	char	*p		Return value and final path.
 * @param	char	**env	Environ.
 */
char	*build_path(char *a, char **env)
{
	int		i;
	int		flag;
	char	**m;
	char	*p;

	while (ft_strncmp("PATH=\0", *env, 5) != 0)
		env++;
	m = ft_split(*env + 5, ':');
	i = -1;
	flag = 0;
	while (m[++i] && flag == 0)
	{
		p = (char *)malloc(sizeof(char) * (ft_strlen(m[i]) + ft_strlen(a) + 2));
		ft_strlcpy(p, m[i], ft_strlen(m[i]) + 1);
		ft_strlcat(p, "/", ft_strlen(p) + 2);
		ft_strlcat(p, a, ft_strlen(p) + ft_strlen(a) + 1);
		if (access(p, F_OK) == 0)
			flag = 1;
		else
			free(p);
	}
	free_my_chars(m);
	return (p);
}

/**
* Execute the first child process.
 * ARGUMENTS:
 * @param	int		*fdp	(F)ile (D)escriptor (P)ipex.
 * VARIABLES:
 * @param	int		fd		File descriptor for input or output files.
 * @param	char	*path	Command path.
 * @param	char	**args	Command and his flags.
 * @param	char	**env	Environ.
 */
void	th_st(int fdp[2], char **argv, char **env)
{
	int		fd;
	char	*path;
	char	**args;

	fd = open(argv[1], O_RDONLY | O_NONBLOCK);
	close(fdp[0]);
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(fdp[1], STDOUT_FILENO);
	close(fdp[1]);
	args = ft_split(argv[2], ' ');
	path = build_path(args[0], env);
	execve(path, args, env);
	perror("execve failed");
	exit(0);
}

/**
* Execute the second child process.
 * ARGUMENTS:
 * @param	int		*fdp	(F)ile (D)escriptor (P)ipex.
 * VARIABLES:
 * @param	int		fd		File descriptor for input or output files.
 * @param	char	*path	Command path.
 * @param	char	**args	Command and his flags.
 * @param	char	**env	Environ.
 */
void	th_nd(int fdp[2], char **argv, char **env)
{
	int		fd;
	char	*path;
	char	**args;

	fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	dup2(fdp[0], STDIN_FILENO);
	close(fdp[0]);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	args = ft_split(argv[3], ' ');
	path = build_path(args[0], env);
	execve(path, args, env);
	perror("execve failed");
	exit(0);
}

/**
 * This program emuletes pipe. Needs four input paramteters.
 * Input file: the first command execute based on his content.
 * Command 1
 * Command 2
 * Ouput file: where the final result is stored.
 * PARAMATERS:
 * @param	int	fdp[2]	(F)ile (D)escriptor (P)ipex
 */
int	main(int argc, char **argv, char **env)
{
	int	fdp[2];

	if (exception_manager(argc, argv, env) == 0)
		return (0);
	else
	{
		pipe(fdp);
		if (fork() == 0)
			th_st(fdp, argv, env);
		else
		{
			wait(NULL);
			close(fdp[1]);
			if (fork() == 0)
				th_nd(fdp, argv, env);
			else
				close(fdp[0]);
			wait(NULL);
		}
	}
	return (0);
}
