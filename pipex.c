/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:45:45 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/06/06 11:35:55 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_start(int *fd, char **av, char **envp)
{
	int		fd_in;
	char	**av_split;
	char	*path;

	close(fd[FD_READ_END]);
	fd_in = open(av[1], O_RDONLY);
	check_fd(fd_in, av[1]);
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
	dup2(fd[FD_WRITE_END], STDOUT_FILENO);
	close(fd[FD_WRITE_END]);
	av_split = ft_av_split(av[2]);
	ft_get_path(av_split[0], envp, &path);
}

int	main(int ac, char **av, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (ac == 5)
	{
		pipe(fd);
		pid = fork();
		if (pid == -1)
			perror("ERROR");
		if (pid == 0)
			child_start(fd, av, envp);
	}
}
