/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htizi <htizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:56:43 by htizi             #+#    #+#             */
/*   Updated: 2021/08/20 22:47:22 by htizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_slash(char *cmd)
{
	int	i;

	i = 0;
	if (cmd)
	{
		while (cmd[i])
		{
			if (cmd[i] == '/')
				return (1);
			i++;
		}
	}
	return (0);
}

void	cmd_not_found(char *cmd)
{
	ft_putstr_fd("pipex: command not found: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	execve_error(t_tab *var)
{
	int	fd;

	if (!var->paths_tab)
		perror("pipex");
	else if (!ft_strncmp(var->cmd, "..", ft_strlen(var->cmd)))
		perror("pipex");
	else if (is_slash(var->str[0]))
	{
		fd = open(var->str[0], O_DIRECTORY);
		if (fd != -1)
		{
			close(fd);
			ft_putstr_fd("pipex: ", STDERR_FILENO);
			ft_putstr_fd(var->cmd, STDERR_FILENO);
			ft_putstr_fd(" is a directory\n", STDERR_FILENO);
		}
		else
			perror("pipex");
	}
	else
		cmd_not_found(var->cmd);
	exit_pipex(var, 1);
}
