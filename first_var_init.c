/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_var_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htizi <htizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:39:28 by htizi             #+#    #+#             */
/*   Updated: 2021/08/20 21:42:45 by htizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	first_var_init(t_tab *var, char **env, char **argv)
{	
	var->paths_tab = get_paths_tab(env);
	pipe(var->fd);
	var->file = open(argv[1], O_RDONLY);
	if (var->file == -1)
		return (-1);
	var->cmd = get_cmd(argv[2]);
	if (var->cmd == NULL)
		return (-1);
	var->cmd_path = get_cmd_path(var->cmd, var->paths_tab);
	var->str[0] = var->cmd_path;
	if (!var->str[0])
		var->str[0] = var->cmd;
	var->str[1] = get_opt(argv[2]);
	var->str[2] = NULL;
	return (0);
}
