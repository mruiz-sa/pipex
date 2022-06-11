/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:16:23 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/06/06 13:38:18 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	path_line(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (envp[i]);
		i++;
	}
	return (NULL);
}

void	ft_get_path(char *command, char *envp[], char **f_path)
{
	char	**path_list;
	char	*path_slash;
	char	*path_arg;
	int		i;
	int		fd;

	i = 0;
	path_list = ft_split(ft_strchr(path_line(envp), '/'), ':');
	while (path_list[i])
	{
		path_slash = ft_strjoin(path_list[i], '/');
		path_arg = ft_strjoin(path_slash, command);
		free(path_slash);
		fd = open(path_arg, O_RDONLY);
		if (fd >= 0)
		{
			*f_path = path_arg;
			free_trash(path_list);
			close(fd);
			return ;
		}
		free(path_arg);
		i++;
	}
	free_trash(path_list);
}
