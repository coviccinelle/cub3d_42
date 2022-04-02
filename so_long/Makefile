# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/25 12:26:42 by thi-phng          #+#    #+#              #
#    Updated: 2021/10/12 11:53:00 by thi-phng         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
RM			=	rm -rf
PATH_MLX	=	mlx
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	so_long
FLAGS		=	-ldl -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11
				-Wl,-rpath=./bass/,-rpath=./mlx/,-rpath=./delay/

SRCS		=	so_long.c \
				init_game.c \
				read_map.c \
				check_map.c \
				display_game.c \
				exit_error.c \
				keys_event_utils.c \
				get_next_line.c \
				get_next_line_utils.c \
				ft_strchr_vs_find_me.c \

OBJS		=	$(SRCS:.c=.o)

.SILENT:
CRED 	= \033[0;31m
CORANGE	= \033[0;33m
CYELLOW	= \033[1;33m
CGREEN 	= \033[0;32m
CCYAN 	= \033[1;36m
CBLUE 	= \033[0;34m
CPURPLE	= \033[0;35m

all:			TITLE $(NAME)
				@rm ${OBJS}
				printf "${CYELLOW} \n"
				@echo The fabulouly ugly game So_long has been complied!

TITLE:
	printf "${CRED}  _   ${CORANGE} _     ${CYELLOW}_  ${CGREEN}    ${CCYAN}       ${CBLUE} _     ${CPURPLE}     ${CRED}      \n"
	printf "${CRED} | |_ ${CORANGE}| |_  ${CYELLOW}(_)${CGREEN} ___ ${CCYAN} _ __  ${CBLUE}| |_   ${CPURPLE}_ _  ${CRED} __ _ \n"
	printf "${CRED} |  _|${CORANGE}| ' \\ ${CYELLOW}| |${CGREEN}|___|${CCYAN}| '_ \\ ${CBLUE}| ' \\ ${CPURPLE}| ' \\ ${CRED}/ _\` |\n"
	printf "${CRED}  \__|${CORANGE}|_||_|${CYELLOW}|_|${CGREEN}     ${CCYAN}| .__/ ${CBLUE}|_||_|${CPURPLE}|_||_|${CRED}\\__, |\n"
	printf "${CRED}      ${CORANGE}      ${CYELLOW}   ${CGREEN}     ${CCYAN}|_|     ${CBLUE}     ${CPURPLE}      ${CRED}|___/ \n"
	printf "${CYELLOW} \n"

.c.o:
			$(CC) $(CFLAGS) -Imlx -Ibass  -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			@make -C mlx
			$(CC) ${CFLAGS} -o $(NAME) ${OBJS} ${FLAGS}

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME) *.o

re:			fclean all

.PHONY:		all clean fclean re

