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
	if (execve(path, av_split, envp) == -1)
	{
		ft_putendl_fd("command not found: ", 2);
		ft_putendl_fd(av_split[0], 2);
		free_trash(av_split);
		free(path);
		exit(0);
	}
}

void	child_end(int *fd, char **av, char **envp)
{
	int		fd_out;
	char	**av_split;
	char	*path;

	close(fd[FD_WRITE_END]);
	fd_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC | O_APPEND | S_IRWXU);
	dup2(fd[FD_READ_END], STDIN_FILENO);
	close(fd[FD_READ_END]);
	av_split = ft_av_split(av[3]);
	ft_get_path(av_split[0], envp, &path);
	if (execve(path, av_split, envp) == -1)
	{
		ft_putendl_fd("command not found: ", 2);
		ft_putendl_fd(av_split[0], 2);
		free_trash(av_split);
		free(path);
		exit(0);
	}
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
		else
		{
			pid = fork();
			if (pid == -1)
				perror("ERROR");
			if (pid == 0)
				child_end(fd, av, envp);
			else
			{
				close(fd[FD_READ_END]);
				close(fd[FD_WRITE_END]);
			}
		}
		waitpid(pid, NULL, 0);
		return (0);
	}
}
