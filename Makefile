# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htizi <htizi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/20 19:10:02 by htizi             #+#    #+#              #
#    Updated: 2021/08/21 15:21:22 by htizi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	pipex
SRCS_DIR			=	./srcs/
INC_DIR				=	./inc/
SRCS				=	close_pipex.c		\
						get_path.c			\
						get_cmd.c			\
						execve_error.c		\
						utils.c				\
						first_fork.c		\
						first_var_init.c	\
						last_fork.c			\
						last_var_init.c		\
						exit_pipex.c		\
						main.c
SRCS_BASENAME		=	$(addprefix $(SRCS_DIR), $(SRCS))
OBJS				=	$(SRCS_BASENAME:.c=.o)
MAIN_O				=	$(MAIN:.c=.o)
CC					=	clang
FLAGS				=	-Wall -Wextra -Werror -I $(INC_DIR)


.c.o			:
				$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all				:	$(NAME)

$(NAME)			:	$(OBJS) $(MAIN_O)
				$(CC) $(FLAGS) $(OBJS) -o $(NAME)
				@echo [$(NAME)] : Created !

clean			:
				rm -f $(OBJS) 
				@echo [.o] : Deleted !

fclean			:	clean
				rm -f $(NAME)
				@echo [$(NAME)] : Deleted !

re				:	fclean all

.PHONY: 		clean fclean all re
