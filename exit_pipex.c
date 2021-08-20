/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htizi <htizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 01:12:49 by htizi             #+#    #+#             */
/*   Updated: 2021/08/20 14:31:18 by htizi            ###   ########.fr       */
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
	free(var->cmd);
	free(var->cmd_path);
	free_tab(var->paths_tab);
	free(var->str[1]);
	if (code == 1)
		exit (127);
	exit (var->ext);
}
