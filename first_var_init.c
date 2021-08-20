/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_var_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htizi <htizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:39:28 by htizi             #+#    #+#             */
/*   Updated: 2021/08/20 02:07:09 by htizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	first_var_init(t_tab *var, char **env, char **argv)
{	
	var->path = get_path(env);
	var->cmd = get_cmd(argv[2]);
	var->cmd_path = get_cmd_path(var->cmd, var->path);
	var->str[0] = var->cmd_path;
	if (!var->str[0])
		var->str[0] = var->cmd;
	var->str[1] = get_opt(argv[2]);
	var->str[2] = NULL;
	pipe(var->fd);
	var->file = open(argv[1], O_RDONLY);
	return (0);
}
