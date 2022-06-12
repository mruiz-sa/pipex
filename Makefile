# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 19:11:27 by mruiz-sa          #+#    #+#              #
#    Updated: 2022/06/12 12:25:14 by mruiz-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = ./srcs/ft_putendl_fd.c \
			./srcs/ft_putstr_fd.c \
			./srcs/ft_split.c \
			./srcs/ft_strchr.c \
			./srcs/ft_strjoin.c \
			./srcs/ft_strlen.c \
			./srcs/ft_strncmp.c \
			./srcs/ft_substr.c \
			./srcs/path.c \
			./srcs/utils.c \
			./pipex.c

OBJECTS = $(SRC:.c=.o)

FLAGS = gcc -Wall -Werror -Wextra

$(NAME): $(OBJECTS)
		@clear
		@echo "\n\033[92m"---------\\nCOMPILED\\n---------\\n"\033[0m\n"
		@ar -rc $(NAME) $(OBJECTS)
		@ranlib $(NAME)
		@$(FLAGS) $(SRC) -o pipex

all: $(NAME)

clean: 
		@clear
		@echo "\n\033[31m"-------------\\nDELETED FILES\\n-------------\\n"\033[0m\n"
		@rm -f $(OBJECTS)

fclean: clean
		@rm -rf $(NAME)
		@rm -rf pipex

re: fclean all

.PHONY: all clean re