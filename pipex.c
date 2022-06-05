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

	close(fd[FD_READ_END]);											/*cerramos el fd de lectura ya que no hay que dejar fds abiertos */
	fd_in = open(av[1], O_RDONLY);									/*creamos un entero y le indicamos que será la apertura del primer archivo solo lectura */
	check_fd(fd_in, av[1]);											/*pasamos la funcion check_fd por si hubiera algun tipo de error con el propio archivo */
	dup2(fd_in, STDIN_FILENO);										/*duplicamos el contenido del archivo fd_in al stdinput */
	close(fd_in);													/*cerramos el archivo que habiamos abierto porque al duplicarlo ya no nos hace falta */
	dup2(fd[FD_WRITE_END], STDOUT_FILENO);							/* */
	close(fd[FD_WRITE_END]);
}

int	main(int ac, char **av, char **envp)
{
	pid_t	pid;
	int		fd[2];													/*Creamos 2 fd, el primero es el archivo de lectura y el segundo el de esritura */

	if (ac == 5)
	{
		pipe(fd);													/*usamos funcion pipe para comunicar los 2 fd */
		pid = fork();												/*dividimos el priceso en 2 (padre/hijo) */
		if (pid == -1)
			perror("ERROR");
		if (pid == 0)
			child_start(fd, av, envp);								/*con el proceso hijo ejecutaremos la funcion child_start */
	}
}
