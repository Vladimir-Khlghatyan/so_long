
SRCS =		${wildcard ./functions/*.c}

OBJS 		= ${SRCS:.c=.o}

CC			= gcc -g
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
MLXFLAGS	= -Imlx -lmlx -framework OpenGL -framework AppKit

%.o: %.c
			@$(CC) ${CFLAGS} -c $< -o $@

ifeq ($(shell uname), Linux)
MLXFLAGS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
%.o: %.c
		@$(CC) ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@
endif

NAME		= so_long

$(NAME):	$(OBJS)
			@$(CC) $(OBJS) $(CFLAGS) $(MLXFLAGS) -o $(NAME)
			@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

all:		${NAME}

clean:
			@${RM} ${OBJS}
			@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:		clean
			@${RM} ${NAME}
			@echo "$(RED)all deleted!$(DEFAULT)"

re:			fclean all

.PHONY:		all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
