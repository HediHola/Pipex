/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htizi <htizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 18:30:20 by htizi             #+#    #+#             */
/*   Updated: 2021/08/19 02:22:08 by htizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	char	**path;
	char	*cmd;
	char	*cmd_path;
	char	*str[3];
	int		file;
	int		fd[2];
	int		i;
	pid_t	pid;

	i = 0;
	path = get_path(env);
	file = open(argv[1], O_RDONLY);
	cmd = get_cmd(argv[2]);
	cmd_path = get_cmd_path(cmd, path);
	str[0] = cmd_path;
	if (!str[0])
		str[0] = cmd;
	str[1] = get_opt(argv[2]);
	str[2] = NULL;
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		dup2(file, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		if (execve(cmd_path, str, env) == -1)
		{
			perror("pipex");
			exit (1);
		}
	}
	close(file);
	file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	cmd = get_cmd(argv[3]);
	cmd_path = get_cmd_path(cmd, path);
	str[0] = cmd;
	if (!str[0])
		str[0] = cmd;
	str[1] = get_opt(argv[3]);
	dup2(fd[0], STDIN_FILENO);
	dup2(file, STDOUT_FILENO);
	close(fd[1]);
	if (execve(cmd_path, str, env) == -1)
	{
		perror("pipex");
		exit (1);
	}
	//wait(pid);
	return (0);
}
