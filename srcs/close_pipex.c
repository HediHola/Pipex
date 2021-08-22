/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htizi <htizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 23:22:32 by htizi             #+#    #+#             */
/*   Updated: 2021/08/23 00:36:08 by htizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipex(t_tab *var)
{
	close(var->fd[0]);
	exit_pipex(var, 666);
	if (var->cmd_1_is_found == 1)
	{	
		waitpid(var->first_pid, &var->status, 0);
		if (WIFEXITED(var->status))
			var->ext = WEXITSTATUS(var->status);
	}
	if (var->cmd != NULL)
	{
		waitpid(var->last_pid, &var->status, 0);
		if (WIFEXITED(var->status))
			var->ext = WEXITSTATUS(var->status);
	}
	exit_pipex(var, 0);
}
