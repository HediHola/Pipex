/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htizi <htizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:25:18 by htizi             #+#    #+#             */
/*   Updated: 2021/08/23 00:36:32 by htizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	first_fork(char **argv, char **env, t_tab *var)
{
	var->ret = first_var_init(var, env, argv);
	if (var->ret == -1)
		exit_pipex(var, var->ret);
	if (var->cmd != NULL)
	{
		var->first_pid = fork();
		if (var->first_pid == 0)
		{
			dup2(var->file, STDIN_FILENO);
			dup2(var->fd[1], STDOUT_FILENO);
			close(var->fd[0]);
			if (execve(var->str[0], var->str, env) == -1)
				execve_error(var);
		}
	}
	close(var->fd[1]);
	exit_pipex(var, 666);
	if (var->cmd != NULL)
		var->cmd_1_is_found = 1;
	return (0);
}
