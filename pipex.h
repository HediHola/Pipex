/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htizi <htizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:37:00 by htizi             #+#    #+#             */
/*   Updated: 2021/08/20 14:28:45 by htizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>

typedef struct s_tab
{
	char	*cmd;
	char	*cmd_path;
	char	**paths_tab;
	char	*str[3];
	int		fd[2];
	int		file;
	int		status;
	int		ext;
}t_tab;
void	exit_pipex(t_tab *var, int code);
void	ft_putstr_fd(char *s, int fd);
int		first_var_init(t_tab *var, char **env, char **argv);
int		last_var_init(t_tab *var, char **argv);
int		first_fork(char **argv, char **env, t_tab *var);
int		last_fork(char **argv, char **env, t_tab *var);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
char	**get_paths_tab(char **env);
char	*get_cmd(char *str);
char	*get_cmd_path(char *cmd, char **paths_tab);
char	*get_opt(char *str);

#endif
