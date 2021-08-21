/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_var_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htizi <htizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:46:01 by htizi             #+#    #+#             */
/*   Updated: 2021/08/20 21:08:20 by htizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	last_var_init(t_tab *var, char **argv)
{
	var->file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (var->file == -1)
		return (-2);
	var->cmd = get_cmd(argv[3]);
	if (var->cmd == NULL)
		return (-1);
	var->cmd_path = get_cmd_path(var->cmd, var->paths_tab);
	var->str[0] = var->cmd_path;
	if (!var->str[0])
		var->str[0] = var->cmd;
	var->str[1] = get_opt(argv[3]);
	return (0);
}
