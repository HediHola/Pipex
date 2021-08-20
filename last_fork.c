/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htizi <htizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:11:27 by htizi             #+#    #+#             */
/*   Updated: 2021/08/20 01:42:15 by htizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	last_fork(char **argv, char **env, t_tab *var)
{
	int		file;
	int		status;
	int		ext;
	pid_t	last_pid;

	last_var_init(var, env, argv);
	last_pid = fork();
	if (last_pid == 0)
	{
		dup2(var->fd[0], STDIN_FILENO);
		dup2(var->file, STDOUT_FILENO);
		close(var->fd[1]);
		if (execve(var->cmd_path, var->str, env) == -1)
		{
			perror("pipex");
			exit (127);
		}
	}
	waitpid(last_pid, &status, 0);
	if (WIFEXITED(status))
		ext = WEXITSTATUS(status);
	close(var->fd[0]);
	close(var->file);
	exit_pipex(var, ext);
	return (0);
}
