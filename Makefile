NAME	=	cub3d
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g3 #-fsanitize=address
RM		=	rm -rf
SRC		=	srcs/main.c \
			srcs/exit.c \
			srcs/load_sprites.c \
			srcs/main.c \
			srcs/player_moves.c \
			srcs/utils/utils_1.c \
			srcs/utils/utils_2.c \
			srcs/window_handling.c \
			srcs/get_map.c \
			srcs/check_map.c \
			srcs/get_next_line.c \


OBJDIR = objs
SRCDIR = srcs

OBJ = $(addprefix ${OBJDIR}/, ${SRC:.c=.o})

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


all: TITLE launch $(NAME)
	@printf "\n$(B)$(CCYAN)$(NAME) compiled$(D)\n\n"

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
			@printf "${B}${CWHITE}]\n"

${OBJDIR}/%.o:${SRCDIR}/%.c
	@mkdir -p ${@D}
	@$(CC) $(CFLAGS) -c $< -o $@
	printf "█"

launch:
	$(call progress_bar)

clean:
	$(RM) $(OBJDIR)
	@echo "$(B)Cleared$(D)"

fclean:			clean
	$(RM) $(NAME) ${RM} objects

re:				fclean all

.PHONY:			all clean fclean re launch