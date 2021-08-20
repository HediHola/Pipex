/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htizi <htizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:51:19 by htizi             #+#    #+#             */
/*   Updated: 2021/08/20 14:13:56 by htizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i] && i < n)
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_opt(char *str)
{
	int		i;
	char	*opt;

	i = 0;
	opt = NULL;
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i])
		opt = ft_strndup(&str[i], ft_strlen(&str[i]));
	return (opt);
}

char	*get_cmd(char *str)
{
	int		i;
	char	*cmd;

	cmd = NULL;
	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	if (i > 0)
		cmd = ft_strndup(str, i);
	return (cmd);
}

char	*get_cmd_path(char *cmd, char **path)
{
	int		cmd_len;
	int		path_len;
	int		i;
	char	*cmd_path;

	cmd_len = ft_strlen(cmd);
	i = 0;
	while (path[i])
	{
		path_len = ft_strlen(path[i]);
		cmd_path = malloc(sizeof(char) * (cmd_len + path_len + 2));
		if (!cmd_path)
			return (NULL);
		ft_strcpy(cmd_path, path[i]);
		cmd_path[path_len] = '/';
		ft_strcat(cmd_path, cmd);
		if (!access(cmd_path, F_OK))
			return (cmd_path);
		free (cmd_path);
		i++;
	}
	return (NULL);
}
