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

void	get_path(char *command, char *envp[], char **f_path)
{
	char	**paths;
	char	*path;
	char	*path_arg;
	int		i;
	int		fd;

	i = 0;
	paths = ft_split(ft_strchr(path_line(envp), '/'), ':');
	while (paths[i])
	{
		path = ft_strjoin(paths[i], '/');
		path_arg = ft_strjoin(path, command);
		free(path);
		fd = open(path_arg, O_RDONLY);
		if (fd >= 0)
		{
			
		}
		free(path_arg);
		i++;
	}
}

char	**ft_av_split(char *av)
{
	char	**av_split;

	av_split = ft_split(av, ' ');
	return (av_split);
}
