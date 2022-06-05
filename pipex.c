/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:45:45 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/06/05 13:31:03 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_start(int *fd, char **av, char **envp)
{
	int	fd_in;

	close(fd[0]);
	fd_in = open(av[1], O_RDONLY);
	check_fd(fd_in, av[1]);
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
