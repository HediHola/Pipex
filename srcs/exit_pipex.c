/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htizi <htizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 01:12:49 by htizi             #+#    #+#             */
/*   Updated: 2021/08/20 23:05:04 by htizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tab(char **paths_tab)
{
	int	i;

	i = 0;
	if (!paths_tab)
		return ;
	while (paths_tab[i])
	{
		free(paths_tab[i]);
		i++;
	}
	free(paths_tab);
}

void	exit_pipex(t_tab *var, int code)
{
	if (code == -1 || code == -2)
		perror("pipex");
	if (code == 666 || code == 667 || code == 1)
	{
		free(var->cmd);
		free(var->cmd_path);
		free(var->str[1]);
		if (code != 1)
			close(var->file);
	}
	if (code == 1 || code == 0 || code == 667 || code == -2)
		free_tab(var->paths_tab);
	if (code == 667 || code == -2)
		exit (1);
	if (code == 1 && (errno == 2 || errno == 13))
		exit (127);
	if (code == 1)
		exit (1);
	if (code == 0)
		exit (var->ext);
}
