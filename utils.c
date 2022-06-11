/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 13:31:18 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/06/06 11:10:07 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_fd(int fd, char *file_name)
{
	if (fd == -1)
	{
		ft_putstr_fd("No such file or directory: ", 2);
		ft_putendl_fd(file_name, 2);
		exit(0);
	}
}

void	free_trash(char **trash)
{
	int	i;

	i = 0;
	while (trash[i])
	{
		free(trash[i]);
		i++;
	}
	free(trash);
}

char	**ft_av_split(char *av)
{
	char	**av_split;

	av_split = ft_split(av, ' ');
	return (av_split);
}
