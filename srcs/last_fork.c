/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htizi <htizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:11:27 by htizi             #+#    #+#             */
/*   Updated: 2021/08/20 23:32:04 by htizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	last_fork(char **argv, char **env, t_tab *var)
{
	var->ret = last_var_init(var, argv);
	if (var->ret == -2)
		exit_pipex(var, var->ret);
	if (var->ret == -1)
		exit_pipex(var, 667);
	if (var->cmd != NULL)
	{
		var->last_pid = fork();
		if (var->last_pid == 0)
		{
			dup2(var->fd[0], STDIN_FILENO);
			dup2(var->file, STDOUT_FILENO);
			close(var->fd[1]);
			if (execve(var->str[0], var->str, env) == -1)
				execve_error(var);
		}
	}
	close_pipex(var);
	return (0);
}
