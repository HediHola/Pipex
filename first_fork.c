/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htizi <htizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:25:18 by htizi             #+#    #+#             */
/*   Updated: 2021/08/20 01:10:37 by htizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	first_fork(char **argv, char **env, t_tab *var)
{
	int		file;
	int		status;
	int		ext;
	pid_t	first_pid;

	first_var_init(var, env, argv);
	first_pid = fork();
	if (first_pid == 0)
	{
		dup2(var->file, STDIN_FILENO);
		dup2(var->fd[1], STDOUT_FILENO);
		close(var->fd[0]);
		if (execve(var->cmd_path, var->str, env) == -1)
		{
			perror("pipex");
			exit (127);
		}
	}
	waitpid(first_pid, &status, 0);
	if (WIFEXITED(status))
		ext = WEXITSTATUS(status);
	close(var->fd[1]);
	close(var->file);
	return (0);
}
