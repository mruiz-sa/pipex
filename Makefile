# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 19:11:27 by mruiz-sa          #+#    #+#              #
#    Updated: 2022/05/09 12:43:57 by mruiz-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex.a

FUNCTIONS = ft_putendl_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
			ft_strjoin.c ft_strlen.c ft_strncmp.c path.c pipex.c \
			utils.c

OBJECTS = $(FUNCTIONS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJECTS)
		ar rc $(NAME) $(OBJECTS)

$(OBJECTS): $(FUNCTIONS)
		gcc $(CFLAGS) -c $(FUNCTIONS)

clean:
		@rm -f $(OBJECTS)

fclean: clean
		@rm -f $(OBJECTS) $(NAME)

re: fclean all

.PHONY: all clean fclean re