/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:51:47 by mruiz-sa          #+#    #+#             */
/*   Updated: 2022/06/12 11:21:14 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>

# define FD_READ_END	0
# define FD_WRITE_END	1

void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	check_fd(int fd, char *file_name);
void	ft_get_path(char *command, char *envp[], char **f_path);
void	check_ac(int ac);
void	free_trash(char **trash);
char	**ft_av_split(char *av);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
