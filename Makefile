NAME	=	cub3d
CC		=	gcc
PATH_MLX	=	mlx
CFLAGS		=	-Wall -Wextra -Werror $(INC)
FLAGS		=	-ldl -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11
				-Wl,-rpath=./bass/,-rpath=./mlx/,-rpath=./delay/
INC = -I ./include
RM		=	rm -rf
SRCS    =srcs/check_map.c \
                srcs/main.c \
                srcs/get_next_line.c \
                srcs/window.c \
                srcs/player_moves.c \
                srcs/draw_textures.c \
                srcs/draw_textures2.c \
                srcs/utils.c \
                srcs/utils_maths.c \
                srcs/utils_free_exit.c \
                srcs/utils_get_next_line.c \
                srcs/get_map.c

OBJS		=	$(SRCS:.c=.o)

.SILENT:
SHELL	:= bash
CRED 	= \033[0;31m
CGRIS	= \033[0;214m
CWHITE	= \033[0;37m
CYELLOW	= \033[1;33m
CGREEN 	= \033[0;32m
CCYAN 	= \033[1;36m
CBLUE 	= \033[0;34m
CPURPLE	= \033[0;35m
B 	=	$(shell tput bold)
D =		$(shell tput sgr0)

all:		TITLE $(NAME)
			@rm ${OBJS}
			printf "${CYELLOW} \n"
			@echo The fabulouly ugly game Cub3d has been complied!

TITLE:
	printf "${CRED}  _   ${CGRIS} _     ${CYELLOW}_  ${CGREEN}    ${CCYAN}       ${CBLUE} _     ${CPURPLE}     ${CRED}      \n"
	printf "${CRED} | |_ ${CGRIS}| |_  ${CYELLOW}(_)${CGREEN} ___ ${CCYAN} _ __  ${CBLUE}| |_   ${CPURPLE}_ _  ${CRED} __ _ \n"
	printf "${CRED} |  _|${CGRIS}| ' \\ ${CYELLOW}| |${CGREEN}|___|${CCYAN}| '_ \\ ${CBLUE}| ' \\ ${CPURPLE}| ' \\ ${CRED}/ _\` |\n"
	printf "${CRED}  \__|${CGRIS}|_||_|${CYELLOW}|_|${CGREEN}     ${CCYAN}| .__/ ${CBLUE}|_||_|${CPURPLE}|_||_|${CRED}\\__, |\n"
	printf "${CRED}      ${CGRIS}      ${CYELLOW}   ${CGREEN}     ${CCYAN}|_|     ${CBLUE}     ${CPURPLE}      ${CRED}|___/ \n"
	printf "${CYELLOW}"
	@echo Clumsy ${NAME} is on the way!


 # ******************************************************************************* #
define  progress_bar
        @i=0; \
        while [[ $$i -le $(words $(SRCS)) ]]; do \
                printf " "; \
                ((i = i + 1)); \
        done; \
		printf "$(B)$(CWHITE)]\r[$(CGREEN)";
endef
 # ******************************************************************************* #

.c.o:
			$(CC) $(CFLAGS) -Imlx -Ibass  -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			@make -C mlx
			$(CC) ${CFLAGS} -o $(NAME) ${OBJS} ${FLAGS}

launch:
	$(call progress_bar)

clean:
	$(RM) $(OBJDIR)
	@echo "[ ✅ ] $(B)Cleared$(D)"

fclean:			clean
	$(RM) $(NAME) ${RM} objects

re:				fclean all

.PHONY:			all clean fclean re launch